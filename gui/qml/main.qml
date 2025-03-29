import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 1280
    height: 720
    visible: true

    Rectangle {
        id: menuBar
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        width: parent.width

        border.color: "black"
        border.width: 1

        height: 40
    }

    Rectangle {
        id: searchableContainer2
        width: parent.width * 0.75
        height: parent.height - 40
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        DraggableCanvas {
            id: draggableCanvas
        }
    }

    Rectangle {
        id: searchableContainer
        width: parent.width * 0.25
        height: parent.height - 40
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        z: 2

        SearchableList {
            anchors.fill: parent
            draggableCanvas : draggableCanvas
            rootObj: searchableContainer.parent
        }
    }
}