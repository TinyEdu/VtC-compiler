import QtQuick 6.0
import QtQuick.Controls 6.0
import "../../"

BlockDiagram {
    id: binaryOperationBlock
    name: "OP"
    width: 90
    height: 82
    color: "lightblue"

    property string operationName: ".."

    Component.onCompleted: {
        binaryOperationBlock.registerSlot(rAnchor.update)
        binaryOperationBlock.registerSlot(l1Anchor.update)
        binaryOperationBlock.registerSlot(l2Anchor.update)
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
        anchors.bottomMargin: 20
    }

    Anchor {
        id: rAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 3
        anchors.bottomMargin: 20
    }

    Anchor {
        id: l1Anchor
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 3
    }

    Anchor {
        id: l2Anchor
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottomMargin: 40
    }
}
