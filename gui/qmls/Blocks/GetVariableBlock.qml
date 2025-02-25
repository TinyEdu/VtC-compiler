import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: getVariableBlock
    name: "Get Var"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: false
    enableRightAnchor: false

    Component.onCompleted: {
        getVariableBlock.registerSlot(rAnchor.update)
    }

    ComboBox {
        id: typeSelector
        width: 60
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 3

        model: ["Call1", "Call2", "Call3"]
        onCurrentIndexChanged: {
            console.log("Selected type: " + typeSelector.currentText)
        }
    }

    Anchor {
        id: rAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 3
    }
}
