import QtQuick 6.0
import QtQuick.Controls 6.0
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
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 4
    }
}
