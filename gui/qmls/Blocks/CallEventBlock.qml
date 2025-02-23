import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: callEventBlock
    name: "Call"
    width: 90
    height: 50
    color: "lightblue"

    Component.onCompleted: {
        callEventBlock.registerSlot(anchor.update)
    }

    Anchor {
        id: anchor
        width: 20
        height: 20
        color: "white"
        radius: 2
        anchors.bottom: parent.bottom
        anchors.left: parent.left
    }

    ComboBox {
        id: typeSelector
        width: 60
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        model: ["Call1", "Call2", "Call3"]
        onCurrentIndexChanged: {
            console.log("Selected type: " + typeSelector.currentText)
        }
    }
}
