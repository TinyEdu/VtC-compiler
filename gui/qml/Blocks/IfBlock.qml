import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: ifBlock
    name: "If"
    width: 130
    height: 70
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: false

    Component.onCompleted: {
        ifBlock.registerSlot(conditionAnchor.update)
        ifBlock.registerSlot(trueAnchor.update)
        ifBlock.registerSlot(falseAnchor.update)
    }

    Row {
        spacing: 8
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 4

        Column {
            spacing: 4
            Text {
                text: "Condition"
                color: "#62717E"
                font.bold: true
                font.pointSize: 10

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Anchor {
                id: conditionAnchor
            }
        }

        Column {
            spacing: 4
            Text {
                text: "True"
                color: "#62717E"
                font.bold: true
                font.pointSize: 10

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                text: "False"
                color: "#62717E"
                font.bold: true
                font.pointSize: 10

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Column {
            spacing: 4
            Anchor {
                id: trueAnchor
            }

            Anchor {
                id: falseAnchor
            }
        }
    }
}
