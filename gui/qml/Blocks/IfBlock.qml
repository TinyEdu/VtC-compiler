import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: ifBlock
    name: "If"
    width: 110
    height: 50
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: false

    Component.onCompleted: {
        ifBlock.registerSlot(conditionAnchor)
        ifBlock.registerSlot(trueAnchor)
        ifBlock.registerSlot(falseAnchor)
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
        text: "True"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: trueAnchor.verticalCenter
        anchors.right: trueAnchor.left
        anchors.rightMargin: 2

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        text: "False"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: falseAnchor.verticalCenter
        anchors.right: falseAnchor.left
        anchors.rightMargin: 2

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Anchor {
        id: conditionAnchor
        objectName: "conditionAnchor"

        border.width: ifBlock.border.width

        anchors.left: parent.left
        anchors.leftMargin: 1.5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 1.5

        width: ifBlock.height * 0.29
        height: ifBlock.height * 0.29

        anchorType: "data"
        anchorDirection: "left"
    }

    Anchor {
        id: trueAnchor
        objectName: "trueAnchor"

        border.width: ifBlock.border.width

        anchors.right: parent.right
        anchors.rightMargin: 1.5

        anchors.bottom: falseAnchor.top
        anchors.bottomMargin: 1.5

        width: ifBlock.height * 0.29
        height: ifBlock.height * 0.29

        anchorType: "anchor"
        anchorDirection: "right"
    }

    Anchor {
        id: falseAnchor
        objectName: "falseAnchor"

        border.width: ifBlock.border.width

        anchors.right: parent.right
        anchors.rightMargin: 1.5

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 1.5

        width: ifBlock.height * 0.29
        height: ifBlock.height * 0.29

        anchorType: "anchor"
        anchorDirection: "right"
    }
}
