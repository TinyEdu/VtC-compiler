import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: setVariableBySignalBlock
    name: "Set Var"
    width: 110
    height: 70
    color: "lightblue"


    Component.onCompleted: {
        setVariableBySignalBlock.registerSlot(valueAnchor.update)
    }

    EditableConfirmField {
        id: variableNameField
        objectName: "variableNameField"

        anchors.left: valueAnchor.left
        anchors.bottom: valueAnchor.top
        anchors.bottomMargin: 4

        placeholderText: "Variable name"

        width: parent.width - 6
        height: 25
    }

    Anchor {
        id: valueAnchor
        objectName: "valueAnchor"

        border.width: parent.border.width

        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4

        width: 16
        height: 16

        anchorType: "data"
        anchorDirection: "left"
    }

    Text {
        text: "New value"
        color: "#62717E"
        font.bold: true
        font.pointSize: 8

        anchors.verticalCenter: valueAnchor.verticalCenter
        anchors.left: valueAnchor.right
        anchors.leftMargin: 3

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
