import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: ifBlock
    name: "If"
    width: 110
    height: 50
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: false

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

        anchors.left: parent.left
        anchors.leftMargin: 1.5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 1.5

        anchorType: "data"
        anchorDirection: "left"
    }

    Anchor {
        id: trueAnchor
        objectName: "trueAnchor"

        anchors.right: parent.right
        anchors.rightMargin: 1.5
        anchors.bottom: falseAnchor.top
        anchors.bottomMargin: 1.5

        anchorType: "anchor"
        anchorDirection: "right"
    }

    Anchor {
        id: falseAnchor
        objectName: "falseAnchor"

        anchors.right: parent.right
        anchors.rightMargin: 1.5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 1.5

        anchorType: "anchor"
        anchorDirection: "right"
    }
}
