import QtQuick 6.0
import QtQuick.Controls 6.0

BlockDiagram {
    id: endDiagram
    name: "End"
    width: 120
    height: 80
    color: "lightblue"

    Component.onCompleted: {
        endDiagram.registerSlot(anchor.update)
    }

    Anchor {
        id: anchor
        width: 15
        height: 15
        color: "white"
        radius: 10
        anchors.left: parent.left
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
    }
}
