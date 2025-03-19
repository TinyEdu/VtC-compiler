import QtQuick 6.0
import QtQuick.Controls 6.0
import "../"

BlockDiagram {
    id: callEventBlock
    name: "Call"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: false

    ComboBox {
        id: typeSelector
        width: 60
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 3

        model: ["Call1", "Call2", "Call3"]
        onCurrentIndexChanged: {
            console.log("Selected type: " + typeSelector.currentText)
        }
    }
}
