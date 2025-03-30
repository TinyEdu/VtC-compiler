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
        valueBlock.registerSlot(passingAnchor.update)
    }

    TextField {
        id: valueField
        objectName: "valueField"
        placeholderText: "value"

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottomMargin: 8

        width: valueBlock.width * 0.64
        height: valueBlock.height * 0.33
    }

    Anchor {
        id: passingAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.bottomMargin: 8

        width: valueBlock.height * 0.33
        height: valueBlock.height * 0.33
    }
}
