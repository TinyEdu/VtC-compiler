import QtQuick 6.0
import QtQuick.Controls 6.0
import "../../"

BlockDiagram {
    id: unaryOperationBlock
    name: "OP"
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
        font.pointSize: 12

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 3
    }

    Anchor {
        id: rAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 3
    }

    Anchor {
        id: lAnchor
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 3
    }

}
