import QtQuick 6.0
import QtQuick.Controls 6.0

BlockDiagram {
    id: setVarDiagram
    name: "Set Variable"
    width: 200
    height: 80
    color: "lightblue"

    Component.onCompleted: {
        setVarDiagram.registerSlot(anchor.update)
    }

    Anchor {
        id: anchor
        width: 15
        height: 15
        color: "white"
        radius: 5
        anchors.right: parent.right
        anchors.rightMargin: 15
        anchors.verticalCenter: parent.verticalCenter
    }

    Row {
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        height: 15
        spacing: 5

        Button {
            id: freezeButton
            width: 20
            height: 20 // Optional: Set a fixed height for uniformity
            text: isFrozen ? "/" : "o"
            hoverEnabled: false
            focusPolicy: Qt.NoFocus
            checkable: true
            checked: isFrozen

            onClicked: isFrozen = !isFrozen

            background: Rectangle {
                color: freezeButton.checked ? "#999999" : "#eeeeee"
                border.color: "black"
                border.width: 1
                radius: 5
            }
        }

        TextField {
            id: textField
            width: 80
            placeholderText: "Enter text"
            enabled: !isFrozen
        }
    }

    property bool isFrozen: false
}
