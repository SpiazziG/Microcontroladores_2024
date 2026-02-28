import QtQuick
import QtQuick3D

Node {
    id: node

    // Resources
    PrincipledMaterial {
        id: cauchoVerde1_material
        objectName: "CauchoVerde1"
        baseColor: "#ff6b3f1d"
        roughness: 0.75
    }

    // Nodes:
    Node {
        id: rootNode
        objectName: "RootNode"
        Model {
            id: madera
            objectName: "Madera"
            rotation: Qt.quaternion(0.707107, -0.707107, 0, 0)
            source: "meshes/madera_mesh.mesh"
            materials: [
                cauchoVerde1_material
            ]
        }
    }

    // Animations:
}
