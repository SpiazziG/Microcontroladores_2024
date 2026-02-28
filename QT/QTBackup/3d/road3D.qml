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
import "Tabla"
// import QtQuick.Studio.DesignEffects
import "Piso"

Rectangle {
    id: rectangle
    anchors.fill: parent
    // width: Constants.width
    // height: Constants.height
    color: "#22262a"

    border.color: "#212528"

    signal animationFinished()

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
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: powerBar.top
        // x: 120
        // y: 71
        // width: 382
        // height: 296
        clip: false
        environment: SceneEnvironment{
            id: sceneEnvironment
            fog: fog
            probeHorizon: 0.2
            lightProbe: studio_small_09_1k
            aoDither: false
            aoEnabled: true
            probeExposure: 0.3
            tonemapMode: SceneEnvironment.TonemapModeLinear
            antialiasingQuality: SceneEnvironment.Medium
            antialiasingMode: SceneEnvironment.SSAA

            Fog {
                id: fog
                color: "#262626"
                mostIntenseY: -1
                leastIntenseY: 4
                heightEnabled: true
                transmitEnabled: false
                depthCurve: 2
                enabled: true
                depthEnabled: true // Enable depth fog
                density: 1
                depthNear: 0
                depthFar: 55
            }
        }

        Node {
            id: scene

            property real startX: 0
            property real intersectionX: -15

            DirectionalLight {
                id: directionalLight
                x: 15
                y: 16
                bakeMode: Light.BakeModeDisabled
                shadowFactor: 25
                shadowFilter: 3
                shadowMapQuality: Light.ShadowMapQualityMedium
                shadowBias: 0.001
                castsShadow: true

                brightness: 0.8
                eulerRotation.x: -23
                z: 0
                eulerRotation.y: 90
            }



            Node {
                id: pivoteDelCoche

                x: scene.startX

                // AHORA: Propiedades para controlar el movimiento
                property real anchoCarril: 15.5 // Ajusta este valor para que el movimiento sea más o menos pronunciado

                // AHORA: Añadimos una animación para que el movimiento sea suave
                z: (anchoCarril * stateController.carPosition) - (anchoCarril / 2)

                // La animación suave sigue siendo una excelente idea
                Behavior on z {
                    enabled: !animLeft.running && !animRight.running && !animForward.running
                    NumberAnimation { duration: 200; easing.type: Easing.OutQuad }
                }

                PerspectiveCamera {
                    id: sceneCamera
                    x: 18
                    y: 19
                    fieldOfViewOrientation: PerspectiveCamera.Vertical
                    fieldOfView: 50
                    clipFar: 800
                    frustumCullingEnabled: false
                    eulerRotation.y: 90
                    eulerRotation.x: -30
                    z: 0
                }

                Car {
                    id: car
                    x: 6.435
                    y: 7
                    //position: Qt.vector3d(7, 6, 0)
                    z: 0.0
                }
            }

            Node {
                id: grupoMurosFijos
                Tabla { id: izq1; x: 1;   y: 0; z: 9 }
                Tabla { id: der1; x: 1;   y: 0; z: -9 }
            }

            Node {
                id: muroIzq
                visible: !stateController.sensorIzquierdo
                Tabla { id: izq2; x: -18; y:0; z: 9 }

            }

            Node {
                id: muroDer
                visible: !stateController.sensorDerecho
                Tabla { id: der2; x: -18; y:0; z: -9 }
            }

            Node {
                id: murosInterIzq
                visible: stateController.sensorIzquierdo
                Tabla { id: interIzq1; x: -10; y:0; z: 17.75; eulerRotation.y: 90 }
                Tabla { id: interIzq2; x: -27; y:0; z: 17.75; eulerRotation.y: 90 }
            }

            Node {
                id: murosInterDer
                visible: stateController.sensorDerecho
                Tabla { id: interDer1; x: -10; y:0; z: -17.75; eulerRotation.y: 90 }
                Tabla { id: interDer2; x: -27; y:0; z: -17.75; eulerRotation.y: 90 }
            }

            Node {
                id: muroFrente
                visible: stateController.sensorFrontal
                Tabla { id: endRoad; x: -27; y: 0; z: 0; eulerRotation.y: 90 }

            }

            Node {
                id: murosPasillo
                visible: !stateController.sensorFrontal
                // visible: stateController.sensorDerecho & stateController.sensorIzquierdo & !stateController.sensorFrontal
                Tabla { id: izq3; x: -38; y: 0; z: 9 }
                Tabla { id: der3; x: -38; y: 0; z: -9 }
            }

            Tabla {
                id: deadEnd
                visible: false
                x: -10
                y: -0
                z: -0.00001
                eulerRotation.y: 90
            }

            Piso {
                id: piso
                x: -19.318
                y: -0.651
                z: -0.37444
            }


        }
    }

    // --- NUEVO: Animaciones ---
    // --- VARIABLES DE CONFIGURACIÓN ---
        // Aumenta estos valores para que vaya más lento
        property int durationApproach: 1000  // Tiempo para llegar al centro
        property int durationTurn: 800       // Tiempo para girar
        property int durationExit: 1000      // Tiempo para avanzar en la nueva dirección

        // Distancia que avanza "hacia adentro" del nuevo pasillo antes de reiniciar
        property real exitDistance: 70

        // 1. Animación de Giro a la IZQUIERDA
        SequentialAnimation {
            id: animLeft
            // Paso A: Avanzar hasta la intersección
            NumberAnimation {
                target: pivoteDelCoche
                property: "x"
                to: scene.intersectionX
                duration: durationApproach
                easing.type: Easing.InOutQuad
            }
            // Paso B: Girar 90 grados
            NumberAnimation {
                target: pivoteDelCoche
                property: "eulerRotation.y"
                to: 90
                duration: durationTurn
                easing.type: Easing.InOutQuad
            }

            // PASO 3: Avanzar en la nueva dirección (Hacia la izquierda visual, que es Z positivo)
            NumberAnimation {
                target: pivoteDelCoche
                property: "z"
                to: exitDistance // Se aleja hacia el muro izquierdo
                duration: durationExit
                easing.type: Easing.InQuad // InQuad para que parezca que acelera al salir
            }

            // Paso C: Reset instantáneo (La magia)
            ScriptAction {
                script: {
                    // 1. Resetear posición física
                    pivoteDelCoche.x = scene.startX
                    pivoteDelCoche.eulerRotation.y = 0
                    pivoteDelCoche.z = 0
                    // 2. Avisar a C++ para que cambie los muros AHORA
                    rectangle.animationFinished ()
                }
            }
        }

        // 2. Animación de Giro a la DERECHA
        SequentialAnimation {
            id: animRight
            NumberAnimation {
                target: pivoteDelCoche
                property: "x"
                to: scene.intersectionX
                duration: durationApproach
                easing.type: Easing.InOutQuad
            }
            NumberAnimation {
                target: pivoteDelCoche
                property: "eulerRotation.y"
                to: -90
                duration: durationTurn
                easing.type: Easing.InOutQuad
            }

            NumberAnimation {
                target: pivoteDelCoche
                property: "z"
                to: -exitDistance
                duration: durationExit
                easing.type: Easing.InQuad
            }

            ScriptAction {
                script: {
                    pivoteDelCoche.x = scene.startX
                    pivoteDelCoche.z = 0
                    pivoteDelCoche.eulerRotation.y = 0
                    rectangle.animationFinished()
                }
            }
        }

        // 3. Animación de AVANZAR (Sin giro)
        SequentialAnimation {
            id: animForward
            // Avanzamos el doble de distancia para simular pasar al siguiente bloque
            NumberAnimation {
                target: pivoteDelCoche
                property: "x"
                to: scene.intersectionX - 40 // Va más allá de la intersección
                duration: durationApproach + durationExit
                easing.type: Easing.InOutQuad
            }
            ScriptAction {
                script: {
                    pivoteDelCoche.x = scene.startX
                    pivoteDelCoche.eulerRotation.y = 0

                    // 2. IMPORTANTE: Recuperar el binding de Z
                    // (Si no hacemos esto, el auto deja de responder a la posición lateral de los sensores)
                    pivoteDelCoche.z = Qt.binding(function() {
                        return (pivoteDelCoche.anchoCarril * stateController.carPosition) - (pivoteDelCoche.anchoCarril / 2)
                    })

                    rectangle.animationFinished()
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
                    text: (stateController.leftMotorPower * 100).toFixed(0) + "%"
                    font.pixelSize: 19
                    color: "#00FA9A" // Color verde
                    font.family: "Century Gothic"
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                }

                // Label estático
                Text {
                    text: "Left Power"
                    font.pixelSize: 14
                    color: "#a0a0a0" // Gris claro
                    font.family: "Century Gothic"
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
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
                    text: (stateController.rightMotorPower * 100).toFixed(0) + "%"
                    font.pixelSize: 19
                    color: "#00FA9A"
                    font.family: "Century Gothic"
                    font.bold: true
                    horizontalAlignment: Text.AlignRight
                    anchors.right: parent.right
                }

                // Label estático
                Text {
                    text: "Right Power"
                    font.pixelSize: 14
                    font.family: "Century Gothic"
                    font.bold: true
                    color: "#a0a0a0"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }
    }

    states: [
        State {
            name: "clicked"
        }
    ]

    // --- CÓDIGO TEMPORAL DE PRUEBA ---
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onClicked: (mouse) => {
                if (mouse.button === Qt.LeftButton) {
                    console.log("Prueba manual: Giro Izquierda");
                    stateController.triggerTurnLeft();
                } else if (mouse.button === Qt.RightButton) {
                    console.log("Prueba manual: Giro Derecha");
                    stateController.triggerTurnRight();
                } else if (mouse.button === Qt.MiddleButton) {
                    console.log("Prueba manual: Avanzar");
                    stateController.triggerMoveForward();
                }
            }

            onDoubleClicked: {
                console.log("Prueba manual: Avanzar");
                stateController.triggerMoveForward();
            }
        }
}

/*##^##
Designer {
    D{i:0;matPrevEnvDoc:"SkyBox";matPrevEnvValueDoc:"preview_studio";matPrevModelDoc:"#Sphere"}
D{i:8;cameraSpeed3d:1;cameraSpeed3dMultiplier:1}
}
##^##*/
