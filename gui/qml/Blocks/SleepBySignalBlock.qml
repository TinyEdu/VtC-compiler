import QtQuick
import QtQuick.Controls
import "../"

BlockDiagram {
    id: sleepBySignalBlock
    name: "Sleep"
    width: 90
    height: 50
    color: "lightblue"

    enableLeftAnchor: true
    enableRightAnchor: true

    Text {
        text: "Time"
        color: "#62717E"
        font.bold: true
        font.pointSize: 10
        anchors.bottom: parent.bottom
        anchors.margins: 3
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Anchor {
        id: lAnchor
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.margins: 3

        anchorType: "data"
        anchorDirection: "left"
    }
}
