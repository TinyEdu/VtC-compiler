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

    Rectangle {
        id: searchableListContainer
        width: parent.width * 0.25
        height: parent.height
        anchors {
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }

        SearchableList {
            id: searchableList
            anchors.fill: parent
        }
    }
}