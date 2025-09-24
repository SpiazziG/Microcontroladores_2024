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

Rectangle {
    id: rectangle
    anchors.fill: parent
    color: "transparent"

    Item {
        id: __materialLibrary__

        PrincipledMaterial {
            id: principledMaterial
            objectName: "New Material"
        }
    }

    View3D {
        id: view3D
        anchors.fill: parent;
        environment: sceneEnvironment
        SceneEnvironment {
            id: sceneEnvironment
            aoEnabled: false
            clearColor: "#232729"
            backgroundMode: SceneEnvironment.Color
            antialiasingQuality: SceneEnvironment.High
            antialiasingMode: SceneEnvironment.MSAA
        }

        Node {
            id: scene
            DirectionalLight {
                id: directionalLight
                x: -15
                y: 5
                eulerRotation.x: -23
                z: 0
                eulerRotation.y: -90
            }

            PerspectiveCamera {
                id: sceneCamera
                x: -16.5
                y: 3.4
                eulerRotation.y: -90
                eulerRotation.x: -20
                z: 0
            }

            Node {
                id: pivoteDelCoche
                // Este nodo está en el centro (0,0,0) de la escena por defecto

                // 2. METEMOS EL COCHE DENTRO Y AJUSTAMOS SU POSICIÓN
                Car {
                    id: car
                    x: 0
                    eulerRotation.z: 0
                    // 4. AHORA AJUSTAMOS LA POSICIÓN DEL COCHE PARA CENTRARLO VISUALMENTE
                    // Tendrás que experimentar con estos valores. Si el coche orbita
                    // hacia la derecha, prueba con un valor negativo en X, y viceversa.
                    position: Qt.vector3d(7, 0, 0) // <--- ¡VALOR DE EJEMPLO! AJÚSTALO
                }
            }

            NumberAnimation {
                target: pivoteDelCoche // <-- ¡CAMBIO IMPORTANTE!
                property: "eulerRotation.y"
                from: 0
                to: -360
                duration: 24000
                loops: Animation.Infinite
                running: true
            }
        }
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}

/*##^##
Designer {
    D{i:0;matPrevEnvDoc:"SkyBox";matPrevEnvValueDoc:"preview_studio";matPrevModelDoc:"#Sphere"}
D{i:5;cameraSpeed3d:25;cameraSpeed3dMultiplier:1}
}
##^##*/
