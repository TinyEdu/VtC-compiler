import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: valueBlock
    name: "Value"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: false
    enableRightAnchor: false

    EditableConfirmField {
        id: valueField
        objectName: "valueField"

        anchors.verticalCenter: passingAnchor.verticalCenter

        anchors.left: parent.left
        anchors.leftMargin: 3

        width: parent.width * 0.64
        height: parent.height * 0.5
    }

    Anchor {
        id: passingAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.bottomMargin: 8

        border.width: parent.border.width

        width: parent.height * 0.33
        height: parent.height * 0.33

        anchorType: "data"
        anchorDirection: "right"
    }
}
