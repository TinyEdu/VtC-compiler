import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: callEventBlock
    name: "Call"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: false

    EditableConfirmField {
        id: eventField
        objectName: "eventField"
        placeholderText: "event"

        anchors.horizontalCenter: parent.horizontalCenter

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5

        width: parent.width * 0.64
        height: parent.height * 0.5
    }
}
