import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: printBlock
    name: "Print"
    width: 90
    height: 50
    color: "lightblue"

    EditableConfirmField {
        id: valueField
        objectName: "valueField"

        anchors.horizontalCenter: parent.horizontalCenter

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5

        width: parent.width * 0.64
        height: parent.height * 0.5
    }
}
