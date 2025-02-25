import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: forLoopBlock
    name: "For loop"
    width: 150
    height: 70
    color: "lightblue"

    Component.onCompleted: {
        forLoopBlock.registerSlot(r1Anchor.update)
        forLoopBlock.registerSlot(r2Anchor.update)
    }

    Column {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 3
        spacing: 3

        Row {
            spacing: 3
            anchors.right: parent.right
            Text {
                text: "from"
                color: "#62717E"
                font.pointSize: 10
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: startField
                width: 80
                placeholderText: "start"
            }

            Anchor {
                id: r1Anchor
            }
        }

        Row {
            spacing: 3
            anchors.right: parent.right
            Text {
                text: "to"
                color: "#62717E"
                font.pointSize: 10
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: endField
                width: 80
                placeholderText: "end"
            }

            Anchor {
                id: r2Anchor
            }
        }
    }
}
