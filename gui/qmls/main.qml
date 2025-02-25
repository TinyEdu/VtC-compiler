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
                x: 15
                y: 20
            }

            EndBlock {
                x: 15
                y: 100
            }

            CallEventBlock {
                x: 15
                y: 180
            }

            ListenEventBlock {
                x: 15
                y: 260
            }

            BinaryOperationBlock {
                x: 15
                y: 340
            }

            AddingBinaryOperationBlock {
                x: 15
                y: 460
            }

            UnaryOperationBlock {
                x: 150
                y: 20
            }

            NegationUnaryOperationBlock {
                x: 150
                y: 100
            }

            CreateVariableBySignalBlock {
                x: 150
                y: 180
            }

            CreateVariableByValueBlock {
                x: 150
                y: 270
            }

            IfBlock {
                x: 150
                y: 370
            }

            ValueBlock {
                x: 150
                y: 460
            }

            GetVariableBlock {
                x: 150
                y: 530
            }

            SetVariableBySignalBlock {
                x: 300
                y: 20
            }

            SetVariableByValueBlock {
                x: 300
                y: 120
            }

            SkipBlock {
                x: 300
                y: 210
            }

            BreakBlock {
                x: 300
                y: 290
            }
        }
    }
}
