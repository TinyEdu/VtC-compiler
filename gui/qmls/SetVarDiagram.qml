import QtQuick 6.0
import QtQuick.Controls 6.0

BlockDiagram {
    id: setVarDiagram
    name: "Set Variable"
    width: 240
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
        height: 20
        spacing: 5

        Button {
            id: freezeButton
            width: 20
            height: 20
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

        ComboBox {
            id: typeSelector
            model: ["Integer", "String", "Float"]
            width: 50
            enabled: !isFrozen

            onCurrentIndexChanged: {
                console.log("Selected type: " + typeSelector.currentText)
            }
        }
    }

    property bool isFrozen: false
}
