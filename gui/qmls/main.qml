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

            CallEventBlock {
                x: 100
                y: 100
            }

            ListenEventBlock {
                x: 100
                y: 200
            }

            StartBlock {
                x: 100
                y: 300
            }

            EndBlock {
                x: 100
                y: 400
            }

            BinaryOperationBlock {
                x: 230
                y: 200
            }

            AddingBinaryOperationBlock {
                x: 230
                y: 330
            }

            UnaryOperationBlock {
                x: 330
                y: 330
            }

            NegationUnaryOperationBlock {
                x: 330
                y: 200
            }

            CreateVariableBySignalBlock {
                x: 100
                y: 500
            }

            CreateVariableByValueBlock {
                x: 100
                y: 500
            }
        }
    }
}
