import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: valueBlock
    name: "Value"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: false
    enableRightAnchor: false

    Component.onCompleted: {
        valueBlock.registerSlot(passingAnchor.update)
    }

    EditableConfirmField {
        id: valueField
        objectName: "valueField"

        anchors.verticalCenter: passingAnchor.verticalCenter

        anchors.left: parent.left
        anchors.leftMargin: 3

        width: valueBlock.width * 0.64
        height: valueBlock.height * 0.5
    }

    Anchor {
        id: passingAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.bottomMargin: 8

        border.width: parent.border.width

        width: valueBlock.height * 0.33
        height: valueBlock.height * 0.33
    }
}
