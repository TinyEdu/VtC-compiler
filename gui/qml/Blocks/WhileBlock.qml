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

    Text {
        id: conditionText
        text: "Condition"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.right: startText.left
        anchors.verticalCenter: startText.verticalCenter
        anchors.rightMargin: 8

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: startText
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

    Anchor {
        id: conditionAnchor
        objectName: "conditionAnchor"

        anchors.right: conditionText.left
        anchors.rightMargin: 1.5
        anchors.verticalCenter: startAnchor.verticalCenter

        anchorType: "data"
        anchorDirection: "left"
    }

    Anchor {
        id: startAnchor
        objectName: "startAnchor"

        anchors.right: parent.right
        anchors.rightMargin: 1.5

        anchors.bottom: endAnchor.top
        anchors.bottomMargin: 1.5

        anchorType: "anchor"
        anchorDirection: "right"
    }
}
