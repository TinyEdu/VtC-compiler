import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: printBlock
    name: "Print"
    width: 90
    height: 50
    color: "lightblue"

    property bool isFrozen: false

    Component.onCompleted: {
        printBlock.registerSlot(valueAnchor.update)
    }

    Anchor {
        id: valueAnchor
        objectName: "valueAnchor"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5

        anchors.left: parent.left
        anchors.leftMargin: 3

        border.width: parent.border.width

        width: parent.height * 0.33
        height: parent.height * 0.33
    }

    Text {
        id: printLabel
        text: "value"

        color: "#62717E"
        font.pixelSize: 12
        font.bold: true
        verticalAlignment: Text.AlignVCenter

        anchors.verticalCenter: valueAnchor.verticalCenter
        anchors.left: valueAnchor.right
        anchors.leftMargin: 5

        width: parent.width * 0.64
        height: parent.height * 0.5
    }
}
