import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: endBlock
    name: "End"
    width: 90
    height: 50
    color: "lightblue"

    Component.onCompleted: {
        endBlock.registerSlot(anchor.update)
    }

    Anchor {
        id: anchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.right: parent.right
    }
}
