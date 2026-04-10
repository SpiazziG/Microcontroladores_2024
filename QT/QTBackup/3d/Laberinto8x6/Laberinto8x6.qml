import QtQuick
import QtQuick3D

Node {
    id: node

    // Resources
    PrincipledMaterial {
        id: smoothIvory_material
        objectName: "SmoothIvory"
        baseColor: "#ffeeeec9"
        roughness: 0.800000011920929
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }
    PrincipledMaterial {
        id: rubberBlack_material
        objectName: "RubberBlack"
        baseColor: "#ff0d0d0d"
        roughness: 0.75
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }

    // Nodes:
    Node {
        id: root
        objectName: "ROOT"
        Node {
            id: tablaPiso8x6_1
            objectName: "TablaPiso8x6:1"
            z: 3.944304526105059e-31
            rotation: Qt.quaternion(1, -4.85723e-17, 1.66533e-16, -8.32667e-17)
            Model {
                id: s_lido1
                objectName: "Sólido1"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_mesh.mesh"
                materials: [
                    smoothIvory_material
                ]
            }
        }
        Node {
            id: cintas8x6_1
            objectName: "Cintas8x6:1"
            x: 1.0658141459917976e-15
            y: 0.017999999225139618
            z: 1.776356799695581e-17
            rotation: Qt.quaternion(1, -4.85723e-17, -7.80151e-17, 1.93911e-32)
            Model {
                id: s_lido17
                objectName: "Sólido1"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_mesh8.mesh"
                materials: [
                    rubberBlack_material
                ]
            }
        }
    }

    // Animations:
}
