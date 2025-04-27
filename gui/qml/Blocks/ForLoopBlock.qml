import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: forLoop
    name: "For Loop"
    width: 150
    height: 103
    color: "lightblue"

    Text {
        text: "Inc"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: incrementAnchor.verticalCenter
        anchors.right: incrementAnchor.left
        anchors.rightMargin: 3

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        text: "Start"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: fromField.verticalCenter
        anchors.right: startAnchor.left
        anchors.rightMargin: 3

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        text: "End"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: toField.verticalCenter
        anchors.right: endAnchor.left
        anchors.rightMargin: 3

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Anchor {
        id: incrementAnchor
        objectName: "incrementAnchor"

        anchors.verticalCenter: incrementField.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 3

        anchorType: "data"
        anchorDirection: "right"
    }

    Anchor {
        id: startAnchor
        objectName: "startAnchor"

        anchors.verticalCenter: fromField.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 3

        anchorType: "anchor"
        anchorDirection: "right"
    }

    Anchor {
        id: endAnchor
        objectName: "endAnchor"

        anchors.verticalCenter: toField.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 3

        anchorType: "anchor"
        anchorDirection: "left"
    }

    EditableConfirmField {
        id: fromField
        objectName: "fromField"

        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottom: toField.top
        anchors.bottomMargin: 3

        placeholderText: "From"

        width: parent.width * 0.6
        height: 25
    }

    EditableConfirmField {
        id: toField
        objectName: "toField"

        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottom: incrementField.top
        anchors.bottomMargin: 3

        placeholderText: "To"

        width: parent.width * 0.6
        height: 25
    }

    EditableConfirmField {
        id: incrementField
        objectName: "incrementField"

        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3

        placeholderText: "Increment"

        width: parent.width * 0.6
        height: 25
    }
}
