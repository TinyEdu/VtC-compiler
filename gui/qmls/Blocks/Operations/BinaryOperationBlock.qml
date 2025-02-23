import QtQuick 6.0
import QtQuick.Controls 6.0
import "../../"



BlockDiagram {
    id: binaryOperationBlock
    name: "Operation"
    width: 90
    height: 90
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
        font.pointSize: 18

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 18
    }

    Anchor {
        id: rAnchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 20
    }

    Anchor {
        id: l1Anchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.left: parent.left
    }

    Anchor {
        id: l2Anchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 40
    }
}
