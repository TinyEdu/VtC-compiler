import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: createVariableBySignalBlock
    name: "Create Var"
    width: 110
    height: 70
    color: "lightblue"

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

        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4

        anchorType: "data"
        anchorDirection: "left"
    }

    Text {
        text: "Initial value"
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
