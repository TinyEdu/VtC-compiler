// main.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import ProgramSerializator

Window {
    width: 1280
    height: 720
    visible: true

    Item {
        id: dragLayer
        anchors.fill: parent
        z: 999999
    }

    BezierConnectionFactory {
        id: bezierFactory
        draggableCanvas: draggableCanvas
    }

    Rectangle {
        id: menuBar
        anchors {
            right: parent.right
            left: parent.left
            top: parent.top
        }

        height: 40
        width: parent.width

        border.color: "black"
        border.width: 1

        Button {
            id: saveButton
            text: "Save"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            width: parent.width * 0.25

            onClicked: ProgramSerializator.save()
        }
    }

    Rectangle {
        id: draggableCanvasContainer
        width: parent.width * 0.75
        height: parent.height - 40
        border.color: "black"
        border.width: 1
        anchors {
            right: parent.right
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
        height: parent.height - 39

        border.color: "black"
        border.width: 1

        anchors {
            left: parent.left
            bottom: parent.bottom
        }

        SearchableList {
            id: searchableList
            anchors.fill: parent
        }
    }
}