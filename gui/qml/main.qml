import QtQuick 6.0
import QtQuick.Controls 6.0

ApplicationWindow {
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Searchable BlockCreator List Example")

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