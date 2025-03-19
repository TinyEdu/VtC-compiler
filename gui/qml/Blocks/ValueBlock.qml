import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: valueBlock
    name: "Value"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: false
    enableRightAnchor: false

    Component.onCompleted: {
        valueBlock.registerSlot(rAnchor.update)
    }

    TextField {
        id: nameField
        width: 80
        placeholderText: "value"

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 3
    }

    Anchor {
        id: rAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 3
    }
}
