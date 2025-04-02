import QtQuick
import QtQuick.Controls
import "../../"

BlockDiagram {
    id: binaryOperationBlock
    name: "Binary Op"
    width: 110
    height: 69
    color: "lightblue"

    Component.onCompleted: {
        binaryOperationBlock.registerSlot(rightInputValue)
        binaryOperationBlock.registerSlot(leftInputValue)
        binaryOperationBlock.registerSlot(outputValue)
    }

    Anchor {
        id: outputValue
        objectName: "outputValue"

        anchors.bottom: rightInputValue.top
        anchors.right: parent.right
        anchors.rightMargin: 3

        border.width: parent.border.width

        width: 16
        height: 16


        anchorType: "data"
        anchorDirection: "right"
    }

    Anchor {
        id: rightInputValue
        objectName: "rightInputValue"

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 3
        anchors.margins: 3

        border.width: parent.border.width

        width: 16
        height: 16

        anchorType: "data"
        anchorDirection: "left"
    }

    Anchor {
        id: leftInputValue
        objectName: "leftInputValue"

        anchors.bottom: outputValue.top
        anchors.left: parent.left
        anchors.leftMargin: 3

        border.width: parent.border.width

        width: 16
        height: 16

        anchorType: "data"
        anchorDirection: "left"
    }

    EditableComboBox {
        id: operation
        objectName: "operation"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: outputValue.verticalCenter

        implicitWidth: parent.width - rightInputValue.width - outputValue.width - 16
        implicitHeight: rightInputValue.height

        borderColor: parent.border.color

        model: ["add", "subtract", "divide", "multiply"]
    }
}
