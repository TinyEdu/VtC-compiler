import QtQuick 6.0
import QtQuick.Controls 6.0

BlockDiagram {
    id: startDiagram
    name: "Start"
    width: 120
    height: 80
    color: "lightblue"

    Component.onCompleted: {
        startDiagram.registerSlot(anchor.update)
    }

    Anchor {
        id: anchor
        width: 15
        height: 15
        color: "white"
        radius: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
    }
}
