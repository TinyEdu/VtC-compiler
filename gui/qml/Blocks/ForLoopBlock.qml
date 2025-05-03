import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: forLoop
    name: "For Loop"
    width: 150
    height: 80
    color: "lightblue"

    EditableConfirmField {
        id: fromField
        objectName: "fromField"
        placeholderText: "From"

        anchors.left: parent.left
        anchors.leftMargin: 4
        anchors.top: parent.top
        anchors.topMargin: 20

        width: (parent.width - 4 * 4) / 3
        height: 25
    }

    EditableConfirmField {
        id: toField
        objectName: "toField"
        placeholderText: "To"

        anchors.left: fromField.right
        anchors.leftMargin: 4
        anchors.top: parent.top
        anchors.topMargin: 20

        width: (parent.width - 4 * 4) / 3
        height: 25
    }

    EditableConfirmField {
        id: stepField
        objectName: "stepField"
        placeholderText: "Step"

        anchors.left: toField.right
        anchors.leftMargin: 4
        anchors.top: parent.top
        anchors.topMargin: 20

        width: (parent.width - 4 * 4) / 3
        height: 25
    }

    EditableConfirmField {
        id: indexName
        objectName: "indexName"
        placeholderText: "Index Name"

        anchors.left: parent.left
        anchors.leftMargin: 4
        anchors.top: fromField.bottom
        anchors.topMargin: 4

        width: fromField.width * 2 + 4
        height: 25
    }

    Text {
        text: "Start"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: indexName.verticalCenter
        anchors.right: startAnchor.left
        anchors.rightMargin: 3

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Anchor {
        id: startAnchor
        objectName: "startAnchor"

        anchors.verticalCenter: indexName.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 1

        anchorType: "anchor"
        anchorDirection: "right"
    }
}
