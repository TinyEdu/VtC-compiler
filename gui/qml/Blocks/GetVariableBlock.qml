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
        getVariableBlock.registerSlot(passingAnchor.update)
    }

    TextField {
        id: variableField
        width: 60
        placeholderText: "Var name"

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 3
    }

    Anchor {
        id: passingAnchor
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 3
    }
}
