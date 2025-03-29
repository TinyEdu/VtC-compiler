import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 1280
    height: 720
    visible: true

    Rectangle {
        id: searchableContainer2
        width: parent.width * 0.75
        height: parent.height
        anchors.right: parent.right

        DraggableCanvas {
            id: draggableCanvas
        }
    }

    Rectangle {
        id: searchableContainer
        width: parent.width * 0.25
        height: parent.height
        anchors.left: parent.left
        z: 2

        SearchableList {
            anchors.fill: parent
            draggableCanvas : draggableCanvas
            rootObj: searchableContainer.parent
        }
    }
}