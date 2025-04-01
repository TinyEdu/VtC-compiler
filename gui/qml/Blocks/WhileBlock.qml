import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: whileBlock
    name: "While"
    width: 110
    height: 50
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: true

    Component.onCompleted: {
        whileBlock.registerSlot(conditionAnchor.update)
        whileBlock.registerSlot(startAnchor.update)
        whileBlock.registerSlot(endAnchor.update)
    }

    Text {
        text: "Condition"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.left: conditionAnchor.left
        anchors.bottom: conditionAnchor.top
        anchors.bottomMargin: 2

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        text: "Start"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: startAnchor.verticalCenter
        anchors.right: startAnchor.left
        anchors.rightMargin: 2

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        text: "End"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: endAnchor.verticalCenter
        anchors.right: endAnchor.left
        anchors.rightMargin: 2

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Anchor {
        id: conditionAnchor
        objectName: "conditionAnchor"

        border.width: whileBlock.border.width

        anchors.left: parent.left
        anchors.leftMargin: 1.5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 1.5

        width: whileBlock.height * 0.29
        height: whileBlock.height * 0.29

        anchorType: "data"
        anchorDirection: "left"
    }

    Anchor {
        id: startAnchor
        objectName: "startAnchor"

        border.width: whileBlock.border.width

        anchors.right: parent.right
        anchors.rightMargin: 1.5

        anchors.bottom: endAnchor.top
        anchors.bottomMargin: 1.5

        width: whileBlock.height * 0.29
        height: whileBlock.height * 0.29

        anchorType: "anchor"
        anchorDirection: "right"
    }

    Anchor {
        id: endAnchor
        objectName: "endAnchor"

        border.width: whileBlock.border.width

        anchors.right: parent.right
        anchors.rightMargin: 1.5

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 1.5

        width: whileBlock.height * 0.29
        height: whileBlock.height * 0.29

        anchorType: "anchor"
        anchorDirection: "left"
    }
}

