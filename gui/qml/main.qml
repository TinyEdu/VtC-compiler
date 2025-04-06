// main.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 1280
    height: 720
    visible: true

    Rectangle {
        id: draggableCanvasContainer
        border.width: 2
        anchors {
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        width: parent.width * 0.5
        height: parent.height

        DraggableCanvas {
            id: draggableCanvas
            anchors.fill: parent
        }
    }

    Rectangle {
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
        width: parent.width * 0.5
        height: parent.height
        color: "blue"
    }

    BlockCreator {
        id: blockCreator
        x: 30
        y: 40
        width: 42
        height: 383
        color: "gray"
    }
}
