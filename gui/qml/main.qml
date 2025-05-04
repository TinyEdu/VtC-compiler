// main.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import GuiController

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
            left: parent.left
            right: parent.right
            top: parent.top
        }

        height: 40
        color: "#84818E"
        border.color: "black"
        border.width: 1

        // Button width and spacing
        property int buttonWidth: width * 0.125
        property int buttonSpacing: 4

        EditableButton {
            id: runButton
            text: "RUN"
            width: menuBar.buttonWidth
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            onClicked: {
                textDisplay.append(GuiController.run())
            }

            backgroundColor: "#50C878"
            pressedBackgroundColor: "#00A86B"
            borderColor: "#50C878"
            textColor: "#ffffff"
        }

        EditableButton {
            id: centerButton
            text: "Center"
            width: menuBar.buttonWidth
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: runButton.left
            anchors.rightMargin: menuBar.buttonSpacing
            onClicked: GuiController.center()
        }

        EditableButton {
            id: loadButton
            text: "Load"
            width: menuBar.buttonWidth
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: centerButton.left
            anchors.rightMargin: menuBar.buttonSpacing
            onClicked: GuiController.load()
        }

        EditableButton {
            id: saveButton
            text: "Save"
            width: menuBar.buttonWidth
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: loadButton.left
            anchors.rightMargin: menuBar.buttonSpacing
            onClicked: GuiController.save()
        }
    }


    Rectangle {
        id: draggableCanvasContainer
        width: parent.width * 0.75
        height: parent.height * 0.75 - 40
        border.color: "black"
        border.width: 1
        anchors {
            right: parent.right
            top: parent.top
            topMargin: 40
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

    Rectangle {
        id: textDisplayContainer
        height: parent.height * 0.25

        border.color: "black"
        border.width: 1

        anchors {
            left: searchableListContainer.right
            right: parent.right
            bottom: parent.bottom
        }

        TerminalDisplay {
            id: textDisplay
            anchors.fill: parent
            backgroundColor: "#ffffff"
            textColor: "#333333"
        }
    }
}