import QtQuick 6.0
import QtQuick.Window 6.0

Window {
    width: 800
    height: 600
    visible: true
    title: "Block Diagram Creator"

    Rectangle {
        id: draggableCanvas
        anchors.fill: parent
        color: "#FFFFFF"

        BlockCreator {
            id: blockCreator
            x: 20
            y: 20
            blockDiagramComponent: Qt.createComponent("Blocks/BreakBlock.qml")
        }
    }
}