// main.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 1280
    height: 720
    visible: true

    BezierConnectionFactory {
        id: bezierFactory
        draggableCanvas: draggableCanvas
    }

    Rectangle {
        id: draggableCanvasContainer
        width: parent.width * 0.5
        height: parent.height

        anchors {
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }

        DraggableCanvas {
            id: draggableCanvas
            anchors.fill: parent
        }
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
