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
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }

    // Nodes:
    Model {
        id: madera
        objectName: "Madera"
        scale.x: 0.01
        scale.y: 0.01
        scale.z: 0.01
        source: "meshes/madera_mesh.mesh"
        materials: [
            cauchoVerde1_material
        ]
    }

    // Animations:
}
