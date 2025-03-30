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
        id: callSelector
        width: 80
        placeholderText: "Call name"

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 3
    }
}
