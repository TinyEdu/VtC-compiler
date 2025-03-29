import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 800
    height: 600
    visible: true

    DraggableCanvas {
        id: draggableCanvas
    }

    Rectangle {
        id: searchableContainer
        width: parent.width * 0.3
        height: parent.height
        anchors.left: parent.left

        SearchableList {
            anchors.fill: parent
            draggableCanvas : draggableCanvas.parent
        }
    }
}