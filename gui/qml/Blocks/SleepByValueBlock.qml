import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: sleepByValueBlock
    name: "Sleep"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: true

    TextField {
        id: nameField
        width: 80
        placeholderText: "value"

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 3
    }
}
