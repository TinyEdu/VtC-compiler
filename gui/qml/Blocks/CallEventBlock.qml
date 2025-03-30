import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: callEventBlock
    name: "Call"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: false

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
