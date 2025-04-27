import QtQuick
import QtQuick.Controls
import "../../"

BlockDiagram {
    id: unaryOperationBlock
    name: "Unary Op"
    width: 110
    height: 50
    color: "lightblue"

    enableLeftAnchor: false
    enableRightAnchor: false

    Anchor {
        id: outputValue
        objectName: "outputValue"

        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 3
        anchors.margins: 3

        anchorType: "data"
        anchorDirection: "right"
    }

    Anchor {
        id: inputValue
        objectName: "inputValue"

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 3
        anchors.margins: 3

        anchorType: "data"
        anchorDirection: "left"
    }

    EditableComboBox {
        id: operation
        objectName: "operation"
        
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: outputValue.verticalCenter

        implicitWidth: parent.width - inputValue.width - outputValue.width - 12
        implicitHeight: inputValue.height

        borderColor: parent.border.color

        model: ["negate", "not"]
    }
}
