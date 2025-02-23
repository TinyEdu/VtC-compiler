import QtQuick 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0
import QtQuick.Controls.Material 6.0

import "Blocks"
import "Blocks/Operations"

ApplicationWindow {
    Material.theme: Material.Light
    visible: true
    width: 800
    height: 600

    property var bezierConnections: []

    RowLayout {
        anchors.fill: parent

        // Left panel: Scrollable list
        ScrollView {
            Layout.preferredWidth: parent.width * 0.3
            Layout.fillHeight: true

            Column {
                width: parent.width
                spacing: 10

                Repeater {
                    model: ["Block 1", "Block 2", "Block 3", "Block 4"]
                    delegate: Button {
                        text: modelData
                        width: parent.width - 20
                    }
                }
            }
        }

        // Right panel: Block diagram workspace
        Rectangle {
            id: draggableCanvas
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "lightgray"

            StartBlock {
                x: 50
                y: 20
            }

            EndBlock {
                x: 50
                y: 100
            }

            CallEventBlock {
                x: 50
                y: 180
            }

            ListenEventBlock {
                x: 50
                y: 260
            }

            BinaryOperationBlock {
                x: 50
                y: 340
            }

            AddingBinaryOperationBlock {
                x: 50
                y: 460
            }

            UnaryOperationBlock {
                x: 200
                y: 20
            }

            NegationUnaryOperationBlock {
                x: 200
                y: 100
            }

            CreateVariableBySignalBlock {
                x: 200
                y: 180
            }

            CreateVariableByValueBlock {
                x: 200
                y: 310
            }
        }
    }
}
