import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: createVariableByValueBlock
    name: "Create"
    width: 150
    height: 100
    color: "lightblue"

    Component.onCompleted: {
        createVariableByValueBlock.registerSlot(rAnchor.update)
        createVariableByValueBlock.registerSlot(l1Anchor.update)
        createVariableByValueBlock.registerSlot(l2Anchor.update)
    }

    Anchor {
        id: rAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 20
    }

    Anchor {
        id: l1Anchor
        anchors.bottom: parent.bottom
        anchors.left: parent.left
    }

    Anchor {
        id: l2Anchor
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 40
    }

    property bool isFrozen: false

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 5
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
                horizontalAlignment: Text.AlignRight
            }
        }

        TextField {
            id: initialValue
            width: 100
            placeholderText: "initial value"
            enabled: !isFrozen
            horizontalAlignment: Text.AlignRight
        }
    }
}
