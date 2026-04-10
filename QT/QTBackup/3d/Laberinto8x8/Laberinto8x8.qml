import QtQuick
import QtQuick3D

Node {
    id: node

    // Resources
    PrincipledMaterial {
        id: cauchoVerde2_material
        objectName: "CauchoVerde2"
        baseColor: "#ffe5e5e5"
        roughness: 0.75
        cullMode: PrincipledMaterial.NoCulling
        alphaMode: PrincipledMaterial.Opaque
    }
    PrincipledMaterial {
        id: cauchoVerde1_material
        objectName: "CauchoVerde1"
        baseColor: "#ff6b3f1d"
        roughness: 0.75
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
            id: tablaSuelo_1
            objectName: "TablaSuelo:1"
            x: -0.019439665600657463
            y: -0.017511818557977676
            z: 5.684341759025859e-16
            Model {
                id: madera
                objectName: "Madera"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/madera_mesh.mesh"
                materials: [
                    cauchoVerde2_material,
                    cauchoVerde1_material
                ]
            }
        }
        Node {
            id: cintaPiso_1
            objectName: "CintaPiso:1"
            x: -0.019439665600657463
            y: -0.003761819563806057
            z: 5.684341759025859e-16
            rotation: Qt.quaternion(1, 0, -9.53749e-17, 0)
            Model {
                id: s_lido1
                objectName: "Sólido1"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_mesh.mesh"
                materials: [
                    rubberBlack_material
                ]
            }
        }
    }

    // Animations:
}
