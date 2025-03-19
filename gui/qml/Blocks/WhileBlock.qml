import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: whileBlock
    name: "While"
    width: 130
    height: 70
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: true

    Component.onCompleted: {
        whileBlock.registerSlot(r1Anchor.update)
        whileBlock.registerSlot(r2Anchor.update)
        whileBlock.registerSlot(l1Anchor.update)
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
                id: l1Anchor
            }
        }

        Column {
            spacing: 4
            Text {
                text: "Start"
                color: "#62717E"
                font.bold: true
                font.pointSize: 10

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                text: "End"
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
                id: r1Anchor
            }

            Anchor {
                id: r2Anchor
            }
        }
    }
}
