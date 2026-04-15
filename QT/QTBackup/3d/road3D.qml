/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick
import QtQuick.Controls
import QtQuick3D
import "Car"
import "TablaMadera"
// import QtQuick.Studio.DesignEffects
import "Piso"
import "Laberinto8x6"

Rectangle {
    id: maze3D
    objectName: "maze3D"

    anchors.fill: parent
    // width: Constants.width
    // height: Constants.height
    color: "#22262a"

    border.color: "#212528"

    signal animationFinished()

    signal reqSetStart()
    signal reqSetTarget()
    signal reqFindBlackCells()
    signal reqStartExploration()
    signal reqStopRobot()

    signal reqResetMaze()
    // signal reqToggleFullScreen()

    property int activeCameraIndex: 0 // 0: Orbit, 1: Follow, 2: POV

    property int robotLogX: 0
    property int robotLogY: 0
    property int robotDir: 0 // 0: N, 1: E, 2: S, 3: W
    property int robotTargetX: 0
    property int robotTargetY: 0
    property int maxMazeCost: 1

    property int targetX: -1
    property int targetY: -1

    property int robotAction: 0      // 0: IDLE, 1: FOLLOW_WALL, etc.
    property int runTimeSeconds: 0

    ListModel { id: blackCellsModel }

    function clearMazeData() {
        mazeWallsModel.clear();
        cellWeightsModel.clear();
        pathTraceModel.clear();
        blackCellsModel.clear();

        // Escondemos la meta visualmente
        maze3D.robotTargetX = -1;
        maze3D.robotTargetY = -1;
    }

    function addBlackCell(x, y) {
        var uniqueId = "blk_" + x + "_" + y;
        // Evitamos pintar dos veces la misma celda
        for (var i = 0; i < blackCellsModel.count; i++) {
            if (blackCellsModel.get(i).uid === uniqueId) return;
        }
        blackCellsModel.append({ "uid": uniqueId, "px": x, "py": y });
    }

    function formatTime(totalSeconds) {
        var m = Math.floor(totalSeconds / 60);
        var s = totalSeconds % 60;
        return (m < 10 ? "0" : "") + m + ":" + (s < 10 ? "0" : "") + s;
    }

    Shortcut {
        sequence: "C" // Funciona tanto con 'c' minúscula como 'C' mayúscula
        onActivated: {
            // Replicamos exactamente la misma lógica que teníamos en el ratón
            if (cameraTransitionAnim.running) return;

            var next = (maze3D.activeCameraIndex + 1) % 3;
            cameraTransitionAnim.nextCamera = [globalCamera, followCamera, povCamera][next];
            cameraTransitionAnim.nextIndex = next;

            cameraTransitionAnim.start();
        }
    }

    // Shortcut {
    //     sequence: "F"
    //     onActivated: {
    //         maze3D.reqToggleFullScreen();
    //     }
    // }

    // --- ATAJO DE TECLADO: RESTABLECER CÁMARAS ('R') ---
    Shortcut {
        sequence: "R" // Funciona con 'r' o 'R'
        onActivated: {
            // 1. Restablecemos la cámara global (Paneo, Rotación y Zoom)
            cameraOrbitPivot.position = Qt.vector3d(0, 0, 0);
            cameraOrbitPivot.eulerRotation = Qt.vector3d(-50, 0, 0);
            globalCamera.position = Qt.vector3d(0, -20, 180)
            globalCamera.fieldOfView = 50;

            // 2. Restablecemos la cámara de persecución
            followCameraPivot.eulerRotation = Qt.vector3d(-35, 90, 0);
            followCamera.position = Qt.vector3d(0, 0, 85);
        }
    }

    Shortcut {
        sequence: "F5"
        onActivated: {
            // console.log("F5 presionado: Solicitando reinicio de laberinto...");
            maze3D.reqResetMaze();
        }
    }

    // Modelo para almacenar los pesos de cada celda
    ListModel { id: cellWeightsModel }

    // Función para actualizar o crear el peso de una celda
    function updateCellWeight(x, y, peso) {
        var uniqueId = "wgt_" + x + "_" + y;

        // Si ya existe, solo le cambiamos el número
        for (var i = 0; i < cellWeightsModel.count; i++) {
            if (cellWeightsModel.get(i).uid === uniqueId) {
                cellWeightsModel.setProperty(i, "peso", peso);
                return;
            }
        }

        // Si no existe, lo creamos
        cellWeightsModel.append({ "uid": uniqueId, "logX": x, "logY": y, "peso": peso });
    }

    function updateCellWalls(x, y, wallsByte) {
        // 1. Calculamos el centro visual de la celda actual
        var cx = -71.75 + (x * 20.5);
        // Restamos en Z porque asumo que Y lógico positivo va hacia el Norte (adentro de la pantalla, que es Z negativo en 3D)
        var cz = 51.25 - (y * 20.5);

        // 2. Evaluamos el byte (bit 0=N, 1=E, 2=S, 3=W) según tu código C++
        if (wallsByte & (1 << 0)) addWallIfNotExists(cx, cz - 10.25, 0);  // Norte
        if (wallsByte & (1 << 1)) addWallIfNotExists(cx + 10.25, cz, 90); // Este
        if (wallsByte & (1 << 2)) addWallIfNotExists(cx, cz + 10.25, 0);  // Sur
        if (wallsByte & (1 << 3)) addWallIfNotExists(cx - 10.25, cz, 90); // Oeste
    }

    function addWallIfNotExists(px, pz, rot) {
        // TRUCO: Usamos las coordenadas como un ID único para no duplicar paredes compartidas
        var uniqueId = "w_" + px.toFixed(2) + "_" + pz.toFixed(2);

        for (var i = 0; i < mazeWallsModel.count; i++) {
            if (mazeWallsModel.get(i).uid === uniqueId) return; // Si ya existe, salimos
        }

        mazeWallsModel.append({ "uid": uniqueId, "posX": px, "posZ": pz, "rotY": rot });
    }

    Item {
        id: stateController
        objectName: "stateController"

        // --- Propiedades para la visibilidad de los muros ---
        // Cambia estos valores para ver cómo la escena reacciona
        property bool sensorIzquierdo: false  // true = hay muro a la izquierda, false = hay intersección
        property bool sensorDerecho: false
        property bool sensorFrontal: false

        // --- Propiedades para la posición del coche ---
        // Valores de 0.0 (lejos del muro) a 1.0 (pegado al muro)
        property real carPosition: 0.5

        property real leftMotorPower: 0.25 // Ejemplo: 25%
        property real rightMotorPower: 0.75 // Ejemplo: 75%

        // NEW
        function triggerMoveForward() { animForward.start(); }
        function triggerTurnLeft()    { animLeft.start(); }
        function triggerTurnRight()   { animRight.start(); }
    }

    Item {
        id: __materialLibrary__

        PrincipledMaterial {
            id: principledMaterial
            objectName: "New Material"
        }

        Texture {
            id: studio_small_09_1k
            source: "qrc:/3d/assets/studio_small_09_1k.hdr"
            objectName: "Studio small 09 1k"
        }
    }

    View3D {
        id: view3D
        anchors.fill: parent

        camera: globalCamera

        environment: SceneEnvironment {
            clearColor: "#1a1a1a"
            backgroundMode: SceneEnvironment.Color

            // HDR
            lightProbe: studio_small_09_1k
            probeExposure: 0.8

            // COLOR
            // tonemapMode: SceneEnvironment.TonemapModeLinear
            tonemapMode: SceneEnvironment.TonemapModeAces

            // AMBIENT OCLUSSION

            aoEnabled: true
            aoStrength: 85
            aoDistance: 12.0
            aoBias: 0.1
            aoSoftness: 50
            aoDither: true

            fog: fog
            probeHorizon: 0.2

            antialiasingQuality: SceneEnvironment.High
            antialiasingMode: SceneEnvironment.MSAA

            // Fog {
            //     color: "#1a1a1a"
            //     enabled: true
            //     depthEnabled: true

            //     depthNear: 100
            //     depthFar: 150
            //     density: 1.0
            // }

            Fog {
                id: fog
                color: "#1a1a1a"
                // color: "#262626"
                mostIntenseY: -1
                leastIntenseY: 4
                heightEnabled: true
                transmitEnabled: false
                depthCurve: 2
                enabled: true
                depthEnabled: true // Enable depth fog
                density: 0.4
                depthNear: 0
                depthFar: 55
            }
        }

        Node {
            id: cameraOrbitPivot
            position: Qt.vector3d(0, 0, 0) // Centro del mundo

            // 1. EL PIVOTE MANEJA LA ROTACIÓN INICIAL
            eulerRotation.x: -50 // Tu ángulo inicial deseado
            eulerRotation.y: 0

            PerspectiveCamera {
                id: globalCamera
                // 2. LA CÁMARA SOLO SE ALEJA HACIA ATRÁS (Z)
                // Usamos 150 (o la distancia que prefieras) para compensar el zoom
                position: Qt.vector3d(0, -20, 180)

                // LA CÁMARA NO TIENE ROTACIÓN (mira de frente a su padre)
                eulerRotation.x: 0
                eulerRotation.y: 0
                eulerRotation.z: 0

                fieldOfView: 50 // FOV inicial
            }

            // PerspectiveCamera {
            //     id: globalCamera
            //     // Posición relativa al pivote: Alta y hacia atrás
            //     position: Qt.vector3d(0, 100, 110)
            //     eulerRotation.x: -50 // Mirando hacia abajo al centro
            //     eulerRotation.y: 0
            // }
        }

        DirectionalLight {
            eulerRotation.x: -45
            eulerRotation.y: 0
            brightness: 1.5

            castsShadow: true
            shadowFactor: 80 // Qué tan oscura es la sombra (0-100)
            // shadowMapResolution: 2048 // Si se ve pixelada la sombra, súbelo a 4096 (consume más VRAM)
        }

        Laberinto8x6 {
            id: piso
            position: Qt.vector3d(0, -2, 0) // En QtQuick3D se usa 'position', no x, y, z sueltos
            eulerRotation.y: 90
            // Prueba 1: Hacerlo 100 veces más grande
            scale: Qt.vector3d(100, 100, 100)
        }

        // --- MARCADOR VISUAL DE LA CELDA OBJETIVO ---
        Model {
            id: targetHighlight
            source: "#Rectangle"

            // Solo es visible si el targetX no es negativo
            visible: maze3D.robotTargetX >= 0 && maze3D.robotTargetY >= 0

            // Usamos las variables del robotTarget
            x: -71.75 + (maze3D.robotTargetX * 20.5)
            z: 51.25 - (maze3D.robotTargetY * 20.5)
            y: 0.2 // Un pelín más alto que el piso para que no se "pelee" visualmente con la madera

            eulerRotation.x: -90
            scale: Qt.vector3d(0.2, 0.2, 0.2) // Tamaño de 1 celda

            materials: PrincipledMaterial {
                baseColor: "#FF00FF" // Tu verde cian/agua
                emissiveFactor: Qt.vector3d(0.0, 0.98, 0.6) // Le da un efecto de luz "led"
                alphaMode: PrincipledMaterial.Blend
                opacity: 0.5 // Semitransparente
            }
        }

        Model {
            id: startHighlight
            source: "#Rectangle"

            // Suponiendo que usás las variables del robot, o creaste startX/startY
            visible: maze3D.robotLogX >= 0 && maze3D.robotLogY >= 0

            x: -71.75 + (maze3D.robotLogX * 20.5)
            z: 51.25 - (maze3D.robotLogY * 20.5)
            y: 0.15 // Un pelín más bajo que el target por si se superponen

            eulerRotation.x: -90
            scale: Qt.vector3d(0.2, 0.2, 0.2)

            materials: PrincipledMaterial {
                baseColor: "#7CFC00" // Azul brillante
                emissiveFactor: Qt.vector3d(0.0, 0.75, 1.0) // Brillo azulado
                alphaMode: PrincipledMaterial.Blend
                opacity: 0.5
            }
        }

        // --- GRILLA INVISIBLE PARA CLICKS (HITBOXES) ---
        Repeater3D {
            model: 48 // Tus 8 columnas x 6 filas

            delegate: Model {
                // 1. Calculamos las coordenadas lógicas a partir del índice (0 al 47)
                property int logicalX: index % 8
                property int logicalY: Math.floor(index / 8)

                source: "#Rectangle"

                // ¡LA CLAVE! Le decimos al motor que este objeto se puede "tocar" con el ratón
                pickable: true

                x: -71.75 + (logicalX * 20.5)
                z: 51.25 - (logicalY * 20.5)
                y: 0.3 // Lo ponemos un poquito más arriba para que el rayo lo choque a él primero

                eulerRotation.x: -90
                scale: Qt.vector3d(0.205, 0.205, 0.205)

                // Lo hacemos casi 100% invisible para que no se vea, pero siga existiendo físicamente
                materials: PrincipledMaterial {
                    baseColor: "white"
                    alphaMode: PrincipledMaterial.Blend
                    opacity: 0.01
                }
            }
        }

        // --- EJES DE REFERENCIA ---
        Node {
            id: ejesReferencia

            // 1. Números del Eje X (0 al 7) en el borde inferior
            Repeater3D {
                model: 8 // Se repite 8 veces (index va de 0 a 7)
                delegate: Model {
                    source: "#Rectangle"

                    // La misma cuenta de la celda, pero desplazada una fila hacia "abajo" (Z positivo)
                    x: -71.75 + (index * 20.5)
                    z: 51.25 + 20.5 // 71.75

                    y: 0.1
                    eulerRotation.x: -90
                    scale: Qt.vector3d(0.2, 0.2, 0.2)

                    materials: PrincipledMaterial {
                        alphaMode: PrincipledMaterial.Blend
                        baseColorMap: Texture {
                            sourceItem: Rectangle {
                                width: 100; height: 100; color: "transparent"
                                Text {
                                    anchors.centerIn: parent
                                    text: index
                                    color: "white"
                                    font.pixelSize: 60; font.bold: true
                                }
                            }
                        }
                    }
                }
            }

            // 2. Números del Eje Y (0 al 5) en el borde izquierdo
            Repeater3D {
                model: 6 // Se repite 6 veces (index va de 0 a 5)
                delegate: Model {
                    source: "#Rectangle"

                    // Desplazado una columna hacia la "izquierda" (X negativo)
                    x: -71.75 - 20.5 // -92.25
                    z: 51.25 - (index * 20.5)

                    y: 0.1
                    eulerRotation.x: -90
                    scale: Qt.vector3d(0.2, 0.2, 0.2)

                    materials: PrincipledMaterial {
                        alphaMode: PrincipledMaterial.Blend
                        baseColorMap: Texture {
                            sourceItem: Rectangle {
                                width: 100; height: 100; color: "transparent"
                                Text {
                                    anchors.centerIn: parent
                                    text: index
                                    color: "white"
                                    font.pixelSize: 60; font.bold: true
                                }
                            }
                        }
                    }
                }
            }

            // 3. Letra "X" en la esquina inferior izquierda
            Model {
                source: "#Rectangle"
                x: 92.25
                z: 71.75
                y: 0.1
                eulerRotation.x: -90
                scale: Qt.vector3d(0.2, 0.2, 0.2)
                materials: PrincipledMaterial {
                    alphaMode: PrincipledMaterial.Blend
                    baseColorMap: Texture {
                        sourceItem: Rectangle {
                            width: 100; height: 100; color: "transparent"
                            Text {
                                anchors.centerIn: parent; text: "X"
                                color: "white"; font.pixelSize: 60; font.bold: true
                            }
                        }
                    }
                }
            }

            // 4. Letra "Y" un poco más arriba de la X
            Model {
                source: "#Rectangle"
                x: -92.25
                z: -71.75 // A mitad de camino entre la "X" y el "0" del eje Y
                y: 0.1
                eulerRotation.x: -90
                scale: Qt.vector3d(0.2, 0.2, 0.2)
                materials: PrincipledMaterial {
                    alphaMode: PrincipledMaterial.Blend
                    baseColorMap: Texture {
                        sourceItem: Rectangle {
                            width: 100; height: 100; color: "transparent"
                            Text {
                                anchors.centerIn: parent; text: "Y"
                                color: "white"; font.pixelSize: 60; font.bold: true
                            }
                        }
                    }
                }
            }
        }

        ListModel {
            id: mazeWallsModel

        }

        Component {
            id: wallComponent

            TablaMadera {
                // position: Qt.vector3d(0, 0.48, -0.34)
                // x: model.posX
                // y: 0 // Ajustá esto si tu tabla queda hundida en el piso
                // z: model.posZ
                x: 0
                y: 0
                z: 0
                eulerRotation.y: 0
                scale: Qt.vector3d(100, 100, 100)
            }
        }

        Node {
            id: mazeWorld

            // --- CONFIGURACIÓN DE LA GRILLA ---
            // Ajustá estos valores. Asumo que 20.5 es el ancho/largo de tu celda
            // property real cellSize: 20.5

            // // Ajustá estos offsets para que la celda [0,0] coincida con tu piso visual
            // property real startOffsetX: 0
            // property real startOffsetZ: -10.25
            property real cellSize: 20.5

            // Ajustá estos offsets para que la celda [0,0] coincida con tu piso visual
            property real startOffsetX: 0
            property real startOffsetZ: -0
            // --- GENERADOR DE PAREDES ---
            Repeater3D {
                model: mazeWallsModel
                delegate: Node {
                    // 1. LÓGICA: Ubicamos y rotamos el Nodo usando el Model
                    // Sumamos el offset inicial para que coincida con la grilla
                    x: model.posX + mazeWorld.startOffsetX
                    z: model.posZ + mazeWorld.startOffsetZ
                    eulerRotation.y: model.rotY

                    id: wallNode // <-- Le damos un nombre explícito al Nodo

                    opacity: 0.0 // Nace invisible

                    Component.onCompleted: fadeInAnim.start()

                    NumberAnimation {
                        id: fadeInAnim
                        target: wallNode // <-- Apuntamos directamente al ID
                        property: "opacity"
                        to: 1.0
                        duration: 400
                        easing.type: Easing.OutQuad
                    }

                    // 2. VISUAL: Tu tabla con el desfase mágico aplicado
                    TablaMadera {
                        position: Qt.vector3d(0, 0, 0)
                        // position: Qt.vector3d(0, 0.48, -0.34) // ¡Tus valores!
                        scale: Qt.vector3d(100, 100, 100)
                    }
                }
            }

            // D. Celdas Pintadas de Negro
            Repeater3D {
                model: blackCellsModel
                delegate: Model {
                    source: "#Rectangle" // Un plano simple
                    x: -71.75 + (model.px * 20.5)
                    z: 51.25 - (model.py * 20.5)
                    y: 0.15 // A ras del suelo, un poco por debajo de los números
                    eulerRotation.x: -90 // Acostado sobre el piso
                    scale: Qt.vector3d(0.205, 0.205, 0.205) // Tamaño exacto de tu celda

                    materials: PrincipledMaterial {
                        baseColor: "#050505" // Un negro casi puro
                        roughness: 0.9 // Muy rugoso para que no refleje la luz como un espejo
                    }
                }
            }

            // --- GENERADOR DE TEXTOS EN EL SUELO ---
            Repeater3D {
                model: cellWeightsModel
                delegate: Model {
                    source: "#Rectangle" // Un plano cuadrado básico

                    // Mismas coordenadas del suelo, pero centradas
                    x: -71.75 + (model.logX * 20.5)
                    z: 51.25 - (model.logY * 20.5)
                    y: 0.1 // Lo levantamos 1 milímetro para que no se superponga con el modelo de tu laberinto

                    eulerRotation.x: -90 // Lo acostamos en el suelo

                    // El plano de QML mide 100x100. Tu celda 20.5. Lo escalamos para que entre.
                    scale: Qt.vector3d(0.2, 0.2, 0.2)

                    // Acá ocurre la magia: Usamos un Item 2D como textura 3D
                    materials: PrincipledMaterial {
                        alphaMode: PrincipledMaterial.Blend // Permite fondo transparente
                        baseColorMap: Texture {
                            sourceItem: Rectangle {
                                width: 100
                                height: 100
                                color: "transparent" // Fondo invisible

                                Text {
                                    anchors.centerIn: parent
                                    text: model.peso === 255 ? "" : model.peso

                                    // --- MAGIA DE COLORES ---
                                    color: {
                                        if (model.peso === 255) return "transparent";

                                        // maxCost define a partir de qué número se vuelve 100% rojo.
                                        // Para un 8x6, 35 o 40 es un buen límite.
                                        var currentMax = maze3D.maxMazeCost > 0 ? maze3D.maxMazeCost : 1;

                                        // Calculamos el Hue (120 = Verde, 0 = Rojo)
                                        var h = 120 - ((model.peso * 120) / currentMax);
                                        if (h < 0) h = 0; // Topamos en rojo

                                        // QML usa valores de 0.0 a 1.0 para HSVA
                                        return Qt.hsva(h / 360.0, 1.0, 1.0, 1.0);
                                    }
                                    // ------------------------

                                    font.pixelSize: 50
                                    font.bold: true
                                    style: Text.Outline
                                    styleColor: "black" // El borde negro ayuda a que los verdes y rojos resalten sobre el piso claro
                                }
                            }
                        }
                    }
                }
            }
        }

        // --- MODELO PARA EL CAMINO ---
        ListModel { id: pathTraceModel }

        // --- VISUALIZACIÓN DEL CAMINO (Trail) ---
        Repeater3D {
            model: pathTraceModel
            delegate: Model {
                source: "#Sphere" // Puedes usar #Rectangle si prefieres cuadraditos

                // Ubicación en la celda
                x: -71.75 + (model.px * 20.5)
                z: 51.25 - (model.py * 20.5)
                y: 0.5 // Un poco elevado para que flote sobre los números

                scale: Qt.vector3d(0.04, 0.04, 0.04) // Esferas pequeñas

                materials: PrincipledMaterial {
                    baseColor: "#FF00FF" // El magenta de tu meta
                    emissiveFactor: Qt.vector3d(1.0, 0.0, 1.0)
                    opacity: 0.6
                    alphaMode: PrincipledMaterial.Blend
                }
            }
        }

        // Función para que C++ nos pase la lista de puntos
        function updatePath(pointsArray) {
            pathTraceModel.clear();
            for (var i = 0; i < pointsArray.length; i++) {
                pathTraceModel.append({ "px": pointsArray[i].x, "py": pointsArray[i].y });
            }
        }

        Node {
            id: robotPivot

            property real cellSize: 20.5
            property real robotOffsetX: -71.75
            property real robotOffsetZ: 51.25

            x: robotPivot.robotOffsetX + (maze3D.robotLogX * mazeWorld.cellSize)
            z: robotPivot.robotOffsetZ - (maze3D.robotLogY * mazeWorld.cellSize)
            y: 5.95
            eulerRotation.y: {
                switch(maze3D.robotDir) {
                    case 0: return -90;   // Norte
                    case 1: return 180; // Este (ajusta el signo según tu sistema de coordenadas)
                    case 2: return 90; // Sur
                    case 3: return 0;  // Oeste
                    default: return 0;
                }
            }

            Behavior on x { NumberAnimation { duration: 300 } }
            Behavior on z { NumberAnimation { duration: 300 } }
            Behavior on eulerRotation.y { RotationAnimation { direction: RotationAnimation.Shortest; duration: 250 } }

            Node {
                id: followCameraPivot
                position: Qt.vector3d(0,0,0)
                // position: Qt.vector3d(35,35,0)
                eulerRotation.x: -35
                eulerRotation.y: 90

                PerspectiveCamera {
                    id: followCamera
                    x: 0
                    y: 0
                    // Se posiciona atrás (-40 en X local) y arriba (30 en Y)
                    position: Qt.vector3d(0, 0, 40)
                    eulerRotation.x: 0 // Mira un poco hacia abajo
                    eulerRotation.y: 0 // Apunta hacia el frente del auto
                }
            }

            PerspectiveCamera {
                id: povCamera
                position: Qt.vector3d(-3, -1, 0)
                eulerRotation: Qt.vector3d(0, 90, 0)
                fieldOfView: 85
            }

            // PerspectiveCamera {
            //     id: followCamera
            //     // Se posiciona atrás (-40 en X local) y arriba (30 en Y)
            //     position: Qt.vector3d(35, 35, 0)
            //     eulerRotation.x: -35 // Mira un poco hacia abajo
            //     eulerRotation.y: 90 // Apunta hacia el frente del auto
            // }

            Car {
                id: car
                position: Qt.vector3d(7, 0, 0)
            }
        }
    }

    Rectangle {
        id: fadeOverlay
        anchors.fill: parent
        color: "#000000"
        opacity: 0.0 // Invisible por defecto



        // Esta propiedad ignora los clics para que lleguen al MouseArea que está abajo
        enabled: false

        SequentialAnimation {
            id: cameraTransitionAnim
            property int nextIndex: 0

            // Variable temporal para saber a qué cámara vamos
            property var nextCamera: null

            // 1. Fundido a negro (150 milisegundos)
            NumberAnimation { target: fadeOverlay; property: "opacity"; to: 1.0; duration: 150; easing.type: Easing.InOutQuad }

            ScriptAction {
                script: {
                    view3D.camera = cameraTransitionAnim.nextCamera;
                    maze3D.activeCameraIndex = cameraTransitionAnim.nextIndex;
                }
            }

            // 3. Volvemos a hacer la pantalla transparente
            NumberAnimation { target: fadeOverlay; property: "opacity"; to: 0.0; duration: 150; easing.type: Easing.InOutQuad }
        }

        // SequentialAnimation {
        //     id: cameraTransitionAnim

        //     // Variable temporal para saber a qué cámara vamos
        //     property var nextCamera: null

        //     // 1. Fundido a negro (150 milisegundos)
        //     NumberAnimation { target: fadeOverlay; property: "opacity"; to: 1.0; duration: 150; easing.type: Easing.InOutQuad }

        //     // 2. Cambiamos la cámara de golpe mientras la pantalla está negra
        //     PropertyAction { target: view3D; property: "camera"; value: cameraTransitionAnim.nextCamera }

        //     // 3. Volvemos a hacer la pantalla transparente
        //     NumberAnimation { target: fadeOverlay; property: "opacity"; to: 0.0; duration: 150; easing.type: Easing.InOutQuad }
        // }
    }

    MouseArea {
        anchors.fill: parent
        // Aceptamos los 3 botones
        acceptedButtons: Qt.LeftButton | Qt.MiddleButton | Qt.RightButton

        property real lastMouseX: 0
        property real lastMouseY: 0
        property bool isDragging: false

        onPressed: (mouse) => {
            lastMouseX = mouse.x
            lastMouseY = mouse.y
            isDragging = false
        }

        onPositionChanged: (mouse) => {
            if (maze3D.activeCameraIndex === 2) return; // Bloqueado en POV

            if(Math.abs(mouseX - lastMouseX) > 1 || Math.abs((mouse.y - lastMouseY) > 1)) {
                isDragging = true;
            }

            var deltaX = mouse.x - lastMouseX
            var deltaY = mouse.y - lastMouseY

            // --- CLIC IZQUIERDO: ROTAR ---
            if (pressedButtons & Qt.LeftButton) {
                if (maze3D.activeCameraIndex === 0) { // Global
                    cameraOrbitPivot.eulerRotation.y -= deltaX * 0.5
                    var pG = cameraOrbitPivot.eulerRotation.x - deltaY * 0.5
                    cameraOrbitPivot.eulerRotation.x = Math.max(-90, Math.min(-5, pG))
                }
                else if (maze3D.activeCameraIndex === 1) { // Persecución
                    followCameraPivot.eulerRotation.y -= deltaX * 0.5
                    var pF = followCameraPivot.eulerRotation.x - deltaY * 0.5
                    followCameraPivot.eulerRotation.x = Math.max(-60, Math.min(-5, pF))
                }
            }
            // --- CLIC CENTRAL: PANEO (Solo Global) ---
            else if ((pressedButtons & Qt.MiddleButton) && maze3D.activeCameraIndex === 0) {
                var yawRad = cameraOrbitPivot.eulerRotation.y * Math.PI / 180
                var panSpeed = 0.2
                var moveX = (deltaX * Math.cos(yawRad) + deltaY * Math.sin(yawRad)) * panSpeed
                var moveZ = (deltaY * Math.cos(yawRad) - deltaX * Math.sin(yawRad)) * panSpeed
                cameraOrbitPivot.x -= moveX
                cameraOrbitPivot.z -= moveZ
            }

            lastMouseX = mouse.x
            lastMouseY = mouse.y
        }

        // --- RUEDA: ZOOM BASE ESTABLE ---
        onWheel: (wheel) => {
            if (maze3D.activeCameraIndex === 2) return; // Bloqueado en POV

            var dir = wheel.angleDelta.y / 120

            if (maze3D.activeCameraIndex === 0) {
                // Zoom Global (Lente)
                var nFOV = globalCamera.fieldOfView - (dir * 5)
                globalCamera.fieldOfView = Math.max(15, Math.min(100, nFOV))
            }
            else if (maze3D.activeCameraIndex === 1) {
                // Zoom Persecución (Distancia física)
                var nDist = followCamera.position.z - (dir * 10)
                followCamera.position.z = Math.max(30, Math.min(200, nDist))
            }
        }

        onClicked: (mouse) => {
            // if (mouse.button === Qt.LeftButton) {
            // Si la cámara POV está activa, ignoramos el clic
                if (maze3D.activeCameraIndex === 2 || isDragging) return;

            // --- CLIC CENTRAL: Rotar el robot ---
                if (mouse.button === Qt.MiddleButton) {
                    // Sumamos 1 a la dirección y usamos % 4 para que vuelva a 0 (0->1->2->3->0)
                    maze3D.robotDir = (maze3D.robotDir + 1) % 4;
                    console.log("Nueva dirección del robot:", maze3D.robotDir);
                    return; // Salimos acá porque no hace falta disparar el rayo 3D para esto
                }

                // Solo seleccionamos si el ratón NO se movió (es decir, no fue un arrastre para rotar la cámara)
                // if (mouse.x === lastMouseX && mouse.y === lastMouseY) {
                    // 1. Disparamos el rayo láser desde la cámara
                    var pickResult = view3D.pick(mouse.x, mouse.y);

                    // 2. Si el rayo chocó con algo...
                    if (pickResult.objectHit) {
                        var hitObj = pickResult.objectHit;

                        // 3. Verificamos si lo que chocamos es un Hitbox (si tiene las propiedades lógicas)
                        if (hitObj.logicalX !== undefined && hitObj.logicalY !== undefined) {
                            if (mouse.button === Qt.LeftButton) {
                                // CLIC IZQUIERDO -> Marca la Meta (Target)
                                maze3D.robotTargetX = hitObj.logicalX;
                                maze3D.robotTargetY = hitObj.logicalY;
                                console.log("Meta: X", maze3D.targetX, "Y", maze3D.targetY);
                            } else if (mouse.button === Qt.RightButton) {
                                // CLIC DERECHO -> Marca el Inicio (Start) o la posición del robot
                                // (Asegurate de crear properties startX y startY en tu maze3D si vas a usar esto)
                                maze3D.robotLogX = hitObj.logicalX;
                                maze3D.robotLogY = hitObj.logicalY;
                                console.log("Inicio: X", maze3D.startX, "Y", maze3D.startY);
                            }
                        }
                    }
                // }
            // }
        }
    }

    // --- PANEL LATERAL DESLIZABLE (FLYOUT) ---
    Item {
        id: sidePanelContainer
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: powerBar.top
        width: 185 // El ancho total de tu panel abierto

        // Z-Index alto para asegurar que tape todo, incluido el 3D
        z: 100

        Rectangle {
            id: sideMenu
            width: parent.width
            height: parent.height
            color: "#1c1f22" // Un tono oscuro ligeramente distinto al fondo principal

            // LÓGICA DE DESLIZAMIENTO ACTUALIZADA:
            x: panelHover.hovered ? 0 : width - 12

            // Borde izquierdo con tu color cian/verde para que se note
            Rectangle {
                width: 2
                height: parent.height
                color: "#393F44"
                anchors.left: parent.left
            }

            // Animación suave de entrada y salida
            Behavior on x {
                NumberAnimation {
                    duration: 300
                    easing.type: Easing.OutCubic
                }
            }

            // --- 1. EL NUEVO OBSERVADOR (Reemplaza al hoverArea) ---
            HoverHandler {
                id: panelHover
            }

            // --- 2. EL ESCUDO DE CLICS ---
            // Mantenemos un MouseArea ciego de fondo para evitar que, al hacer
            // clic en un espacio vacío del panel, muevas la cámara 3D por accidente.
            MouseArea {
                anchors.fill: parent
                hoverEnabled: false // ¡Apagado para que no tiemble!
                acceptedButtons: Qt.LeftButton | Qt.MiddleButton | Qt.RightButton
            }

            // --- CONTENIDO DEL PANEL ---
            Column {
                anchors.fill: parent
                anchors.topMargin: 20
                anchors.bottomMargin: 20
                anchors.leftMargin: 15 // Despega el contenido de la línea gris
                anchors.rightMargin: 10
                spacing: 15

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "State"
                    color: "white"
                    font.family: "Century Gothic"
                    font.pixelSize: 18
                    font.bold: true
                }

                Rectangle { width: parent.width; height: 1; color: "#393F44" } // Separador

                // SECCIÓN 1: ESTADO DEL ROBOT
                Column {
                    width: parent.width
                    spacing: 12 // Un poco más de espacio entre bloques

                    // Current Action
                    Column {
                        width: parent.width; spacing: 2
                        Text { text: "Current Action"; color: "white"; font.family: "Century Gothic"; font.pixelSize: 12; font.bold: true }
                        Text {
                            width: parent.width

                            // --- BINDING DEL ESTADO (ENUM) ---
                            text: {
                                switch(maze3D.robotAction) {
                                    case 0: return "IDLE";
                                    case 1: return "FOLLOW WALL";
                                    case 2: return "CENTER IN CELL";
                                    case 3: return "AFTER TURN";
                                    case 4: return "TURN PIVOT";
                                    case 5: return "BACK WALL ALIGN";
                                    default: return "UNKNOWN";
                                }
                            }

                            color: "#00FA9A"
                            font.family: "Century Gothic"; font.pixelSize: 12; font.bold: true
                            horizontalAlignment: Text.AlignRight
                            wrapMode: Text.WordWrap
                        }
                    }

                    // Current Direction
                    Column {
                        width: parent.width; spacing: 2
                        Text { text: "Current Direction"; color: "white"; font.family: "Century Gothic"; font.pixelSize: 12; font.bold: true }
                        Text {
                            width: parent.width

                            // --- MAGIA DEL BINDING AUTOMÁTICO ---
                            text: {
                                switch(maze3D.robotDir) {
                                    case 0: return "North";
                                    case 1: return "East";
                                    case 2: return "South";
                                    case 3: return "West";
                                    default: return "-";
                                }
                            }

                            color: "#00FA9A"
                            font.family: "Century Gothic"; font.pixelSize: 12; font.bold: true
                            horizontalAlignment: Text.AlignRight
                            wrapMode: Text.WordWrap
                        }
                    }
                }

                Rectangle { width: parent.width; height: 1; color: "#393F44" } // Línea divisoria

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Robot Control"
                    color: "white"
                    font.family: "Century Gothic"
                    font.pixelSize: 18
                    font.bold: true
                }

                // SECCIÓN 2: BOTONES DE CONTROL
                Column {
                    width: parent.width
                    spacing: 8

                    // 1. SET START
                    Rectangle {
                        width: parent.width; height: 32; radius: 3
                        color: btnSetStartHover.hovered ? "#00965C" : "#393F44"
                        Text { anchors.centerIn: parent; text: "SET START"; color: "white"; font.family: "Century Gothic"; font.pixelSize: 11; font.bold: true }
                        HoverHandler { id: btnSetStartHover }
                        MouseArea { anchors.fill: parent; onClicked: maze3D.reqSetStart() }
                    }

                    // 2. SET TARGET
                    Rectangle {
                        width: parent.width; height: 32; radius: 3
                        color: btnSetTargetHover.hovered ? "#00965C" : "#393F44"
                        Text { anchors.centerIn: parent; text: "SET TARGET"; color: "white"; font.family: "Century Gothic"; font.pixelSize: 11; font.bold: true }
                        HoverHandler { id: btnSetTargetHover }
                        MouseArea { anchors.fill: parent; onClicked: maze3D.reqSetTarget() }
                    }

                    // 4. FIND BLACK CELLS (Modo Búsqueda de Celdas)
                    Rectangle {
                        width: parent.width; height: 32; radius: 3
                        color: btnFindBlackHover.hovered ? "#00965C" : "#393F44"
                        Text {
                            anchors.centerIn: parent; text: "FIND BLACK CELLS"
                            color: "white"; font.family: "Century Gothic"; font.pixelSize: 10; font.bold: true
                        }
                        HoverHandler { id: btnFindBlackHover }
                        MouseArea { anchors.fill: parent; onClicked: maze3D.reqFindBlackCells() }
                    }

                    // // 3. START RUN
                    // Rectangle {
                    //     width: parent.width; height: 32; radius: 3
                    //     color: btnStartRunHover.hovered ? "#00965C" : "#393F44"
                    //     Text { anchors.centerIn: parent; text: "START RUN"; color: "white"; font.family: "Century Gothic"; font.pixelSize: 11; font.bold: true }
                    //     HoverHandler { id: btnStartRunHover }
                    //     MouseArea { anchors.fill: parent; onClicked: maze3D.reqStartRun() }
                    // }

                    // 4. START EXPLORATION
                    Rectangle {
                        width: parent.width; height: 32; radius: 3
                        color: btnStartExplorationHover.hovered ? "#00965C" : "#393F44"
                        Text { anchors.centerIn: parent; text: "START EXPLORATION"; color: "white"; font.family: "Century Gothic"; font.pixelSize: 11; font.bold: true }
                        HoverHandler { id: btnStartExplorationHover }
                        MouseArea { anchors.fill: parent; onClicked: maze3D.reqStartExploration() }
                    }

                    // 5. STOP (Emergencia - Naranja distintivo)
                    Rectangle {
                        width: parent.width; height: 32; radius: 3
                        color: btnStopHover.hovered ? "#FFA500" : "#8C5A00" // Rojo fuego en hover, rojo oscuro normal
                        Text { anchors.centerIn: parent; text: "STOP"; color: "white"; font.family: "Century Gothic"; font.pixelSize: 12; font.bold: true }
                        HoverHandler { id: btnStopHover }
                        MouseArea { anchors.fill: parent; onClicked: maze3D.reqStopRobot() }
                    }
                }
            }
        }
    }

    Rectangle {
        id: powerBar
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: parent.height * 0.15
        color: "#22262a"

        Rectangle { // El borde superior
            width: parent.width
            height: 2
            color: "#393F44"
            anchors.top: parent.top
        }

        Item {
            id: leftPowerDisplay
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.07
            width: parent.width * 0.3 // Ocupa un 30% del ancho total
            height: parent.height

            Column {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                spacing: 2

                // Label del valor de potencia (dinámico)
                Text {
                    text: "X: " + maze3D.robotLogX + "  Y: " + maze3D.robotLogY
                    // text: (stateController.leftMotorPower * 100).toFixed(0) + "%"
                    font.pixelSize: 19
                    color: "#00FA9A" // Color verde
                    font.family: "Century Gothic"
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                }

                // Label estático
                Text {
                    text: "Current Cell"
                    font.pixelSize: 14
                    color: "#a0a0a0" // Gris claro
                    font.family: "Century Gothic"
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                }
            }
        }

        Item {
            id: centerPowerDisplay
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width * 0.3
            height: parent.height

            Column {
                anchors.centerIn: parent
                spacing: 2

                Text {
                    // --- MAGIA DEL RELOJ AQUÍ ---
                    text: maze3D.formatTime(maze3D.runTimeSeconds)

                    font.pixelSize: 19
                    color: "#00FA9A"
                    font.family: "Century Gothic"
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    text: "Run Time"
                    font.pixelSize: 14
                    color: "#a0a0a0"
                    font.family: "Century Gothic"
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        Item {
            id: rightPowerDisplay
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: parent.width * 0.07
            width: parent.width * 0.3 // Ocupa un 30% del ancho total
            height: parent.height

            Column {
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                spacing: 2

                // Label del valor de potencia (dinámico)
                Text {
                    text: "X: " + maze3D.robotTargetX + "  Y: " + maze3D.robotTargetY
                    // text: (stateController.rightMotorPower * 100).toFixed(0) + "%"
                    font.pixelSize: 19
                    color: "#00FA9A"
                    font.family: "Century Gothic"
                    font.bold: true
                    horizontalAlignment: Text.AlignRight
                    anchors.right: parent.right
                }

                // Label estático
                Text {
                    text: "Target Cell"
                    // text: "Right Power"
                    font.pixelSize: 14
                    font.family: "Century Gothic"
                    font.bold: true
                    color: "#a0a0a0"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;matPrevEnvDoc:"SkyBox";matPrevEnvValueDoc:"preview_studio";matPrevModelDoc:"#Sphere"}
D{i:5;cameraSpeed3d:1;cameraSpeed3dMultiplier:1}D{i:6;cameraSpeed3d:25;cameraSpeed3dMultiplier:1}
D{i:13;cameraSpeed3d:25;cameraSpeed3dMultiplier:1}D{i:16;cameraSpeed3d:1;cameraSpeed3dMultiplier:1}
D{i:17;cameraSpeed3d:1;cameraSpeed3dMultiplier:1}D{i:26;cameraSpeed3d:1;cameraSpeed3dMultiplier:1}
D{i:43;cameraSpeed3d:25;cameraSpeed3dMultiplier:1}
}
##^##*/

