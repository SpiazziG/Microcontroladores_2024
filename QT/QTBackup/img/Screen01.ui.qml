/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick
import QtQuick.Controls

Item {
    id: screen

    property bool sensorFrontal: false // El Frontal está invertido
    property bool sensorIzquierdo: true
    property bool sensorDerecho: true
    property real leftMotorPower: 0.0 // Ejemplo: 25%
    property real rightMotorPower: 0.0 // Ejemplo: 75%
    property real carPosition: 0.5 // 0.0 = Izq, 0.5 = Cen, 1.0 = Der

    Rectangle {
        anchors.fill: parent
        color: "#212528"
    }

    Item {
        id: roadContainer
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: powerBar.top

        Image {
            id: currentRoad
            source: "road.svg"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width * 0.4
            fillMode: Image.Stretch
        }

        Image {
            id: rightRoad
            source: "rightRoad.svg"
            visible: screen.sensorDerecho
            anchors.bottom: currentRoad.verticalCenter
            anchors.left: currentRoad.horizontalCenter
            anchors.right: parent.right
            height: currentRoad.height * 0.25
            fillMode: Image.Stretch
        }

        Image {
            id: leftRoad
            source: "leftRoad.svg"
            visible: screen.sensorIzquierdo
            anchors.bottom: currentRoad.verticalCenter
            anchors.left: parent.left
            anchors.right: currentRoad.horizontalCenter
            height: currentRoad.height * 0.25
            fillMode: Image.Stretch
        }

        Image {
            id: frontRoad
            source: "frontRoad.svg"
            visible: screen.sensorFrontal
            anchors.top: currentRoad.top
            anchors.bottom: rightRoad.top
            anchors.horizontalCenter: currentRoad.horizontalCenter
            width: currentRoad.width
            fillMode: Image.Stretch
        }

        Image {
            id: car
            source: "carShape.svg"
            width: currentRoad.width * 0.45
            fillMode: Image.PreserveAspectFit
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 30
            x: (currentRoad.x + (currentRoad.width * screen.carPosition)) - (width / 2)
        }
    }

    Rectangle {
        id: powerBar
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: parent.height * 0.15 // Un poco más de altura para que quepa bien el texto
        color: "#22262a"
        border.color: "#22262a"

        Rectangle {
            // Un rectángulo delgado que actúa como nuestro borde.
            width: parent.width // Ocupa todo el ancho del padre (powerBar)
            height: 2           // 1 píxel de grosor
            color: "#393F44"       // El color que tenía el borde antes

            // Lo anclamos a la parte superior del padre.
            anchors.top: parent.top
        }

        // --- CONTENEDOR PARA LA INFORMACIÓN IZQUIERDA ---
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
                    text: (screen.leftMotorPower * 100).toFixed(0) + "%"
                    font.pixelSize: 18
                    color: "#00FA9A" // Color verde
                    font.family: "Siemens Sans"
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                }

                // Label estático
                Text {
                    text: "Left Power"
                    font.pixelSize: 14
                    color: "#a0a0a0" // Gris claro
                    font.family: "Siemens Sans"
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                }
            }
        }

        // --- CONTENEDOR PARA LA INFORMACIÓN DERECHA ---
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
                    text: (screen.rightMotorPower * 100).toFixed(0) + "%"
                    font.pixelSize: 18
                    color: "#00FA9A"
                    font.family: "Siemens Sans"
                    font.bold: true
                    horizontalAlignment: Text.AlignRight
                    anchors.right: parent.right
                }

                // Label estático
                Text {
                    text: "Right Power"
                    font.pixelSize: 14
                    font.family: "Siemens Sans"
                    font.bold: true
                    color: "#a0a0a0"
                    horizontalAlignment: Text.AlignRight
                }
            }
        }
    }
}
