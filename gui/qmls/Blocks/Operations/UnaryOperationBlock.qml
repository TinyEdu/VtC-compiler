import QtQuick 6.0
import QtQuick.Controls 6.0
import "../../"

BlockDiagram {
    id: unaryOperationBlock
    name: "Operation"
    width: 90
    height: 50
    color: "lightblue"

    property string operationName: "."

    Component.onCompleted: {
        unaryOperationBlock.registerSlot(rAnchor.update)
        unaryOperationBlock.registerSlot(lAnchor.update)
    }

    Text {
        text: operationName
        color: "#62717E"
        font.bold: true
        font.pointSize: 16

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
    }

    Anchor {
        id: rAnchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.right: parent.right
    }

    Anchor {
        id: lAnchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.left: parent.left
    }

}
