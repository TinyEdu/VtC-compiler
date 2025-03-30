import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: listenEventBlock
    name: "Listen"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: false
    enableRightAnchor: true

    TextField {
        id: eventField
        objectName: "eventField"
        placeholderText: "event name"
        width: 80

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 3
    }
}
