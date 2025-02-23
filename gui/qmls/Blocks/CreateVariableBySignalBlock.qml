import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: createVariableBySignalBlock
    name: "Set Variable"
    width: 150
    height: 100
    color: "lightblue"

    Component.onCompleted: {
        createVariableBySignalBlock.registerSlot(rAnchor.update)
        createVariableBySignalBlock.registerSlot(l1Anchor.update)
        createVariableBySignalBlock.registerSlot(l2Anchor.update)
    }

    Anchor {
        id: rAnchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 20
    }

    Anchor {
        id: l1Anchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.left: parent.left
    }

    Anchor {
        id: l2Anchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 40
    }

    Column {
        property bool isFrozen: false

        anchors.centerIn: parent
        spacing: 5

        Text {
            text: "Variable name:"
            color: "#62717E"
            font.bold: true
            font.pointSize: 10
            horizontalAlignment: Text.AlignHCenter
        }
        Row {
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
                placeholderText: "name"
                enabled: !isFrozen
            }
        }
    }

    property bool isFrozen: false
}
