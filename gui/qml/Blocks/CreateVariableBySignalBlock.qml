import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: createVariableBySignalBlock
    name: "Create Var"
    width: 120
    height: 70
    color: "lightblue"

    property bool isFrozen: false

    Component.onCompleted: {
        createVariableBySignalBlock.registerSlot(signalAnchor.update)
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 3
        spacing: 3

        Row {
            spacing: 3
            Button {
                id: freezeButton

                width: 20
                height: 20
                text: isFrozen ? "X" : "Y"
                hoverEnabled: false
                focusPolicy: Qt.NoFocus
                checkable: true
                checked: isFrozen

                onClicked: isFrozen = !isFrozen

                background: Rectangle {
                    color: freezeButton.checked ? "#999999" : "#eeeeee"
                    border.color: "#84818E"
                    border.width: 1.5
                    radius: 5
                }
            }

            TextField {
                id: nameField
                width: 80
                placeholderText: "name"
                enabled: !isFrozen
            }
        }

        Row {
            spacing: 3
            Anchor {
                id: signalAnchor
            }
            Text {
                text: "Initial value"
                color: "#62717E"
                font.pointSize: 10
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
