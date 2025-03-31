import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: getVariableBlock
    name: "Get Var"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: false
    enableRightAnchor: false

    Component.onCompleted: {
        getVariableBlock.registerSlot(passingAnchor.update)
    }

    EditableConfirmField {
        id: variableField
        objectName: "variableField"

        anchors.verticalCenter: passingAnchor.verticalCenter

        anchors.left: parent.left
        anchors.leftMargin: 3

        width: parent.width * 0.64
        height: parent.height * 0.5
    }

    Anchor {
        id: passingAnchor
        objectName: "variableField"

        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.bottomMargin: 8

        border.width: parent.border.width

        width: parent.height * 0.33
        height: parent.height * 0.33
    }
}
