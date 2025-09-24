import QtQuick
import QtQuick3D

Node {
    id: node

    // Resources
    Texture {
        id: __texture
        objectName: "."
        pivotU: 0.5
        pivotV: 0.5
        positionV: 0.9876968264579773
        scaleU: 81.27999877929688
        scaleV: 81.27999877929688
        generateMipmaps: true
        mipFilter: Texture.Linear
        // source: "maps/."
    }
    Texture {
        id: __texture756
        objectName: "."
        pivotU: 0.5
        pivotV: 0.5
        positionU: 0.001312335953116417
        positionV: 1
        rotationUV: 90
        scaleU: 127
        scaleV: 762
        generateMipmaps: true
        mipFilter: Texture.Linear
        // source: "maps/."
    }

    // Nodes:
    Node {
        id: rootNode
        objectName: "RootNode"
        Node {
            id: node1x8_Male_Pin_Header_1
            objectName: "1x8 Male Pin Header:1"
            x: -7.691983699798584
            y: 0.33592039346694946
            z: 0.877501368522644
            rotation: Qt.quaternion(0.5, 0.5, 0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_042
                objectName: "Sólido1.042"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_022_mesh.mesh"
                materials: [
                    m247224153_material
                ]
            }
            Model {
                id: s_lido2_025
                objectName: "Sólido2.025"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_013_mesh.mesh"
                materials: [
                    m247224153_material
                ]
            }
            Model {
                id: s_lido3_025
                objectName: "Sólido3.025"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_013_mesh.mesh"
                materials: [
                    m247224153_material
                ]
            }
            Model {
                id: s_lido4_021
                objectName: "Sólido4.021"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_012_mesh.mesh"
                materials: [
                    m247224153_material
                ]
            }
            Model {
                id: s_lido5_021
                objectName: "Sólido5.021"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_012_mesh.mesh"
                materials: [
                    m247224153_material
                ]
            }
            Model {
                id: s_lido6_021
                objectName: "Sólido6.021"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_012_mesh.mesh"
                materials: [
                    m247224153_material
                ]
            }
            Model {
                id: s_lido7_020
                objectName: "Sólido7.020"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_011_mesh.mesh"
                materials: [
                    m247224153_material
                ]
            }
            Model {
                id: s_lido8_012
                objectName: "Sólido8.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_010_mesh.mesh"
                materials: [
                    m247224153_material
                ]
            }
            Model {
                id: s_lido9_012
                objectName: "Sólido9.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_010_mesh.mesh"
                materials: [
                    m262626_material
                ]
            }
        }
        Node {
            id: as_1427__8____M_trico_M2_x_10_1
            objectName: "AS 1427 (8) - Métrico M2 x 10:1"
            x: -9.515167236328125
            y: 0.6529204249382019
            z: -1.082550048828125
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_016
                objectName: "Solid1.016"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_006_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1427__8____M_trico_M2_x_10_2
            objectName: "AS 1427 (8) - Métrico M2 x 10:2"
            x: -9.515167236328125
            y: 0.6529204249382019
            z: 1.0574499368667603
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_018
                objectName: "Solid1.018"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_006_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1427__8____M_trico_M2_5_x_8_1
            objectName: "AS 1427 (8) - Métrico M2,5 x 8:1"
            x: -8.906272888183594
            y: 0.4959203898906708
            z: 0.8019000291824341
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_020
                objectName: "Solid1.020"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_007_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1427__8____M_trico_M2_5_x_8_2
            objectName: "AS 1427 (8) - Métrico M2,5 x 8:2"
            x: -8.906272888183594
            y: 0.4959203898906708
            z: -0.798099935054779
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_022
                objectName: "Solid1.022"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_007_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1427__8____M_trico_M3_x_50_1
            objectName: "AS 1427 (8) - Métrico M3 x 50:1"
            x: -5.081273078918457
            y: 0.19292038679122925
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_008
                objectName: "Solid1.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_002_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1427__8____M_trico_M3_x_50_2
            objectName: "AS 1427 (8) - Métrico M3 x 50:2"
            x: -5.081273078918457
            y: 0.19292038679122925
            z: -2.598099946975708
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_010
                objectName: "Solid1.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_002_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M2_5_1
            objectName: "AS 1474 - Métrico M2,5:1"
            x: -8.906272888183594
            y: -0.05707961320877075
            z: 0.8019000291824341
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_021
                objectName: "Solid1.021"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_008_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M2_5_2
            objectName: "AS 1474 - Métrico M2,5:2"
            x: -8.906272888183594
            y: -0.05707961320877075
            z: -0.798099935054779
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_023
                objectName: "Solid1.023"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_008_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M2_1
            objectName: "AS 1474 - Métrico M2:1"
            x: -2.781273126602173
            y: -3.557079553604126
            z: 1.6018999814987183
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_001
                objectName: "Solid1.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_001_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M2_2
            objectName: "AS 1474 - Métrico M2:2"
            x: -4.681272983551025
            y: -3.557079553604126
            z: 1.6018999814987183
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_003
                objectName: "Solid1.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_001_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M2_3
            objectName: "AS 1474 - Métrico M2:3"
            x: -2.781273126602173
            y: -3.557079553604126
            z: -1.598099946975708
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_005
                objectName: "Solid1.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_001_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M2_4
            objectName: "AS 1474 - Métrico M2:4"
            x: -4.681272983551025
            y: -3.557079553604126
            z: -1.598099946975708
            rotation: Qt.quaternion(-0.5, 0.5, 0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_007
                objectName: "Solid1.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_001_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M2_5
            objectName: "AS 1474 - Métrico M2:5"
            x: -9.515167236328125
            y: -0.05707961320877075
            z: -1.082550048828125
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_017
                objectName: "Solid1.017"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_001_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M2_6
            objectName: "AS 1474 - Métrico M2:6"
            x: -9.515167236328125
            y: -0.05707961320877075
            z: 1.0574499368667603
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_019
                objectName: "Solid1.019"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_001_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M3_1
            objectName: "AS 1474 - Métrico M3:1"
            x: -5.081273078918457
            y: -3.7170796394348145
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_009
                objectName: "Solid1.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_003_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: as_1474___M_trico_M3_2
            objectName: "AS 1474 - Métrico M3:2"
            x: -5.081273078918457
            y: -3.7170796394348145
            z: -2.598099946975708
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_011
                objectName: "Solid1.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_003_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: arandelaDisplay_1
            objectName: "ArandelaDisplay:1"
            x: -9.515167236328125
            y: 0.3429203927516937
            z: 1.0574499368667603
            rotation: Qt.quaternion(0.5, -0.5, 0.5, 0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_043
                objectName: "Sólido1.043"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_023_mesh.mesh"
                materials: [
                    black_material
                ]
            }
        }
        Node {
            id: arandelaDisplay_2
            objectName: "ArandelaDisplay:2"
            x: -9.515167236328125
            y: 0.3429203927516937
            z: -1.082550048828125
            rotation: Qt.quaternion(0.5, -0.5, -0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_044
                objectName: "Sólido1.044"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_023_mesh.mesh"
                materials: [
                    black_material
                ]
            }
        }
        Node {
            id: battery_HOLDER
            objectName: "BATTERY HOLDER"
            x: -4.82377290725708
            y: 0.44292038679122925
            z: 0.0018999999156221747
            rotation: Qt.quaternion(3.09086e-08, 0.707107, 3.09086e-08, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_008
                objectName: "Sólido1.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_005_mesh.mesh"
                materials: [
                    m515151_material
                ]
            }
            Model {
                id: s_lido10_002
                objectName: "Sólido10.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_001_mesh.mesh"
                materials: [
                    m20417082_material
                ]
            }
            Model {
                id: s_lido11_002
                objectName: "Sólido11.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_002_mesh.mesh"
                materials: [
                    smoothPurple_material,
                    m100153100_material,
                    m128128128_material
                ]
            }
            Model {
                id: s_lido2_002
                objectName: "Sólido2.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_001_mesh.mesh"
                materials: [
                    m189198204_material
                ]
            }
            Model {
                id: s_lido3_002
                objectName: "Sólido3.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_001_mesh.mesh"
                materials: [
                    m189198204_material
                ]
            }
            Model {
                id: s_lido4_002
                objectName: "Sólido4.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_001_mesh.mesh"
                materials: [
                    m189198204_material
                ]
            }
            Model {
                id: s_lido5_002
                objectName: "Sólido5.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_001_mesh.mesh"
                materials: [
                    m189198204_material
                ]
            }
            Model {
                id: s_lido6_002
                objectName: "Sólido6.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_002_mesh.mesh"
                materials: [
                    smoothPurple_material,
                    m100153100_material,
                    m128128128_material
                ]
            }
            Model {
                id: s_lido7_002
                objectName: "Sólido7.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_001_mesh.mesh"
                materials: [
                    m20417082_material
                ]
            }
            Model {
                id: s_lido8_002
                objectName: "Sólido8.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_001_mesh.mesh"
                materials: [
                    m20417082_material
                ]
            }
            Model {
                id: s_lido9_002
                objectName: "Sólido9.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_001_mesh.mesh"
                materials: [
                    m20417082_material
                ]
            }
        }
        Node {
            id: bluepill
            objectName: "Bluepill"
            x: -9.764272689819336
            y: -2.4575889110565186
            z: -2.666261672973633
            rotation: Qt.quaternion(-3.09086e-08, -3.09086e-08, 0.707107, 0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_020
                objectName: "Sólido1.020"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_012_mesh.mesh"
                materials: [
                    m245245246_material
                ]
            }
            Model {
                id: s_lido10_005
                objectName: "Sólido10.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_004_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido100
                objectName: "Sólido100"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido100_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido101
                objectName: "Sólido101"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido101_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido102
                objectName: "Sólido102"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido102_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido103
                objectName: "Sólido103"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido103_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido104
                objectName: "Sólido104"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido104_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido105
                objectName: "Sólido105"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido105_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido106
                objectName: "Sólido106"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido106_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido107
                objectName: "Sólido107"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido107_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido108
                objectName: "Sólido108"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido108_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido11_005
                objectName: "Sólido11.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_004_mesh.mesh"
                materials: [
                    m252525_material
                ]
            }
            Model {
                id: s_lido12_004
                objectName: "Sólido12.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_003_mesh.mesh"
                materials: [
                    m252525_material
                ]
            }
            Model {
                id: s_lido13_004
                objectName: "Sólido13.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_003_mesh.mesh"
                materials: [
                    m252525_material
                ]
            }
            Model {
                id: s_lido14_004
                objectName: "Sólido14.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido15_004
                objectName: "Sólido15.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido16_004
                objectName: "Sólido16.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido17_004
                objectName: "Sólido17.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido18_004
                objectName: "Sólido18.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido19_004
                objectName: "Sólido19.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido2_005
                objectName: "Sólido2.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_004_mesh.mesh"
                materials: [
                    m4859150_001_material
                ]
            }
            Model {
                id: s_lido20_004
                objectName: "Sólido20.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido21_004
                objectName: "Sólido21.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido22_004
                objectName: "Sólido22.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido23_004
                objectName: "Sólido23.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido24_004
                objectName: "Sólido24.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido25_004
                objectName: "Sólido25.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido26_004
                objectName: "Sólido26.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido27_004
                objectName: "Sólido27.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido28_004
                objectName: "Sólido28.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido29_004
                objectName: "Sólido29.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido3_005
                objectName: "Sólido3.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_004_mesh.mesh"
                materials: [
                    m252525_material
                ]
            }
            Model {
                id: s_lido30_004
                objectName: "Sólido30.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_003_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido31_004
                objectName: "Sólido31.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido32_004
                objectName: "Sólido32.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_003_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido33_002
                objectName: "Sólido33.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido33_002_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido34_002
                objectName: "Sólido34.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido34_002_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido35_002
                objectName: "Sólido35.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido35_002_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido36_002
                objectName: "Sólido36.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido36_002_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido37_001
                objectName: "Sólido37.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido37_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido38_001
                objectName: "Sólido38.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido38_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido39_001
                objectName: "Sólido39.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido39_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido4_005
                objectName: "Sólido4.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_004_mesh.mesh"
                materials: [
                    m252525_material
                ]
            }
            Model {
                id: s_lido40_001
                objectName: "Sólido40.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido40_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido41_001
                objectName: "Sólido41.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido41_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido42_001
                objectName: "Sólido42.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido42_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido43_001
                objectName: "Sólido43.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido43_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido44_001
                objectName: "Sólido44.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido44_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido45_001
                objectName: "Sólido45.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido45_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido46_001
                objectName: "Sólido46.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido46_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido47_001
                objectName: "Sólido47.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido47_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido48_001
                objectName: "Sólido48.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido48_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido49_001
                objectName: "Sólido49.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido49_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido5_005
                objectName: "Sólido5.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_004_mesh.mesh"
                materials: [
                    m252525_material
                ]
            }
            Model {
                id: s_lido50_001
                objectName: "Sólido50.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido50_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido51_001
                objectName: "Sólido51.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido51_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido52_001
                objectName: "Sólido52.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido52_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido53_001
                objectName: "Sólido53.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido53_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido54_001
                objectName: "Sólido54.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido54_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido55_001
                objectName: "Sólido55.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido55_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido56_001
                objectName: "Sólido56.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido56_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido57_001
                objectName: "Sólido57.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido57_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido58_001
                objectName: "Sólido58.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido58_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido59_001
                objectName: "Sólido59.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido59_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido6_005
                objectName: "Sólido6.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_004_mesh.mesh"
                materials: [
                    m252525_material
                ]
            }
            Model {
                id: s_lido60_001
                objectName: "Sólido60.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido60_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido61_001
                objectName: "Sólido61.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido61_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido62_001
                objectName: "Sólido62.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido62_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido63_001
                objectName: "Sólido63.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido63_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido64_001
                objectName: "Sólido64.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido64_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido65_001
                objectName: "Sólido65.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido65_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido66_001
                objectName: "Sólido66.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido66_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido67_001
                objectName: "Sólido67.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido67_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido68_001
                objectName: "Sólido68.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido68_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido69_001
                objectName: "Sólido69.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido69_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido7_005
                objectName: "Sólido7.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_005_mesh.mesh"
                materials: [
                    m646464_material,
                    m1921920_material,
                    m192192192_material
                ]
            }
            Model {
                id: s_lido70_001
                objectName: "Sólido70.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido70_001_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido71_001
                objectName: "Sólido71.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido71_001_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido72
                objectName: "Sólido72"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido72_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido73
                objectName: "Sólido73"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido73_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido74
                objectName: "Sólido74"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido74_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido75
                objectName: "Sólido75"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido75_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido76
                objectName: "Sólido76"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido76_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido77
                objectName: "Sólido77"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido77_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido78
                objectName: "Sólido78"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido78_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido79
                objectName: "Sólido79"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido79_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido8_005
                objectName: "Sólido8.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_004_mesh.mesh"
                materials: [
                    m160160160_material
                ]
            }
            Model {
                id: s_lido80
                objectName: "Sólido80"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido80_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido81
                objectName: "Sólido81"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido81_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido82
                objectName: "Sólido82"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido82_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido83
                objectName: "Sólido83"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido83_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido84
                objectName: "Sólido84"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido84_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido85
                objectName: "Sólido85"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido85_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido86
                objectName: "Sólido86"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido86_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido87
                objectName: "Sólido87"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido87_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido88
                objectName: "Sólido88"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido88_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido89
                objectName: "Sólido89"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido89_mesh.mesh"
                materials: [
                    m23217335_material
                ]
            }
            Model {
                id: s_lido9_005
                objectName: "Sólido9.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_004_mesh.mesh"
                materials: [
                    m252525_material
                ]
            }
            Model {
                id: s_lido90
                objectName: "Sólido90"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido90_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido91
                objectName: "Sólido91"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido91_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido92
                objectName: "Sólido92"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido92_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido93
                objectName: "Sólido93"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido93_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido94
                objectName: "Sólido94"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido94_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido95
                objectName: "Sólido95"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido95_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido96
                objectName: "Sólido96"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido96_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido97
                objectName: "Sólido97"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido97_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido98
                objectName: "Sólido98"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido98_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
            Model {
                id: s_lido99
                objectName: "Sólido99"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido99_mesh.mesh"
                materials: [
                    m243203124_material
                ]
            }
        }
        Node {
            id: bracketV2_1
            objectName: "BracketV2:1"
            x: -3.7562732696533203
            y: -3.7170796394348145
            z: 1.6018999814987183
            rotation: Qt.quaternion(0.5, 0.5, 0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1
                objectName: "Sólido1"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_mesh.mesh"
                materials: [
                    smoothMediumGray_material
                ]
            }
        }
        Node {
            id: bracketV2_2
            objectName: "BracketV2:2"
            x: -3.7562732696533203
            y: -3.7056915760040283
            z: -1.5975180864334106
            rotation: Qt.quaternion(-0.497882, -0.502109, 0.50211, -0.497881)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_004
                objectName: "Sólido1.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_mesh.mesh"
                materials: [
                    smoothMediumGray_material
                ]
            }
        }
        Node {
            id: chasisV1_1
            objectName: "ChasisV1:1"
            x: -7.531273365020752
            y: -0.05707961320877075
            z: 0.0018999999156221747
            rotation: Qt.quaternion(0.707107, -0.707107, 0, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_011
                objectName: "Sólido1.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_008_mesh.mesh"
                materials: [
                    gray_material
                ]
            }
        }
        Node {
            id: d_SUN_dcdc_step_down_SIMPLE_1
            objectName: "D-SUN_dcdc_step_down_SIMPLE:1"
            x: -6.761173248291016
            y: -3.1700797080993652
            z: -4.046080112457275
            rotation: Qt.quaternion(4.37114e-08, 0, 1, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_035
                objectName: "Sólido1.035"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_035_mesh.mesh"
                materials: [
                    m2210716_material,
                    m204204204_003_material
                ]
            }
            Model {
                id: s_lido10_011
                objectName: "Sólido10.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_009_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido11_011
                objectName: "Sólido11.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_009_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido12_010
                objectName: "Sólido12.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_008_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido13_010
                objectName: "Sólido13.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_008_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido14_010
                objectName: "Sólido14.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_008_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido15_010
                objectName: "Sólido15.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_008_mesh.mesh"
                materials: [
                    m231231231_material
                ]
            }
            Model {
                id: s_lido16_010
                objectName: "Sólido16.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_008_mesh.mesh"
                materials: [
                    m231231231_material
                ]
            }
            Model {
                id: s_lido17_010
                objectName: "Sólido17.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_008_mesh.mesh"
                materials: [
                    m231231231_material
                ]
            }
            Model {
                id: s_lido18_010
                objectName: "Sólido18.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_008_mesh.mesh"
                materials: [
                    m231231231_material
                ]
            }
            Model {
                id: s_lido19_010
                objectName: "Sólido19.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_008_mesh.mesh"
                materials: [
                    m231231231_material
                ]
            }
            Model {
                id: s_lido2_020
                objectName: "Sólido2.020"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_012_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido20_010
                objectName: "Sólido20.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_008_mesh.mesh"
                materials: [
                    m231231231_material
                ]
            }
            Model {
                id: s_lido21_010
                objectName: "Sólido21.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_008_mesh.mesh"
                materials: [
                    m231231231_material
                ]
            }
            Model {
                id: s_lido22_008
                objectName: "Sólido22.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_007_mesh.mesh"
                materials: [
                    m231231231_material
                ]
            }
            Model {
                id: s_lido23_008
                objectName: "Sólido23.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido24_008
                objectName: "Sólido24.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido25_008
                objectName: "Sólido25.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido26_008
                objectName: "Sólido26.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido27_008
                objectName: "Sólido27.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido28_008
                objectName: "Sólido28.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido29_008
                objectName: "Sólido29.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido3_020
                objectName: "Sólido3.020"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_012_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido30_008
                objectName: "Sólido30.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido31_008
                objectName: "Sólido31.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido32_008
                objectName: "Sólido32.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_007_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido33_006
                objectName: "Sólido33.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido33_006_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido34_006
                objectName: "Sólido34.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido34_006_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido35_006
                objectName: "Sólido35.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido35_006_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido36_006
                objectName: "Sólido36.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido36_006_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido37_005
                objectName: "Sólido37.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido37_005_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido38_005
                objectName: "Sólido38.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido38_005_mesh.mesh"
                materials: [
                    m255255255_material,
                    m202020_material
                ]
            }
            Model {
                id: s_lido39_005
                objectName: "Sólido39.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido39_005_mesh.mesh"
                materials: [
                    m204204204_003_material,
                    m1065540_material
                ]
            }
            Model {
                id: s_lido4_016
                objectName: "Sólido4.016"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_011_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido40_005
                objectName: "Sólido40.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido40_005_mesh.mesh"
                materials: [
                    m404040_material,
                    m204204204_003_material
                ]
            }
            Model {
                id: s_lido41_005
                objectName: "Sólido41.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido41_005_mesh.mesh"
                materials: [
                    m255255255_material,
                    m202020_material
                ]
            }
            Model {
                id: s_lido42_005
                objectName: "Sólido42.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido42_005_mesh.mesh"
                materials: [
                    m255255255_material,
                    m202020_material
                ]
            }
            Model {
                id: s_lido43_005
                objectName: "Sólido43.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido43_005_mesh.mesh"
                materials: [
                    m255255255_material,
                    m204204204_003_material
                ]
            }
            Model {
                id: s_lido44_005
                objectName: "Sólido44.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido44_005_mesh.mesh"
                materials: [
                    m404040_material,
                    m204204204_003_material
                ]
            }
            Model {
                id: s_lido45_005
                objectName: "Sólido45.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido45_005_mesh.mesh"
                materials: [
                    m204204204_003_material,
                    m1065540_material
                ]
            }
            Model {
                id: s_lido46_005
                objectName: "Sólido46.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido46_005_mesh.mesh"
                materials: [
                    m204204204_003_material,
                    m1065540_material
                ]
            }
            Model {
                id: s_lido47_005
                objectName: "Sólido47.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido47_005_mesh.mesh"
                materials: [
                    m232239160_material,
                    m204204204_003_material
                ]
            }
            Model {
                id: s_lido48_005
                objectName: "Sólido48.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido48_005_mesh.mesh"
                materials: [
                    m204204204_003_material,
                    m1065540_material
                ]
            }
            Model {
                id: s_lido49_005
                objectName: "Sólido49.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido49_005_mesh.mesh"
                materials: [
                    m118118118_material,
                    m404040_material,
                    m204204204_003_material
                ]
            }
            Model {
                id: s_lido5_016
                objectName: "Sólido5.016"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_011_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido50_005
                objectName: "Sólido50.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido50_005_mesh.mesh"
                materials: [
                    m255255255_material,
                    m202020_material
                ]
            }
            Model {
                id: s_lido51_005
                objectName: "Sólido51.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido51_005_mesh.mesh"
                materials: [
                    m255255255_material,
                    m202020_material
                ]
            }
            Model {
                id: s_lido52_005
                objectName: "Sólido52.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido52_005_mesh.mesh"
                materials: [
                    m204204204_003_material,
                    m1065540_material
                ]
            }
            Model {
                id: s_lido6_016
                objectName: "Sólido6.016"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_011_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido7_015
                objectName: "Sólido7.015"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_010_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido8_011
                objectName: "Sólido8.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_009_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
            Model {
                id: s_lido9_011
                objectName: "Sólido9.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_009_mesh.mesh"
                materials: [
                    m255255255_material
                ]
            }
        }
        Node {
            id: esp_01S__ESP8266__Board_Module_1
            objectName: "ESP-01S (ESP8266) Board Module:1"
            x: -5.61012077331543
            y: -2.4679086208343506
            z: 2.418330192565918
            rotation: Qt.quaternion(4.37114e-08, 0, 0, 1)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_024
                objectName: "Sólido1.024"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_016_mesh.mesh"
                materials: [
                    m333333_material
                ]
            }
            Model {
                id: s_lido10_008
                objectName: "Sólido10.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_007_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido100_002
                objectName: "Sólido100.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido100_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido101_002
                objectName: "Sólido101.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido101_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido102_002
                objectName: "Sólido102.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido102_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido103_002
                objectName: "Sólido103.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido103_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido104_002
                objectName: "Sólido104.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido104_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido11_008
                objectName: "Sólido11.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_007_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido12_007
                objectName: "Sólido12.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_006_mesh.mesh"
                materials: [
                    m333333_material
                ]
            }
            Model {
                id: s_lido13_007
                objectName: "Sólido13.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido14_007
                objectName: "Sólido14.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido15_007
                objectName: "Sólido15.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido16_007
                objectName: "Sólido16.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido17_007
                objectName: "Sólido17.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido18_007
                objectName: "Sólido18.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido19_007
                objectName: "Sólido19.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido2_009
                objectName: "Sólido2.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_008_mesh.mesh"
                materials: [
                    m244229167_material
                ]
            }
            Model {
                id: s_lido20_007
                objectName: "Sólido20.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido21_007
                objectName: "Sólido21.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido22_007
                objectName: "Sólido22.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido23_007
                objectName: "Sólido23.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido24_007
                objectName: "Sólido24.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido25_007
                objectName: "Sólido25.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido26_007
                objectName: "Sólido26.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido27_007
                objectName: "Sólido27.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido28_007
                objectName: "Sólido28.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido29_007
                objectName: "Sólido29.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido3_009
                objectName: "Sólido3.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_008_mesh.mesh"
                materials: [
                    m333333_material
                ]
            }
            Model {
                id: s_lido30_007
                objectName: "Sólido30.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido31_007
                objectName: "Sólido31.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido32_007
                objectName: "Sólido32.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_006_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido33_005
                objectName: "Sólido33.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido33_005_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido34_005
                objectName: "Sólido34.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido34_005_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido35_005
                objectName: "Sólido35.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido35_005_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido36_005
                objectName: "Sólido36.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido36_005_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido37_004
                objectName: "Sólido37.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido37_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido38_004
                objectName: "Sólido38.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido38_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido39_004
                objectName: "Sólido39.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido39_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido4_009
                objectName: "Sólido4.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_008_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido40_004
                objectName: "Sólido40.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido40_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido41_004
                objectName: "Sólido41.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido41_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido42_004
                objectName: "Sólido42.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido42_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido43_004
                objectName: "Sólido43.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido43_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido44_004
                objectName: "Sólido44.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido44_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido45_004
                objectName: "Sólido45.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido45_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido46_004
                objectName: "Sólido46.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido46_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido47_004
                objectName: "Sólido47.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido47_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido48_004
                objectName: "Sólido48.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido48_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido49_004
                objectName: "Sólido49.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido49_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido5_009
                objectName: "Sólido5.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_008_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido50_004
                objectName: "Sólido50.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido50_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido51_004
                objectName: "Sólido51.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido51_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido52_004
                objectName: "Sólido52.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido52_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido53_004
                objectName: "Sólido53.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido53_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido54_004
                objectName: "Sólido54.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido54_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido55_004
                objectName: "Sólido55.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido55_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido56_004
                objectName: "Sólido56.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido56_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido57_004
                objectName: "Sólido57.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido57_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido58_004
                objectName: "Sólido58.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido58_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido59_004
                objectName: "Sólido59.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido59_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido6_009
                objectName: "Sólido6.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_008_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido60_004
                objectName: "Sólido60.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido60_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido61_004
                objectName: "Sólido61.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido61_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido62_004
                objectName: "Sólido62.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido62_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido63_004
                objectName: "Sólido63.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido63_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido64_004
                objectName: "Sólido64.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido64_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido65_004
                objectName: "Sólido65.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido65_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido66_004
                objectName: "Sólido66.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido66_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido67_004
                objectName: "Sólido67.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido67_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido68_004
                objectName: "Sólido68.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido68_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido69_004
                objectName: "Sólido69.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido69_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido7_008
                objectName: "Sólido7.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_007_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido70_004
                objectName: "Sólido70.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido70_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido71_004
                objectName: "Sólido71.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido71_004_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido72_003
                objectName: "Sólido72.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido72_003_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido73_003
                objectName: "Sólido73.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido73_003_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido74_003
                objectName: "Sólido74.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido74_003_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido75_002
                objectName: "Sólido75.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido75_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido76_002
                objectName: "Sólido76.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido76_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido77_002
                objectName: "Sólido77.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido77_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido78_002
                objectName: "Sólido78.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido78_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido79_002
                objectName: "Sólido79.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido79_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido8_008
                objectName: "Sólido8.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_007_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido80_002
                objectName: "Sólido80.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido80_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido81_002
                objectName: "Sólido81.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido81_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido82_002
                objectName: "Sólido82.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido82_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido83_002
                objectName: "Sólido83.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido83_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido84_002
                objectName: "Sólido84.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido84_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido85_002
                objectName: "Sólido85.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido85_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido86_002
                objectName: "Sólido86.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido86_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido87_002
                objectName: "Sólido87.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido87_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido88_002
                objectName: "Sólido88.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido88_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido89_002
                objectName: "Sólido89.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido89_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido9_008
                objectName: "Sólido9.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_007_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido90_002
                objectName: "Sólido90.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido90_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido91_002
                objectName: "Sólido91.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido91_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido92_002
                objectName: "Sólido92.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido92_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido93_002
                objectName: "Sólido93.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido93_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido94_002
                objectName: "Sólido94.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido94_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido95_002
                objectName: "Sólido95.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido95_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido96_002
                objectName: "Sólido96.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido96_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido97_002
                objectName: "Sólido97.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido97_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido98_002
                objectName: "Sólido98.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido98_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
            Model {
                id: s_lido99_002
                objectName: "Sólido99.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido99_002_mesh.mesh"
                materials: [
                    m191189187_material
                ]
            }
        }
        Node {
            id: female_Header_Pitch_2_54mm_1x20_1
            objectName: "Female Header Pitch 2.54mm 1x20:1"
            x: 0.11672694236040115
            y: -3.557588815689087
            z: 2.415738344192505
            rotation: Qt.quaternion(3.09086e-08, 0.707107, 3.09086e-08, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_029
                objectName: "Sólido1.029"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_018_mesh.mesh"
                materials: [
                    m211515_material
                ]
            }
            Model {
                id: s_lido10_009
                objectName: "Sólido10.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_008_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido11_009
                objectName: "Sólido11.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_008_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido12_008
                objectName: "Sólido12.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido13_008
                objectName: "Sólido13.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido14_008
                objectName: "Sólido14.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido15_008
                objectName: "Sólido15.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido16_008
                objectName: "Sólido16.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido17_008
                objectName: "Sólido17.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido18_008
                objectName: "Sólido18.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido19_008
                objectName: "Sólido19.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido2_014
                objectName: "Sólido2.014"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido20_008
                objectName: "Sólido20.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido21_008
                objectName: "Sólido21.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido3_014
                objectName: "Sólido3.014"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido4_014
                objectName: "Sólido4.014"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido5_014
                objectName: "Sólido5.014"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido6_014
                objectName: "Sólido6.014"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido7_013
                objectName: "Sólido7.013"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_009_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido8_009
                objectName: "Sólido8.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_008_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido9_009
                objectName: "Sólido9.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_008_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
        }
        Node {
            id: female_Header_Pitch_2_54mm_1x20_2
            objectName: "Female Header Pitch 2.54mm 1x20:2"
            x: 1.6407270431518555
            y: -3.557588815689087
            z: 2.415738344192505
            rotation: Qt.quaternion(3.09086e-08, 0.707107, 3.09086e-08, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_030
                objectName: "Sólido1.030"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_018_mesh.mesh"
                materials: [
                    m211515_material
                ]
            }
            Model {
                id: s_lido10_010
                objectName: "Sólido10.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_008_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido11_010
                objectName: "Sólido11.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_008_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido12_009
                objectName: "Sólido12.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido13_009
                objectName: "Sólido13.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido14_009
                objectName: "Sólido14.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido15_009
                objectName: "Sólido15.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido16_009
                objectName: "Sólido16.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido17_009
                objectName: "Sólido17.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido18_009
                objectName: "Sólido18.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido19_009
                objectName: "Sólido19.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido2_015
                objectName: "Sólido2.015"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido20_009
                objectName: "Sólido20.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido21_009
                objectName: "Sólido21.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_007_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido3_015
                objectName: "Sólido3.015"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido4_015
                objectName: "Sólido4.015"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido5_015
                objectName: "Sólido5.015"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido6_015
                objectName: "Sólido6.015"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_010_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido7_014
                objectName: "Sólido7.014"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_009_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido8_010
                objectName: "Sólido8.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_008_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
            Model {
                id: s_lido9_010
                objectName: "Sólido9.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_008_mesh.mesh"
                materials: [
                    m2551910_material
                ]
            }
        }
        Node {
            id: gyroSensor_GY_521_1
            objectName: "GyroSensor_GY_521:1"
            x: -9.129359245300293
            y: 0.4959203898906708
            z: -1.0211857557296753
            rotation: Qt.quaternion(3.09086e-08, 0.707107, -3.09086e-08, 0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_022
                objectName: "Sólido1.022"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_014_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido10_007
                objectName: "Sólido10.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_007_mesh732.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido100_001
                objectName: "Sólido100.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido100_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido101_001
                objectName: "Sólido101.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido101_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido102_001
                objectName: "Sólido102.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido102_001_mesh.mesh"
                materials: [
                    smoothBlack_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido103_001
                objectName: "Sólido103.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido103_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido104_001
                objectName: "Sólido104.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido104_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido105_001
                objectName: "Sólido105.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido105_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido106_001
                objectName: "Sólido106.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido106_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido107_001
                objectName: "Sólido107.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido107_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido108_001
                objectName: "Sólido108.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido108_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido109
                objectName: "Sólido109"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido109_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido11_007
                objectName: "Sólido11.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_007_mesh757.mesh"
                materials: [
                    m204204204_001_material,
                    gold_material
                ]
            }
            Model {
                id: s_lido110
                objectName: "Sólido110"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido110_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido111
                objectName: "Sólido111"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido111_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido112
                objectName: "Sólido112"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido112_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido113
                objectName: "Sólido113"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido113_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido114
                objectName: "Sólido114"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido114_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido115
                objectName: "Sólido115"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido115_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido116
                objectName: "Sólido116"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido116_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido117
                objectName: "Sólido117"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido117_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido118
                objectName: "Sólido118"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido118_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido119
                objectName: "Sólido119"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido119_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido12_006
                objectName: "Sólido12.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_006_mesh779.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido120
                objectName: "Sólido120"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido120_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido121
                objectName: "Sólido121"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido121_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido122
                objectName: "Sólido122"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido122_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido123
                objectName: "Sólido123"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido123_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido124
                objectName: "Sólido124"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido124_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido125
                objectName: "Sólido125"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido125_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido126
                objectName: "Sólido126"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido126_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido127
                objectName: "Sólido127"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido127_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido128
                objectName: "Sólido128"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido128_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido129
                objectName: "Sólido129"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido129_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido13_006
                objectName: "Sólido13.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_006_mesh801.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido130
                objectName: "Sólido130"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido130_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido131
                objectName: "Sólido131"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido131_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido132
                objectName: "Sólido132"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido132_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido133
                objectName: "Sólido133"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido133_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido134
                objectName: "Sólido134"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido134_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido135
                objectName: "Sólido135"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido135_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido136
                objectName: "Sólido136"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido136_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido137
                objectName: "Sólido137"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido137_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido138
                objectName: "Sólido138"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido138_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido139
                objectName: "Sólido139"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido139_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido14_006
                objectName: "Sólido14.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_006_mesh823.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido140
                objectName: "Sólido140"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido140_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido141
                objectName: "Sólido141"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido141_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido142
                objectName: "Sólido142"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido142_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido143
                objectName: "Sólido143"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido143_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido144
                objectName: "Sólido144"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido144_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido145
                objectName: "Sólido145"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido145_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido146
                objectName: "Sólido146"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido146_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido147
                objectName: "Sólido147"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido147_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido148
                objectName: "Sólido148"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido148_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido149
                objectName: "Sólido149"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido149_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido15_006
                objectName: "Sólido15.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_006_mesh845.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido150
                objectName: "Sólido150"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido150_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido151
                objectName: "Sólido151"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido151_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido152
                objectName: "Sólido152"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido152_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido153
                objectName: "Sólido153"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido153_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido154
                objectName: "Sólido154"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido154_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido155
                objectName: "Sólido155"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido155_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido156
                objectName: "Sólido156"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido156_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido157
                objectName: "Sólido157"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido157_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido158
                objectName: "Sólido158"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido158_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido159
                objectName: "Sólido159"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido159_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido16_006
                objectName: "Sólido16.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_006_mesh867.mesh"
                materials: [
                    smoothBlack_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido160
                objectName: "Sólido160"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido160_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido161
                objectName: "Sólido161"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido161_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido162
                objectName: "Sólido162"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido162_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido163
                objectName: "Sólido163"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido163_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido164
                objectName: "Sólido164"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido164_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido165
                objectName: "Sólido165"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido165_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido166
                objectName: "Sólido166"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido166_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido167
                objectName: "Sólido167"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido167_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido168
                objectName: "Sólido168"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido168_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido169
                objectName: "Sólido169"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido169_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido17_006
                objectName: "Sólido17.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_006_mesh889.mesh"
                materials: [
                    smoothBlack_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido170
                objectName: "Sólido170"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido170_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido171
                objectName: "Sólido171"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido171_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido172
                objectName: "Sólido172"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido172_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido173
                objectName: "Sólido173"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido173_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido174
                objectName: "Sólido174"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido174_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido175
                objectName: "Sólido175"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido175_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido176
                objectName: "Sólido176"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido176_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido177
                objectName: "Sólido177"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido177_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido178
                objectName: "Sólido178"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido178_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido179
                objectName: "Sólido179"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido179_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido18_006
                objectName: "Sólido18.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_005_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido180
                objectName: "Sólido180"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido180_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido181
                objectName: "Sólido181"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido181_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido182
                objectName: "Sólido182"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido182_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido183
                objectName: "Sólido183"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido183_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido184
                objectName: "Sólido184"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido184_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido185
                objectName: "Sólido185"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido185_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido186
                objectName: "Sólido186"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido186_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido187
                objectName: "Sólido187"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido187_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido188
                objectName: "Sólido188"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido188_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido189
                objectName: "Sólido189"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido189_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido19_006
                objectName: "Sólido19.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_005_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido190
                objectName: "Sólido190"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido190_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido191
                objectName: "Sólido191"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido191_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido192
                objectName: "Sólido192"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido192_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido193
                objectName: "Sólido193"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido193_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido194
                objectName: "Sólido194"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido194_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido195
                objectName: "Sólido195"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido195_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido196
                objectName: "Sólido196"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido196_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido197
                objectName: "Sólido197"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido197_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido198
                objectName: "Sólido198"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido198_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido199
                objectName: "Sólido199"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido199_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido2_007
                objectName: "Sólido2.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_007_mesh.mesh"
                materials: [
                    clearBlue_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido20_006
                objectName: "Sólido20.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_006_mesh958.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido200
                objectName: "Sólido200"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido200_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido201
                objectName: "Sólido201"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido201_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido202
                objectName: "Sólido202"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido202_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido203
                objectName: "Sólido203"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido203_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido204
                objectName: "Sólido204"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido204_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido205
                objectName: "Sólido205"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido205_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido206
                objectName: "Sólido206"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido206_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido207
                objectName: "Sólido207"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido207_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido208
                objectName: "Sólido208"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido208_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido209
                objectName: "Sólido209"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido209_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido21_006
                objectName: "Sólido21.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_006_mesh980.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido210
                objectName: "Sólido210"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido210_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido211
                objectName: "Sólido211"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido211_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido212
                objectName: "Sólido212"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido212_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido213
                objectName: "Sólido213"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido213_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido214
                objectName: "Sólido214"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido214_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido215
                objectName: "Sólido215"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido215_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido216
                objectName: "Sólido216"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido216_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido217
                objectName: "Sólido217"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido217_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido218
                objectName: "Sólido218"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido218_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido219
                objectName: "Sólido219"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido219_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido22_006
                objectName: "Sólido22.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_006_mesh1002.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido220
                objectName: "Sólido220"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido220_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido221
                objectName: "Sólido221"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido221_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido222
                objectName: "Sólido222"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido222_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido223
                objectName: "Sólido223"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido223_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido224
                objectName: "Sólido224"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido224_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido225
                objectName: "Sólido225"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido225_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido226
                objectName: "Sólido226"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido226_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido227
                objectName: "Sólido227"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido227_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido228
                objectName: "Sólido228"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido228_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido229
                objectName: "Sólido229"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido229_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido23_006
                objectName: "Sólido23.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_006_mesh1024.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido230
                objectName: "Sólido230"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido230_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido231
                objectName: "Sólido231"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido231_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido232
                objectName: "Sólido232"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido232_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido233
                objectName: "Sólido233"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido233_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido234
                objectName: "Sólido234"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido234_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido235
                objectName: "Sólido235"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido235_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido236
                objectName: "Sólido236"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido236_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido237
                objectName: "Sólido237"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido237_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido238
                objectName: "Sólido238"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido238_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido239
                objectName: "Sólido239"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido239_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido24_006
                objectName: "Sólido24.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_006_mesh1047.mesh"
                materials: [
                    brindle_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido240
                objectName: "Sólido240"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido240_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido241
                objectName: "Sólido241"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido241_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido242
                objectName: "Sólido242"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido242_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido243
                objectName: "Sólido243"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido243_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido244
                objectName: "Sólido244"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido244_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido245
                objectName: "Sólido245"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido245_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido246
                objectName: "Sólido246"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido246_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido247
                objectName: "Sólido247"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido247_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido248
                objectName: "Sólido248"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido248_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido249
                objectName: "Sólido249"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido249_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido25_006
                objectName: "Sólido25.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_006_mesh1069.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido250
                objectName: "Sólido250"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido250_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido251
                objectName: "Sólido251"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido251_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido252
                objectName: "Sólido252"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido252_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido253
                objectName: "Sólido253"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido253_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido254
                objectName: "Sólido254"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido254_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido255
                objectName: "Sólido255"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido255_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido256
                objectName: "Sólido256"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido256_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido257
                objectName: "Sólido257"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido257_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido258
                objectName: "Sólido258"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido258_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido259
                objectName: "Sólido259"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido259_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido26_006
                objectName: "Sólido26.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_006_mesh1091.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido260
                objectName: "Sólido260"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido260_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido261
                objectName: "Sólido261"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido261_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido262
                objectName: "Sólido262"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido262_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido263
                objectName: "Sólido263"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido263_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido264
                objectName: "Sólido264"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido264_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido265
                objectName: "Sólido265"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido265_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido266
                objectName: "Sólido266"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido266_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido267
                objectName: "Sólido267"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido267_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido268
                objectName: "Sólido268"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido268_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido269
                objectName: "Sólido269"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido269_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido27_006
                objectName: "Sólido27.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_006_mesh1113.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido270
                objectName: "Sólido270"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido270_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido271
                objectName: "Sólido271"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido271_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido272
                objectName: "Sólido272"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido272_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido273
                objectName: "Sólido273"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido273_mesh.mesh"
                materials: [
                    clearBlue_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido274
                objectName: "Sólido274"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido274_mesh.mesh"
                materials: [
                    brindle_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido275
                objectName: "Sólido275"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido275_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido276
                objectName: "Sólido276"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido276_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido277
                objectName: "Sólido277"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido277_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido278
                objectName: "Sólido278"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido278_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido279
                objectName: "Sólido279"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido279_mesh.mesh"
                materials: [
                    brindle_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido28_006
                objectName: "Sólido28.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_006_mesh1135.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido280
                objectName: "Sólido280"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido280_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido281
                objectName: "Sólido281"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido281_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido282
                objectName: "Sólido282"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido282_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido283
                objectName: "Sólido283"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido283_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido284
                objectName: "Sólido284"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido284_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido285
                objectName: "Sólido285"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido285_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido286
                objectName: "Sólido286"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido286_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido287
                objectName: "Sólido287"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido287_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido288
                objectName: "Sólido288"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido288_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido289
                objectName: "Sólido289"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido289_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido29_006
                objectName: "Sólido29.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_005_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido290
                objectName: "Sólido290"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido290_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido291
                objectName: "Sólido291"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido291_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido292
                objectName: "Sólido292"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido292_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido293
                objectName: "Sólido293"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido293_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido294
                objectName: "Sólido294"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido294_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido295
                objectName: "Sólido295"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido295_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido296
                objectName: "Sólido296"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido296_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido297
                objectName: "Sólido297"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido297_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido298
                objectName: "Sólido298"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido298_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido299
                objectName: "Sólido299"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido299_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido3_007
                objectName: "Sólido3.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_006_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido30_006
                objectName: "Sólido30.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_005_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido300
                objectName: "Sólido300"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido300_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido301
                objectName: "Sólido301"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido301_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido302
                objectName: "Sólido302"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido302_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido303
                objectName: "Sólido303"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido303_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido304
                objectName: "Sólido304"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido304_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido305
                objectName: "Sólido305"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido305_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido306
                objectName: "Sólido306"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido306_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido307
                objectName: "Sólido307"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido307_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido308
                objectName: "Sólido308"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido308_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido309
                objectName: "Sólido309"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido309_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido31_006
                objectName: "Sólido31.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_006_mesh1204.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido310
                objectName: "Sólido310"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido310_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido311
                objectName: "Sólido311"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido311_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido312
                objectName: "Sólido312"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido312_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido313
                objectName: "Sólido313"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido313_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido314
                objectName: "Sólido314"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido314_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido315
                objectName: "Sólido315"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido315_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido316
                objectName: "Sólido316"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido316_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido317
                objectName: "Sólido317"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido317_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gold_material
                ]
            }
            Model {
                id: s_lido32_006
                objectName: "Sólido32.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_006_mesh1222.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido33_004
                objectName: "Sólido33.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido33_004_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido34_004
                objectName: "Sólido34.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido34_004_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido35_004
                objectName: "Sólido35.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido35_004_mesh.mesh"
                materials: [
                    brindle_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido36_004
                objectName: "Sólido36.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido36_004_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido37_003
                objectName: "Sólido37.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido37_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido38_003
                objectName: "Sólido38.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido38_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido39_003
                objectName: "Sólido39.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido39_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido4_007
                objectName: "Sólido4.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_006_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido40_003
                objectName: "Sólido40.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido40_003_mesh.mesh"
                materials: [
                    smoothBlack_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido41_003
                objectName: "Sólido41.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido41_003_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido42_003
                objectName: "Sólido42.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido42_003_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido43_003
                objectName: "Sólido43.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido43_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido44_003
                objectName: "Sólido44.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido44_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido45_003
                objectName: "Sólido45.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido45_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido46_003
                objectName: "Sólido46.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido46_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido47_003
                objectName: "Sólido47.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido47_003_mesh.mesh"
                materials: [
                    smoothBlack_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido48_003
                objectName: "Sólido48.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido48_003_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido49_003
                objectName: "Sólido49.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido49_003_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido5_007
                objectName: "Sólido5.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_006_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido50_003
                objectName: "Sólido50.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido50_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido51_003
                objectName: "Sólido51.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido51_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido52_003
                objectName: "Sólido52.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido52_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido53_003
                objectName: "Sólido53.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido53_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido54_003
                objectName: "Sólido54.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido54_003_mesh.mesh"
                materials: [
                    smoothBlack_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido55_003
                objectName: "Sólido55.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido55_003_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido56_003
                objectName: "Sólido56.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido56_003_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido57_003
                objectName: "Sólido57.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido57_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido58_003
                objectName: "Sólido58.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido58_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido59_003
                objectName: "Sólido59.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido59_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido6_007
                objectName: "Sólido6.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_006_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido60_003
                objectName: "Sólido60.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido60_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido61_003
                objectName: "Sólido61.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido61_003_mesh.mesh"
                materials: [
                    brindle_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido62_003
                objectName: "Sólido62.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido62_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido63_003
                objectName: "Sólido63.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido63_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido64_003
                objectName: "Sólido64.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido64_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido65_003
                objectName: "Sólido65.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido65_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido66_003
                objectName: "Sólido66.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido66_003_mesh.mesh"
                materials: [
                    brindle_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido67_003
                objectName: "Sólido67.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido67_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido68_003
                objectName: "Sólido68.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido68_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido69_003
                objectName: "Sólido69.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido69_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido7_007
                objectName: "Sólido7.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_007_mesh1304.mesh"
                materials: [
                    clearBlue_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido70_003
                objectName: "Sólido70.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido70_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido71_003
                objectName: "Sólido71.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido71_003_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido72_002
                objectName: "Sólido72.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido72_002_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido73_002
                objectName: "Sólido73.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido73_002_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido74_002
                objectName: "Sólido74.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido74_002_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido75_001
                objectName: "Sólido75.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido75_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido76_001
                objectName: "Sólido76.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido76_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido77_001
                objectName: "Sólido77.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido77_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido78_001
                objectName: "Sólido78.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido78_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido79_001
                objectName: "Sólido79.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido79_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido8_007
                objectName: "Sólido8.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_007_mesh1326.mesh"
                materials: [
                    clearBlue_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido80_001
                objectName: "Sólido80.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido80_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido81_001
                objectName: "Sólido81.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido81_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido82_001
                objectName: "Sólido82.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido82_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido83_001
                objectName: "Sólido83.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido83_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido84_001
                objectName: "Sólido84.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido84_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido85_001
                objectName: "Sólido85.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido85_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    blueWallPaintGlossy_material
                ]
            }
            Model {
                id: s_lido86_001
                objectName: "Sólido86.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido86_001_mesh.mesh"
                materials: [
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido87_001
                objectName: "Sólido87.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido87_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido88_001
                objectName: "Sólido88.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido88_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido89_001
                objectName: "Sólido89.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido89_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido9_007
                objectName: "Sólido9.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_007_mesh1348.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido90_001
                objectName: "Sólido90.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido90_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido91_001
                objectName: "Sólido91.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido91_001_mesh.mesh"
                materials: [
                    smoothBlack_material,
                    m204204204_001_material
                ]
            }
            Model {
                id: s_lido92_001
                objectName: "Sólido92.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido92_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido93_001
                objectName: "Sólido93.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido93_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido94_001
                objectName: "Sólido94.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido94_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido95_001
                objectName: "Sólido95.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido95_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido96_001
                objectName: "Sólido96.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido96_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido97_001
                objectName: "Sólido97.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido97_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido98_001
                objectName: "Sólido98.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido98_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido99_001
                objectName: "Sólido99.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido99_001_mesh.mesh"
                materials: [
                    m204204204_001_material,
                    gray_material
                ]
            }
        }
        Node {
            id: iso_1207_M2_x_10_1
            objectName: "ISO 1207 M2 x 10:1"
            x: -2.781273126602173
            y: -3.7170796394348145
            z: 1.6018999814987183
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1
                objectName: "Solid1"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: iso_1207_M2_x_10_2
            objectName: "ISO 1207 M2 x 10:2"
            x: -4.681272983551025
            y: -3.7170796394348145
            z: 1.6018999814987183
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_002
                objectName: "Solid1.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: iso_1207_M2_x_10_3
            objectName: "ISO 1207 M2 x 10:3"
            x: -2.781273126602173
            y: -3.7170796394348145
            z: -1.598099946975708
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_004
                objectName: "Solid1.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: iso_1207_M2_x_10_4
            objectName: "ISO 1207 M2 x 10:4"
            x: -4.681272983551025
            y: -3.7170796394348145
            z: -1.598099946975708
            rotation: Qt.quaternion(-0.5, 0.5, 0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_006
                objectName: "Solid1.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: male_Header_2_54mm_1x2_1
            objectName: "Male Header 2.54mm 1x2:1"
            x: -5.836173057556152
            y: -3.550079345703125
            z: -4.451079845428467
            rotation: Qt.quaternion(-4.37114e-08, 0, 0, 1)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_031
                objectName: "Sólido1.031"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_019_mesh.mesh"
                materials: [
                    m000_material
                ]
            }
            Model {
                id: s_lido2_016
                objectName: "Sólido2.016"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_011_mesh.mesh"
                materials: [
                    m204204204_002_material
                ]
            }
            Model {
                id: s_lido3_016
                objectName: "Sólido3.016"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_011_mesh.mesh"
                materials: [
                    m204204204_002_material
                ]
            }
        }
        Node {
            id: male_Header_2_54mm_1x2_2
            objectName: "Male Header 2.54mm 1x2:2"
            x: -7.686172962188721
            y: -3.550079345703125
            z: -4.705080032348633
            rotation: Qt.quaternion(1.94707e-07, 1, 0, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_032
                objectName: "Sólido1.032"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_019_mesh.mesh"
                materials: [
                    m000_material
                ]
            }
            Model {
                id: s_lido2_017
                objectName: "Sólido2.017"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_011_mesh.mesh"
                materials: [
                    m204204204_002_material
                ]
            }
            Model {
                id: s_lido3_017
                objectName: "Sólido3.017"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_011_mesh.mesh"
                materials: [
                    m204204204_002_material
                ]
            }
        }
        Node {
            id: male_Header_2_54mm_1x2_3
            objectName: "Male Header 2.54mm 1x2:3"
            x: -5.836173057556152
            y: -3.550079345703125
            z: -3.6010801792144775
            rotation: Qt.quaternion(1.94707e-07, 1, 0, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_033
                objectName: "Sólido1.033"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_019_mesh.mesh"
                materials: [
                    m000_material
                ]
            }
            Model {
                id: s_lido2_018
                objectName: "Sólido2.018"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_011_mesh.mesh"
                materials: [
                    m204204204_002_material
                ]
            }
            Model {
                id: s_lido3_018
                objectName: "Sólido3.018"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_011_mesh.mesh"
                materials: [
                    m204204204_002_material
                ]
            }
        }
        Node {
            id: male_Header_2_54mm_1x2_4
            objectName: "Male Header 2.54mm 1x2:4"
            x: -7.686172962188721
            y: -3.550079345703125
            z: -3.6010801792144775
            rotation: Qt.quaternion(1.94707e-07, 1, 0, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_034
                objectName: "Sólido1.034"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_019_mesh.mesh"
                materials: [
                    m000_material
                ]
            }
            Model {
                id: s_lido2_019
                objectName: "Sólido2.019"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_011_mesh.mesh"
                materials: [
                    m204204204_002_material
                ]
            }
            Model {
                id: s_lido3_019
                objectName: "Sólido3.019"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_011_mesh.mesh"
                materials: [
                    m204204204_002_material
                ]
            }
        }
        Node {
            id: n20_DC_MOTOR_1
            objectName: "N20 DC MOTOR:1"
            x: -3.756286144256592
            y: -4.2170796394348145
            z: 0.9368999600410461
            rotation: Qt.quaternion(1.94707e-07, 0, 0, 1)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_001
                objectName: "Sólido1.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_001_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido10
                objectName: "Sólido10"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido11
                objectName: "Sólido11"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_mesh.mesh"
                materials: [
                    m363634_material,
                    m15613582_material
                ]
            }
            Model {
                id: s_lido12
                objectName: "Sólido12"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido13
                objectName: "Sólido13"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_mesh.mesh"
                materials: [
                    m204204204_material
                ]
            }
            Model {
                id: s_lido14
                objectName: "Sólido14"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_mesh.mesh"
                materials: [
                    m1888047_material,
                    default_material,
                    m153153153_material,
                    m190188186_material,
                    m2437248_material
                ]
            }
            Model {
                id: s_lido15
                objectName: "Sólido15"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_mesh.mesh"
                materials: [
                    m18013989_material
                ]
            }
            Model {
                id: s_lido16
                objectName: "Sólido16"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_mesh.mesh"
                materials: [
                    m555_material
                ]
            }
            Model {
                id: s_lido17
                objectName: "Sólido17"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_mesh.mesh"
                materials: [
                    m555_material
                ]
            }
            Model {
                id: s_lido18
                objectName: "Sólido18"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_mesh.mesh"
                materials: [
                    m15613581_material
                ]
            }
            Model {
                id: s_lido19
                objectName: "Sólido19"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_mesh.mesh"
                materials: [
                    m15613581_material
                ]
            }
            Model {
                id: s_lido2
                objectName: "Sólido2"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido20
                objectName: "Sólido20"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido21
                objectName: "Sólido21"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido22
                objectName: "Sólido22"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_mesh.mesh"
                materials: [
                    m15613582_material
                ]
            }
            Model {
                id: s_lido23
                objectName: "Sólido23"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_mesh.mesh"
                materials: [
                    m15613582_material
                ]
            }
            Model {
                id: s_lido24
                objectName: "Sólido24"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_mesh.mesh"
                materials: [
                    m15613582_material
                ]
            }
            Model {
                id: s_lido25
                objectName: "Sólido25"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido26
                objectName: "Sólido26"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido27
                objectName: "Sólido27"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido28
                objectName: "Sólido28"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido29
                objectName: "Sólido29"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_mesh.mesh"
                materials: [
                    m190188186_material,
                    m2437248_material
                ]
            }
            Model {
                id: s_lido3
                objectName: "Sólido3"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido30
                objectName: "Sólido30"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido31
                objectName: "Sólido31"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido32
                objectName: "Sólido32"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_mesh.mesh"
                materials: [
                    m178178178_material,
                    m15613582_material,
                    m190188186_material
                ]
            }
            Model {
                id: s_lido4
                objectName: "Sólido4"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido5
                objectName: "Sólido5"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido6
                objectName: "Sólido6"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido7
                objectName: "Sólido7"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido8
                objectName: "Sólido8"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido9
                objectName: "Sólido9"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
        }
        Node {
            id: n20_DC_MOTOR_2
            objectName: "N20 DC MOTOR:2"
            x: -3.7562596797943115
            y: -4.211297035217285
            z: -0.9367699027061462
            rotation: Qt.quaternion(-0.00422806, 0.999991, 7.69155e-08, -3.25206e-10)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_005
                objectName: "Sólido1.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_001_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido10_001
                objectName: "Sólido10.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido11_001
                objectName: "Sólido11.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_001_mesh.mesh"
                materials: [
                    m363634_material,
                    m15613582_material
                ]
            }
            Model {
                id: s_lido12_001
                objectName: "Sólido12.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido13_001
                objectName: "Sólido13.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_mesh.mesh"
                materials: [
                    m204204204_material
                ]
            }
            Model {
                id: s_lido14_001
                objectName: "Sólido14.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_001_mesh.mesh"
                materials: [
                    m1888047_material,
                    default_material,
                    m153153153_material,
                    m190188186_material,
                    m2437248_material
                ]
            }
            Model {
                id: s_lido15_001
                objectName: "Sólido15.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_mesh.mesh"
                materials: [
                    m18013989_material
                ]
            }
            Model {
                id: s_lido16_001
                objectName: "Sólido16.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_mesh.mesh"
                materials: [
                    m555_material
                ]
            }
            Model {
                id: s_lido17_001
                objectName: "Sólido17.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_mesh.mesh"
                materials: [
                    m555_material
                ]
            }
            Model {
                id: s_lido18_001
                objectName: "Sólido18.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_mesh.mesh"
                materials: [
                    m15613581_material
                ]
            }
            Model {
                id: s_lido19_001
                objectName: "Sólido19.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_mesh.mesh"
                materials: [
                    m15613581_material
                ]
            }
            Model {
                id: s_lido2_001
                objectName: "Sólido2.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido20_001
                objectName: "Sólido20.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido21_001
                objectName: "Sólido21.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido22_001
                objectName: "Sólido22.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_mesh.mesh"
                materials: [
                    m15613582_material
                ]
            }
            Model {
                id: s_lido23_001
                objectName: "Sólido23.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_mesh.mesh"
                materials: [
                    m15613582_material
                ]
            }
            Model {
                id: s_lido24_001
                objectName: "Sólido24.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_mesh.mesh"
                materials: [
                    m15613582_material
                ]
            }
            Model {
                id: s_lido25_001
                objectName: "Sólido25.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido26_001
                objectName: "Sólido26.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido27_001
                objectName: "Sólido27.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido28_001
                objectName: "Sólido28.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido29_001
                objectName: "Sólido29.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_001_mesh.mesh"
                materials: [
                    m190188186_material,
                    m2437248_material
                ]
            }
            Model {
                id: s_lido3_001
                objectName: "Sólido3.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido30_001
                objectName: "Sólido30.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido31_001
                objectName: "Sólido31.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido32_001
                objectName: "Sólido32.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_001_mesh.mesh"
                materials: [
                    m178178178_material,
                    m15613582_material,
                    m190188186_material
                ]
            }
            Model {
                id: s_lido4_001
                objectName: "Sólido4.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_mesh.mesh"
                materials: [
                    m190188186_material
                ]
            }
            Model {
                id: s_lido5_001
                objectName: "Sólido5.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido6_001
                objectName: "Sólido6.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido7_001
                objectName: "Sólido7.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido8_001
                objectName: "Sólido8.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
            Model {
                id: s_lido9_001
                objectName: "Sólido9.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_mesh.mesh"
                materials: [
                    m224223219_material
                ]
            }
        }
        Node {
            id: rim_1
            objectName: "Rim:1"
            x: -3.756286144256592
            y: -4.2170796394348145
            z: 4.046899795532227
            rotation: Qt.quaternion(0.663435, 0.244652, 0.663435, -0.244652)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_002
                objectName: "Sólido1.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_002_mesh.mesh"
                materials: [
                    smoothMediumGray_material
                ]
            }
        }
        Node {
            id: rim_2
            objectName: "Rim:2"
            x: -3.7562596797943115
            y: -4.184998512268066
            z: -4.046658992767334
            rotation: Qt.quaternion(0.695876, 0.125525, -0.696913, 0.119636)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_006
                objectName: "Sólido1.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_002_mesh.mesh"
                materials: [
                    smoothMediumGray_material
                ]
            }
        }
        Node {
            id: spdt_Mini_Slide_Switch_1
            objectName: "SPDT Mini Slide Switch:1"
            x: -9.331273078918457
            y: -0.10330894589424133
            z: 2.9768998622894287
            rotation: Qt.quaternion(1.94707e-07, 1, 0, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_023
                objectName: "Sólido1.023"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_015_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
            Model {
                id: s_lido2_008
                objectName: "Sólido2.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_007_mesh1524.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
            Model {
                id: s_lido3_008
                objectName: "Sólido3.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_007_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
            Model {
                id: s_lido4_008
                objectName: "Sólido4.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_007_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
            Model {
                id: s_lido5_008
                objectName: "Sólido5.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_007_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
            Model {
                id: s_lido6_008
                objectName: "Sólido6.008"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_007_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: ssd1306
            objectName: "SSD1306"
            x: -10.625166893005371
            y: 0.502920389175415
            z: -0.012550091370940208
            rotation: Qt.quaternion(3.09086e-08, 0.707107, -3.09086e-08, 0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_010
                objectName: "Sólido1.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_010_mesh.mesh"
                materials: [
                    m0115170_material,
                    m251250245_material
                ]
            }
            Model {
                id: s_lido10_004
                objectName: "Sólido10.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_003_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido11_004
                objectName: "Sólido11.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_003_mesh.mesh"
                materials: [
                    m246246243_material
                ]
            }
            Model {
                id: s_lido12_003
                objectName: "Sólido12.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_003_mesh1546.mesh"
                materials: [
                    m246246243_material,
                    m4859150_material,
                    m505050_material
                ]
            }
            Model {
                id: s_lido13_003
                objectName: "Sólido13.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_002_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido14_003
                objectName: "Sólido14.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido15_003
                objectName: "Sólido15.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_002_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido16_003
                objectName: "Sólido16.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_002_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido17_003
                objectName: "Sólido17.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_002_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido18_003
                objectName: "Sólido18.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido19_003
                objectName: "Sólido19.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido2_004
                objectName: "Sólido2.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_003_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido20_003
                objectName: "Sólido20.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido21_003
                objectName: "Sólido21.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido22_003
                objectName: "Sólido22.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido23_003
                objectName: "Sólido23.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido24_003
                objectName: "Sólido24.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido25_003
                objectName: "Sólido25.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido26_003
                objectName: "Sólido26.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido27_003
                objectName: "Sólido27.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido28_003
                objectName: "Sólido28.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido29_003
                objectName: "Sólido29.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido3_004
                objectName: "Sólido3.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_003_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido30_003
                objectName: "Sólido30.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido31_003
                objectName: "Sólido31.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido32_003
                objectName: "Sólido32.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_002_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido33_001
                objectName: "Sólido33.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido33_001_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido34_001
                objectName: "Sólido34.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido34_001_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido35_001
                objectName: "Sólido35.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido35_001_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido36_001
                objectName: "Sólido36.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido36_001_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido37
                objectName: "Sólido37"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido37_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido38
                objectName: "Sólido38"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido38_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido39
                objectName: "Sólido39"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido39_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido4_004
                objectName: "Sólido4.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_003_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido40
                objectName: "Sólido40"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido40_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido41
                objectName: "Sólido41"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido41_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido42
                objectName: "Sólido42"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido42_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido43
                objectName: "Sólido43"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido43_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido44
                objectName: "Sólido44"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido44_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido45
                objectName: "Sólido45"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido45_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido46
                objectName: "Sólido46"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido46_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido47
                objectName: "Sólido47"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido47_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido48
                objectName: "Sólido48"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido48_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido49
                objectName: "Sólido49"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido49_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido5_004
                objectName: "Sólido5.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_003_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido50
                objectName: "Sólido50"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido50_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido51
                objectName: "Sólido51"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido51_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido52
                objectName: "Sólido52"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido52_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido53
                objectName: "Sólido53"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido53_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido54
                objectName: "Sólido54"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido54_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido55
                objectName: "Sólido55"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido55_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido56
                objectName: "Sólido56"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido56_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido57
                objectName: "Sólido57"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido57_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido58
                objectName: "Sólido58"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido58_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido59
                objectName: "Sólido59"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido59_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido6_004
                objectName: "Sólido6.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_003_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido60
                objectName: "Sólido60"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido60_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido61
                objectName: "Sólido61"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido61_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido62
                objectName: "Sólido62"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido62_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido63
                objectName: "Sólido63"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido63_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido64
                objectName: "Sólido64"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido64_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido65
                objectName: "Sólido65"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido65_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido66
                objectName: "Sólido66"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido66_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido67
                objectName: "Sólido67"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido67_mesh.mesh"
                materials: [
                    m505050_material
                ]
            }
            Model {
                id: s_lido68
                objectName: "Sólido68"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido68_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido69
                objectName: "Sólido69"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido69_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido7_004
                objectName: "Sólido7.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_003_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido70
                objectName: "Sólido70"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido70_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido71
                objectName: "Sólido71"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido71_mesh.mesh"
                materials: [
                    m2001427_material
                ]
            }
            Model {
                id: s_lido8_004
                objectName: "Sólido8.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_003_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
            Model {
                id: s_lido9_004
                objectName: "Sólido9.004"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_003_mesh.mesh"
                materials: [
                    m251250245_material
                ]
            }
        }
        Node {
            id: separadorArriba_1
            objectName: "SeparadorArriba:1"
            x: -9.98127269744873
            y: 2.3429203033447266
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.30042, 0.30042, -0.640116, 0.640116)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_040
                objectName: "Sólido1.040"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_021_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: separadorArriba_2
            objectName: "SeparadorArriba:2"
            x: -9.98127269744873
            y: 2.3429203033447266
            z: -2.4981000423431396
            rotation: Qt.quaternion(0.30042, 0.30042, -0.640116, 0.640116)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_041
                objectName: "Sólido1.041"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_021_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: slotted_1
            objectName: "Slotted:1"
            x: -3.756286144256592
            y: -4.2170796394348145
            z: 4.446899890899658
            rotation: Qt.quaternion(0.543592, 0.452226, -0.543592, 0.452225)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_003
                objectName: "Sólido1.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_003_mesh.mesh"
                materials: [
                    rubberBlack_material
                ]
            }
        }
        Node {
            id: slotted_2
            objectName: "Slotted:2"
            x: -3.7562596797943115
            y: -4.181616306304932
            z: -4.446644306182861
            rotation: Qt.quaternion(0.452065, 0.543725, 0.456647, -0.539883)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_007
                objectName: "Sólido1.007"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_004_mesh.mesh"
                materials: [
                    m393939_material
                ]
            }
        }
        Node {
            id: soportesAdelante_1
            objectName: "SoportesAdelante:1"
            x: -9.98127269744873
            y: -3.557079553604126
            z: -2.4981000423431396
            rotation: Qt.quaternion(0.5, -0.5, -0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_018
                objectName: "Sólido1.018"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_011_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: soportesAdelante_2
            objectName: "SoportesAdelante:2"
            x: -9.98127269744873
            y: -3.557079553604126
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.5, -0.5, -0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_019
                objectName: "Sólido1.019"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_011_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: soportesMedio_1
            objectName: "SoportesMedio:1"
            x: -5.081273078918457
            y: -3.557079553604126
            z: -2.598099946975708
            rotation: Qt.quaternion(0.270598, -0.270598, 0.653282, 0.653281)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_014
                objectName: "Sólido1.014"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_010_mesh1702.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: soportesMedio_2
            objectName: "SoportesMedio:2"
            x: -5.081273078918457
            y: -3.557079553604126
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.270598, -0.270598, 0.653282, 0.653281)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_015
                objectName: "Sólido1.015"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_010_mesh1702.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: soportesMedio_3
            objectName: "SoportesMedio:3"
            x: -2.4812729358673096
            y: -3.557079553604126
            z: -2.598099946975708
            rotation: Qt.quaternion(0.5, -0.5, 0.5, 0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_016
                objectName: "Sólido1.016"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_010_mesh1702.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: soportesMedio_4
            objectName: "SoportesMedio:4"
            x: -2.4812729358673096
            y: -3.557079553604126
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.270598, -0.270598, 0.653282, 0.653281)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_017
                objectName: "Sólido1.017"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_010_mesh1702.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: tcrt_5000_1
            objectName: "TCRT-5000:1"
            x: -11.291358947753906
            y: -3.557079553604126
            z: -3.7980642318725586
            rotation: Qt.quaternion(0.270598, 0.653281, 0.653282, 0.270598)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_025
                objectName: "Sólido1.025"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_017_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
            Model {
                id: s_lido2_010
                objectName: "Sólido2.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido3_010
                objectName: "Sólido3.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido4_010
                objectName: "Sólido4.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido5_010
                objectName: "Sólido5.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido6_010
                objectName: "Sólido6.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_009_mesh.mesh"
                materials: [
                    m4859150_002_material
                ]
            }
            Model {
                id: s_lido7_009
                objectName: "Sólido7.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_008_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
        }
        Node {
            id: tcrt_5000_2
            objectName: "TCRT-5000:2"
            x: -3.0962729454040527
            y: -3.757079601287842
            z: 0.511900007724762
            rotation: Qt.quaternion(0.707107, 0, 0.707107, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_026
                objectName: "Sólido1.026"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_017_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
            Model {
                id: s_lido2_011
                objectName: "Sólido2.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido3_011
                objectName: "Sólido3.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido4_011
                objectName: "Sólido4.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido5_011
                objectName: "Sólido5.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido6_011
                objectName: "Sólido6.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_009_mesh.mesh"
                materials: [
                    m4859150_002_material
                ]
            }
            Model {
                id: s_lido7_010
                objectName: "Sólido7.010"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_008_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
        }
        Node {
            id: tcrt_5000_3
            objectName: "TCRT-5000:3"
            x: -10.881237983703613
            y: -3.557079553604126
            z: 4.211986064910889
            rotation: Qt.quaternion(-0.270598, 0.653281, 0.653282, -0.270598)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_027
                objectName: "Sólido1.027"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_017_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
            Model {
                id: s_lido2_012
                objectName: "Sólido2.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido3_012
                objectName: "Sólido3.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido4_012
                objectName: "Sólido4.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido5_012
                objectName: "Sólido5.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido6_012
                objectName: "Sólido6.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_009_mesh.mesh"
                materials: [
                    m4859150_002_material
                ]
            }
            Model {
                id: s_lido7_011
                objectName: "Sólido7.011"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_008_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
        }
        Node {
            id: tcrt_5000_4
            objectName: "TCRT-5000:4"
            x: -10.966273307800293
            y: -3.757079601287842
            z: -0.5080999732017517
            rotation: Qt.quaternion(0.707107, 0, -0.707107, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_028
                objectName: "Sólido1.028"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_017_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
            Model {
                id: s_lido2_013
                objectName: "Sólido2.013"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido3_013
                objectName: "Sólido3.013"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido4_013
                objectName: "Sólido4.013"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido5_013
                objectName: "Sólido5.013"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido6_013
                objectName: "Sólido6.013"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_009_mesh.mesh"
                materials: [
                    m4859150_002_material
                ]
            }
            Model {
                id: s_lido7_012
                objectName: "Sólido7.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_008_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
        }
        Node {
            id: tcrt_5000_5
            objectName: "TCRT-5000:5"
            x: -9.317778587341309
            y: -3.5607197284698486
            z: 4.297798156738281
            rotation: Qt.quaternion(-0.5, 0.5, 0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_036
                objectName: "Sólido1.036"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_017_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
            Model {
                id: s_lido2_021
                objectName: "Sólido2.021"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido3_021
                objectName: "Sólido3.021"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido4_017
                objectName: "Sólido4.017"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido5_017
                objectName: "Sólido5.017"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido6_017
                objectName: "Sólido6.017"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_009_mesh.mesh"
                materials: [
                    m4859150_002_material
                ]
            }
            Model {
                id: s_lido7_016
                objectName: "Sólido7.016"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_008_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
        }
        Node {
            id: tcrt_5000_6
            objectName: "TCRT-5000:6"
            x: -11.378780364990234
            y: -3.557079553604126
            z: 2.8211963176727295
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_037
                objectName: "Sólido1.037"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_017_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
            Model {
                id: s_lido2_022
                objectName: "Sólido2.022"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido3_022
                objectName: "Sólido3.022"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido4_018
                objectName: "Sólido4.018"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido5_018
                objectName: "Sólido5.018"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido6_018
                objectName: "Sólido6.018"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_009_mesh.mesh"
                materials: [
                    m4859150_002_material
                ]
            }
            Model {
                id: s_lido7_017
                objectName: "Sólido7.017"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_008_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
        }
        Node {
            id: tcrt_5000_7
            objectName: "TCRT-5000:7"
            x: -11.38127326965332
            y: -3.557079553604126
            z: -2.2304341793060303
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_038
                objectName: "Sólido1.038"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_017_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
            Model {
                id: s_lido2_023
                objectName: "Sólido2.023"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido3_023
                objectName: "Sólido3.023"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido4_019
                objectName: "Sólido4.019"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido5_019
                objectName: "Sólido5.019"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido6_019
                objectName: "Sólido6.019"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_009_mesh.mesh"
                materials: [
                    m4859150_002_material
                ]
            }
            Model {
                id: s_lido7_018
                objectName: "Sólido7.018"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_008_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
        }
        Node {
            id: tcrt_5000_8
            objectName: "TCRT-5000:8"
            x: -9.897977828979492
            y: -3.557079553604126
            z: -4.295643329620361
            rotation: Qt.quaternion(0.5, 0.5, 0.5, 0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_039
                objectName: "Sólido1.039"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_017_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
            Model {
                id: s_lido2_024
                objectName: "Sólido2.024"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido3_024
                objectName: "Sólido3.024"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido4_020
                objectName: "Sólido4.020"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido5_020
                objectName: "Sólido5.020"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_009_mesh.mesh"
                materials: [
                    m209204192_material
                ]
            }
            Model {
                id: s_lido6_020
                objectName: "Sólido6.020"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_009_mesh.mesh"
                materials: [
                    m4859150_002_material
                ]
            }
            Model {
                id: s_lido7_019
                objectName: "Sólido7.019"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_008_mesh.mesh"
                materials: [
                    m252525_001_material
                ]
            }
        }
        Node {
            id: topePie_1
            objectName: "TopePie:1"
            x: -9.98127269744873
            y: -4.367079734802246
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.707107, 0.707107, 0, 0)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_012
                objectName: "Sólido1.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_009_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: topePie_2
            objectName: "TopePie:2"
            x: -9.98127269744873
            y: -4.367079734802246
            z: -2.4981000423431396
            rotation: Qt.quaternion(0.270598, 0.270598, 0.653282, -0.653281)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_013
                objectName: "Sólido1.013"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_009_mesh.mesh"
                materials: [
                    glossyBlack_material
                ]
            }
        }
        Node {
            id: tornillo_con_cabeza_redonda_ranurada___Pulgadas_4___40_x_2_1_4
            objectName: "Tornillo con cabeza redonda ranurada - Pulgadas 4 - 40 x 2 1/4"
            x: -2.4812729358673096
            y: 1.0429203510284424
            z: -2.598099946975708
            rotation: Qt.quaternion(0.5, -0.5, 0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_014
                objectName: "Solid1.014"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_004_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: tornillo_con_cabeza_redonda_ranurada___Pulgadas_4___40_x_2_1_4_
            objectName: "Tornillo con cabeza redonda ranurada - Pulgadas 4 - 40 x 2 1/4:"
            x: -2.4812729358673096
            y: 1.0429203510284424
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_012
                objectName: "Solid1.012"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_004_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: tornillo_de_cabeza_ranurada_redonda___Pulgadas_N__6___40___2_
            objectName: "Tornillo de cabeza ranurada redonda - Pulgadas Nº 6 - 40 - 2 "
            x: -9.98127269744873
            y: 2.3429203033447266
            z: -2.4981000423431396
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_026
                objectName: "Solid1.026"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_009_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: tornillo_de_cabeza_ranurada_redonda___Pulgadas_N__6___40___2_3
            objectName: "Tornillo de cabeza ranurada redonda - Pulgadas Nº 6 - 40 - 2 3"
            x: -9.98127269744873
            y: 2.3429203033447266
            z: 2.6018998622894287
            rotation: Qt.quaternion(0.707107, 0, 0, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_024
                objectName: "Solid1.024"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_009_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: tuerca_hex__para_maquinaria___Pulgadas_4___40_1
            objectName: "Tuerca hex. para maquinaria - Pulgadas 4 - 40:1"
            x: -2.4812729358673096
            y: -3.9659996032714844
            z: 2.6018998622894287
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_013
                objectName: "Solid1.013"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_005_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: tuerca_hex__para_maquinaria___Pulgadas_4___40_2
            objectName: "Tuerca hex. para maquinaria - Pulgadas 4 - 40:2"
            x: -2.4812729358673096
            y: -3.9659996032714844
            z: -2.598099946975708
            rotation: Qt.quaternion(-0.5, 0.5, 0.5, -0.5)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_015
                objectName: "Solid1.015"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_005_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: tuerca_hex__para_maquinaria___Pulgadas_6___40_1
            objectName: "Tuerca hex. para maquinaria - Pulgadas 6 - 40:1"
            x: -9.98127269744873
            y: -4.00663948059082
            z: 2.6018998622894287
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_025
                objectName: "Solid1.025"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_010_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: tuerca_hex__para_maquinaria___Pulgadas_6___40_2
            objectName: "Tuerca hex. para maquinaria - Pulgadas 6 - 40:2"
            x: -9.98127269744873
            y: -4.00663948059082
            z: -2.4981000423431396
            rotation: Qt.quaternion(-3.09086e-08, 0.707107, 0.707107, -3.09086e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: solid1_027
                objectName: "Solid1.027"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/solid1_010_mesh.mesh"
                materials: [
                    semiPolished_material
                ]
            }
        }
        Node {
            id: wf2024THT_1
            objectName: "WF2024THT:1"
            x: -14.621273040771484
            y: -3.7170796394348145
            z: 7.5019001960754395
            rotation: Qt.quaternion(3.09086e-08, 0.707107, 3.09086e-08, -0.707107)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_009
                objectName: "Sólido1.009"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_009_mesh1812.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido10_003
                objectName: "Sólido10.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_003_mesh1816.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido11_003
                objectName: "Sólido11.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_003_mesh1818.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido12_002
                objectName: "Sólido12.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_002_mesh.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido13_002
                objectName: "Sólido13.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_002_mesh1822.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido14_002
                objectName: "Sólido14.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_002_mesh1824.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido15_002
                objectName: "Sólido15.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_002_mesh1826.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido16_002
                objectName: "Sólido16.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_002_mesh1828.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido17_002
                objectName: "Sólido17.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_002_mesh1830.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido18_002
                objectName: "Sólido18.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_002_mesh1832.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido19_002
                objectName: "Sólido19.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_002_mesh1834.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido2_003
                objectName: "Sólido2.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_003_mesh1836.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido20_002
                objectName: "Sólido20.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_002_mesh1838.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido21_002
                objectName: "Sólido21.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_002_mesh1841.mesh"
                materials: [
                    m225181125_material,
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido22_002
                objectName: "Sólido22.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_002_mesh1843.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido23_002
                objectName: "Sólido23.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_002_mesh1845.mesh"
                materials: [
                    m383737_material,
                    glossyBlack_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido24_002
                objectName: "Sólido24.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_002_mesh1847.mesh"
                materials: [
                    m383737_material,
                    m210209199_material
                ]
            }
            Model {
                id: s_lido25_002
                objectName: "Sólido25.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_002_mesh1849.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido26_002
                objectName: "Sólido26.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_002_mesh1851.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido27_002
                objectName: "Sólido27.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_002_mesh1853.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido28_002
                objectName: "Sólido28.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_002_mesh1855.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido29_002
                objectName: "Sólido29.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_002_mesh1857.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido3_003
                objectName: "Sólido3.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_003_mesh1859.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido30_002
                objectName: "Sólido30.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_002_mesh1861.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido31_002
                objectName: "Sólido31.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_002_mesh1863.mesh"
                materials: [
                    m383737_material,
                    m210209199_material
                ]
            }
            Model {
                id: s_lido32_002
                objectName: "Sólido32.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_002_mesh1865.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido33
                objectName: "Sólido33"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido33_mesh.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido34
                objectName: "Sólido34"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido34_mesh.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido35
                objectName: "Sólido35"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido35_mesh.mesh"
                materials: [
                    m225181125_material,
                    m80124105_material
                ]
            }
            Model {
                id: s_lido36
                objectName: "Sólido36"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido36_mesh.mesh"
                materials: [
                    m383737_material,
                    glossyBlack_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido4_003
                objectName: "Sólido4.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_003_mesh1876.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido5_003
                objectName: "Sólido5.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_003_mesh1878.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido6_003
                objectName: "Sólido6.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_003_mesh1880.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido7_003
                objectName: "Sólido7.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_003_mesh1882.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
            Model {
                id: s_lido8_003
                objectName: "Sólido8.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_003_mesh1884.mesh"
                materials: [
                    m383737_material,
                    m219188126_material
                ]
            }
            Model {
                id: s_lido9_003
                objectName: "Sólido9.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_003_mesh1886.mesh"
                materials: [
                    m210209199_material,
                    cyan_material
                ]
            }
        }
        Node {
            id: driver_9110_1
            objectName: "driver-9110:1"
            x: -5.904678821563721
            y: -2.161660671234131
            z: -0.06177535280585289
            rotation: Qt.quaternion(0.696555, 5.35542e-14, 0.717503, 4.21469e-08)
            scale.x: 100
            scale.y: 100
            scale.z: 100
            Model {
                id: s_lido1_021
                objectName: "Sólido1.021"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido1_021_mesh1890.mesh"
                materials: [
                    lightGray_material,
                    default_material
                ]
            }
            Model {
                id: s_lido10_006
                objectName: "Sólido10.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido10_006_mesh.mesh"
                materials: [
                    default_material,
                    smoothBlack_material
                ]
            }
            Model {
                id: s_lido11_006
                objectName: "Sólido11.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido11_006_mesh.mesh"
                materials: [
                    default_material,
                    smoothBlack_material
                ]
            }
            Model {
                id: s_lido12_005
                objectName: "Sólido12.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido12_005_mesh.mesh"
                materials: [
                    default_material,
                    smoothBlack_material
                ]
            }
            Model {
                id: s_lido13_005
                objectName: "Sólido13.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido13_005_mesh.mesh"
                materials: [
                    default_material,
                    smoothBlack_material
                ]
            }
            Model {
                id: s_lido14_005
                objectName: "Sólido14.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido14_005_mesh.mesh"
                materials: [
                    default_material,
                    brindle_material
                ]
            }
            Model {
                id: s_lido15_005
                objectName: "Sólido15.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido15_005_mesh.mesh"
                materials: [
                    default_material,
                    brindle_material
                ]
            }
            Model {
                id: s_lido16_005
                objectName: "Sólido16.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido16_005_mesh.mesh"
                materials: [
                    default_material,
                    brindle_material
                ]
            }
            Model {
                id: s_lido17_005
                objectName: "Sólido17.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido17_005_mesh.mesh"
                materials: [
                    default_material,
                    smoothBlack_material
                ]
            }
            Model {
                id: s_lido18_005
                objectName: "Sólido18.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido18_005_mesh1908.mesh"
                materials: [
                    default_material,
                    brindle_material
                ]
            }
            Model {
                id: s_lido19_005
                objectName: "Sólido19.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido19_005_mesh1910.mesh"
                materials: [
                    default_material,
                    brindle_material
                ]
            }
            Model {
                id: s_lido2_006
                objectName: "Sólido2.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido2_006_mesh.mesh"
                materials: [
                    lightGray_material,
                    default_material
                ]
            }
            Model {
                id: s_lido20_005
                objectName: "Sólido20.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido20_005_mesh.mesh"
                materials: [
                    default_material,
                    smoothBlack_material
                ]
            }
            Model {
                id: s_lido21_005
                objectName: "Sólido21.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido21_005_mesh.mesh"
                materials: [
                    default_material,
                    smoothBlack_material
                ]
            }
            Model {
                id: s_lido22_005
                objectName: "Sólido22.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido22_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido23_005
                objectName: "Sólido23.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido23_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido24_005
                objectName: "Sólido24.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido24_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido25_005
                objectName: "Sólido25.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido25_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido26_005
                objectName: "Sólido26.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido26_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido27_005
                objectName: "Sólido27.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido27_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido28_005
                objectName: "Sólido28.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido28_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido29_005
                objectName: "Sólido29.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido29_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido3_006
                objectName: "Sólido3.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido3_006_mesh1934.mesh"
                materials: [
                    lightGray_material,
                    default_material
                ]
            }
            Model {
                id: s_lido30_005
                objectName: "Sólido30.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido30_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido31_005
                objectName: "Sólido31.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido31_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido32_005
                objectName: "Sólido32.005"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido32_004_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido33_003
                objectName: "Sólido33.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido33_003_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido34_003
                objectName: "Sólido34.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido34_003_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido35_003
                objectName: "Sólido35.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido35_003_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido36_003
                objectName: "Sólido36.003"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido36_003_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido37_002
                objectName: "Sólido37.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido37_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido38_002
                objectName: "Sólido38.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido38_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido39_002
                objectName: "Sólido39.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido39_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido4_006
                objectName: "Sólido4.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido4_006_mesh1956.mesh"
                materials: [
                    lightGray_material,
                    default_material
                ]
            }
            Model {
                id: s_lido40_002
                objectName: "Sólido40.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido40_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido41_002
                objectName: "Sólido41.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido41_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido42_002
                objectName: "Sólido42.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido42_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido43_002
                objectName: "Sólido43.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido43_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido44_002
                objectName: "Sólido44.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido44_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido45_002
                objectName: "Sólido45.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido45_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido46_002
                objectName: "Sólido46.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido46_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido47_002
                objectName: "Sólido47.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido47_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido48_002
                objectName: "Sólido48.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido48_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido49_002
                objectName: "Sólido49.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido49_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido5_006
                objectName: "Sólido5.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido5_006_mesh1978.mesh"
                materials: [
                    lightGray_material,
                    default_material
                ]
            }
            Model {
                id: s_lido50_002
                objectName: "Sólido50.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido50_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido51_002
                objectName: "Sólido51.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido51_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido52_002
                objectName: "Sólido52.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido52_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido53_002
                objectName: "Sólido53.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido53_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido54_002
                objectName: "Sólido54.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido54_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido55_002
                objectName: "Sólido55.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido55_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido56_002
                objectName: "Sólido56.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido56_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido57_002
                objectName: "Sólido57.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido57_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido58_002
                objectName: "Sólido58.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido58_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido59_002
                objectName: "Sólido59.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido59_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido6_006
                objectName: "Sólido6.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido6_006_mesh2000.mesh"
                materials: [
                    lightGray_material,
                    default_material
                ]
            }
            Model {
                id: s_lido60_002
                objectName: "Sólido60.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido60_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido61_002
                objectName: "Sólido61.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido61_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido62_002
                objectName: "Sólido62.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido62_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido63_002
                objectName: "Sólido63.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido63_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido64_002
                objectName: "Sólido64.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido64_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido65_002
                objectName: "Sólido65.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido65_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido66_002
                objectName: "Sólido66.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido66_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido67_002
                objectName: "Sólido67.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido67_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido68_002
                objectName: "Sólido68.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido68_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido69_002
                objectName: "Sólido69.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido69_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido7_006
                objectName: "Sólido7.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido7_006_mesh.mesh"
                materials: [
                    default_material,
                    smoothBlack_material
                ]
            }
            Model {
                id: s_lido70_002
                objectName: "Sólido70.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido70_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido71_002
                objectName: "Sólido71.002"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido71_002_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido72_001
                objectName: "Sólido72.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido72_001_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido73_001
                objectName: "Sólido73.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido73_001_mesh.mesh"
                materials: [
                    default_material
                ]
            }
            Model {
                id: s_lido74_001
                objectName: "Sólido74.001"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido74_001_mesh.mesh"
                materials: [
                    lightGray_material,
                    default_material,
                    darkGreen_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido8_006
                objectName: "Sólido8.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido8_006_mesh.mesh"
                materials: [
                    lightGray_material,
                    default_material,
                    darkGreen_material,
                    gray_material
                ]
            }
            Model {
                id: s_lido9_006
                objectName: "Sólido9.006"
                scale.x: 0.01
                scale.y: 0.01
                scale.z: 0.01
                source: "meshes/s_lido9_006_mesh.mesh"
                materials: [
                    default_material,
                    clearBlue_material
                ]
            }
        }
    }

    Node {
        id: __materialLibrary__

        PrincipledMaterial {
            id: m247224153_material
            objectName: "M247224153"
            baseColor: "#ffedbe51"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m262626_material
            objectName: "M262626"
            baseColor: "#ff030303"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: semiPolished_material
            objectName: "SemiPolished"
            baseColor: "#ff83807d"
            roughness: 0.6000000238418579
        }

        PrincipledMaterial {
            id: black_material
            objectName: "Black"
            baseColor: "#ff000000"
            roughness: 0.5
            normalMap: __texture
        }

        PrincipledMaterial {
            id: m515151_material
            objectName: "M515151"
            baseColor: "#ff080808"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m20417082_material
            objectName: "M20417082"
            baseColor: "#ff9a6716"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: smoothPurple_material
            objectName: "SmoothPurple"
            // baseColor: "#ff370037"
            baseColor: "#ff895daa"
            roughness: 0.800000011920929
        }

        PrincipledMaterial {
            id: m100153100_material
            objectName: "M100153100"
            baseColor: "#ff205120"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m128128128_material
            objectName: "M128128128"
            baseColor: "#ff373737"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m189198204_material
            objectName: "M189198204"
            baseColor: "#ff82909a"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m245245246_material
            objectName: "M245245246"
            baseColor: "#ffe9e9eb"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m243203124_material
            objectName: "M243203124"
            baseColor: "#ffe59833"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m252525_material
            objectName: "M252525"
            baseColor: "#ff020202"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m23217335_material
            objectName: "M23217335"
            baseColor: "#ffce6b04"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m4859150_001_material
            objectName: "M4859150.001"
            baseColor: "#ff080b4e"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m646464_material
            objectName: "M646464"
            baseColor: "#ff0d0d0d"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m1921920_material
            objectName: "M1921920"
            baseColor: "#ff868600"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m192192192_material
            objectName: "M192192192"
            baseColor: "#ff868686"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m160160160_material
            objectName: "M160160160"
            baseColor: "#ff5a5a5a"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: smoothMediumGray_material
            objectName: "SmoothMediumGray"
            baseColor: "#ff373737"
            roughness: 0.800000011920929
        }

        PrincipledMaterial {
            id: gray_material
            objectName: "Gray"
            // baseColor: "#ff242424"
            baseColor: "#ff373c3f"
            roughness: 0.699999988079071
        }

        PrincipledMaterial {
            id: m2210716_material
            objectName: "M2210716"
            baseColor: "#ff022501"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m204204204_003_material
            objectName: "M204204204.003"
            baseColor: "#ff9a9a9a"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m255255255_material
            objectName: "M255255255"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m231231231_material
            objectName: "M231231231"
            baseColor: "#ffcccccc"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m202020_material
            objectName: "M202020"
            baseColor: "#ff020202"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m1065540_material
            objectName: "M1065540"
            baseColor: "#ff250a05"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m404040_material
            objectName: "M404040"
            baseColor: "#ff050505"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m232239160_material
            objectName: "M232239160"
            baseColor: "#ffcedc5a"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m118118118_material
            objectName: "M118118118"
            baseColor: "#ff2e2e2e"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m333333_material
            objectName: "M333333"
            baseColor: "#ff040404"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m191189187_material
            objectName: "M191189187"
            baseColor: "#ff85827f"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m244229167_material
            objectName: "M244229167"
            baseColor: "#ffe7c863"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m211515_material
            objectName: "M211515"
            baseColor: "#ff020101"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m2551910_material
            objectName: "M2551910"
            baseColor: "#ffff8500"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m204204204_001_material
            objectName: "M204204204.001"
            baseColor: "#ff9a9a9a"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: smoothBlack_material
            objectName: "SmoothBlack"
            baseColor: "#ff000000"
            roughness: 0.800000011920929
        }

        PrincipledMaterial {
            id: gold_material
            objectName: "Gold"
            baseColor: "#ff734400"
            roughness: 0.699999988079071
            normalMap: __texture756
        }

        PrincipledMaterial {
            id: clearBlue_material
            objectName: "ClearBlue"
            // baseColor: "#ff000ce0"
            baseColor: "#ff193c67"
        }

        PrincipledMaterial {
            id: brindle_material
            objectName: "Brindle"
            baseColor: "#ff5f3c1f"
            roughness: 0.42500001192092896
            normalMap: __texture756
        }

        PrincipledMaterial {
            id: blueWallPaintGlossy_material
            objectName: "BlueWallPaintGlossy"
            // baseColor: "#ff0205ef"
            baseColor: "#ff193c67"
            roughness: 0.47999995946884155
        }

        PrincipledMaterial {
            id: m000_material
            objectName: "M000"
            baseColor: "#ff000000"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m204204204_002_material
            objectName: "M204204204.002"
            baseColor: "#ff9a9a9a"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m190188186_material
            objectName: "M190188186"
            baseColor: "#ff83807d"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m224223219_material
            objectName: "M224223219"
            baseColor: "#ffbebcb5"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m363634_material
            objectName: "M363634"
            baseColor: "#ff040404"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m15613582_material
            objectName: "M15613582"
            baseColor: "#ff553e16"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: default_material
            objectName: "Default"
            baseColor: "#ff858585"
            roughness: 0.699999988079071
        }

        PrincipledMaterial {
            id: m204204204_material
            objectName: "M204204204"
            baseColor: "#ff9a9a9a"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m1888047_material
            objectName: "M1888047"
            baseColor: "#ff801407"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m153153153_material
            objectName: "M153153153"
            baseColor: "#ff515151"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m2437248_material
            objectName: "M2437248"
            baseColor: "#ff0205ef"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m18013989_material
            objectName: "M18013989"
            baseColor: "#ff744219"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m555_material
            objectName: "M555"
            baseColor: "#ff000000"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m15613581_material
            objectName: "M15613581"
            baseColor: "#ff553e15"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m178178178_material
            objectName: "M178178178"
            baseColor: "#ff727272"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: glossyBlack_material
            objectName: "GlossyBlack"
            baseColor: "#ff000000"
            roughness: 0.6600000262260437
        }

        PrincipledMaterial {
            id: m0115170_material
            objectName: "M0115170"
            baseColor: "#ff002c67"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m251250245_material
            objectName: "M251250245"
            baseColor: "#fff6f4e9"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m505050_material
            objectName: "M505050"
            baseColor: "#ff080808"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m246246243_material
            objectName: "M246246243"
            baseColor: "#ffebebe5"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m4859150_material
            objectName: "M4859150"
            baseColor: "#ff080b4e"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m2001427_material
            objectName: "M2001427"
            baseColor: "#ff934501"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: rubberBlack_material
            objectName: "RubberBlack"
            baseColor: "#ff0d0d0d"
            roughness: 0.75
        }

        PrincipledMaterial {
            id: m393939_material
            objectName: "M393939"
            baseColor: "#ff050505"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m252525_001_material
            objectName: "M252525.001"
            baseColor: "#ff020202"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m209204192_material
            objectName: "M209204192"
            baseColor: "#ffa39a86"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m4859150_002_material
            objectName: "M4859150.002"
            baseColor: "#ff080b4e"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m383737_material
            objectName: "M383737"
            baseColor: "#ff050505"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m219188126_material
            objectName: "M219188126"
            baseColor: "#ffb58035"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m210209199_material
            objectName: "M210209199"
            baseColor: "#ffa4a392"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: cyan_material
            objectName: "Cyan"
            // baseColor: "#ff083ec4"
            baseColor: "#ff2c7cab"
            roughness: 0.42500001192092896
            normalMap: __texture756
        }

        PrincipledMaterial {
            id: m225181125_material
            objectName: "M225181125"
            baseColor: "#ffc07634"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: m80124105_material
            objectName: "M80124105"
            baseColor: "#ff143324"
            roughness: 0.8999999761581421
        }

        PrincipledMaterial {
            id: lightGray_material
            objectName: "LightGray"
            baseColor: "#ff515151"
            roughness: 0.699999988079071
            normalMap: __texture756
        }

        PrincipledMaterial {
            id: darkGreen_material
            objectName: "DarkGreen"
            baseColor: "#ff015601"
            roughness: 0.699999988079071
        }
    }

    // Animations:
}
