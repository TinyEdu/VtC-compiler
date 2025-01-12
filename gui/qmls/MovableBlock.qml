import QtQuick 2.15

Rectangle {
    id: block
    width: 70
    height: 100
    color: "#3498db"
    border.color: "black"
    radius: 5

    // Label at the top
    Rectangle {
        id: label
        height: 20
        width: parent.width
        color: "#2c3e50"
        anchors.top: parent.top
        Text {
            anchors.centerIn: parent
            text: blockName
            color: "white"
            font.pixelSize: 12
        }
    }

    // Customizable property for boundaries
    property Item boundaryParent: null

    property string blockName: "Block Name"

        // Mouse handling for dragging
    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: parent
        cursorShape: Qt.OpenHandCursor

        property real maxX: boundaryParent ? boundaryParent.width - block.width : 0
        property real maxY: boundaryParent ? boundaryParent.height - block.height : 0

        onPositionChanged: {
            if (boundaryParent) {
                block.x = Math.max(0, Math.min(block.x, maxX));
                block.y = Math.max(0, Math.min(block.y, maxY));
            }
        }
    }
}
