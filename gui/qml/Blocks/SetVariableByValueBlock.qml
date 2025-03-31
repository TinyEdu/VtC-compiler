import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: setVariableByValueBlock
    name: "Set Var"
    width: 110
    height: 76
    color: "lightblue"

    EditableConfirmField {
        id: variableNameField
        objectName: "variableNameField"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: valueField.top
        anchors.bottomMargin: 4

        placeholderText: "Variable name"

        width: parent.width - 6
        height: 25
    }

    EditableConfirmField {
        id: valueField
        objectName: "valueField"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3

        placeholderText: "New value"

        width: parent.width - 6
        height: 25
    }
}