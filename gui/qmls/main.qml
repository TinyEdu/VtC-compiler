import QtQuick 2.15
import QtQuick.Controls 6.5
import QtQuick.Layouts 1.15


ApplicationWindow {
    visible: true
    width: 600
    height: 400
    title: "Draggable Blocks with Labels"

    ColumnLayout {
        anchors.fill: parent

        TabBar {
            id: tabBar
            Layout.fillWidth: true

            TabButton { text: "Board" }
            TabButton { text: "Text Box" }
        }

        SwipeView {
            id: swipeView
            Layout.fillWidth: true
            Layout.fillHeight: true
            currentIndex: tabBar.currentIndex

            // First Tab: Draggable Blocks
            Rectangle {
                id: board
                color: "#f5f5f5" // Light gray board
                border.color: "#ccc"
                border.width: 2

                // Add multiple MovableBlocks dynamically
                MovableBlock {
                    blockName: "Block 1"
                    x: 50
                    y: 50
                    boundaryParent: board
                }

                MovableBlock {
                    blockName: "Block 2"
                    x: 150
                    y: 150
                    boundaryParent: board
                }
            }

            // Second Tab: Text Box
            Rectangle {
                color: "#ffffff" // White background

                TextArea {
                    anchors.fill: parent
                    anchors.margins: 10
                    placeholderText: "Type something here..."
                    font.pixelSize: 16
                    wrapMode: TextEdit.WordWrap
                }
            }
        }
    }
}
