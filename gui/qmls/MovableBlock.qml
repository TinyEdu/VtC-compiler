import QtQuick 2.15
import com.example.movableblock 1.0

Item {
    id: movableBlock
    property alias name: blockBackend.name
    property color blockColor: "blue" // Default color for the main block
    property color barColor: "darkblue" // Default color for the top bar

    width: 100
    height: 100

    MovableBlock {
        id: blockBackend
    }

    // Main block with top bar
    Rectangle {
        anchors.fill: parent
        color: blockColor
        radius: 10

        // Top bar
        Rectangle {
            id: topBar
            width: parent.width
            height: 20
            color: barColor
            anchors.top: parent.top
            radius: 10 // Rounded top corners
            border.width: 1
            border.color: "black"

            Text {
                anchors.centerIn: parent
                text: blockBackend.name
                color: "white"
                font.bold: true
                font.pointSize: 10
            }
        }

        // Smaller square 1
        Rectangle {
            id: smallSquare1
            width: 15
            height: 15
            color: "white"
            radius: 5
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }

        // Smaller square 2
        Rectangle {
            id: smallSquare2
            width: 15
            height: 15
            color: "white"
            radius: 5
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    MouseArea {
        anchors.fill: parent
        drag.target: movableBlock

        onPressed: console.log("Dragging started on", blockBackend.name)
        onReleased: console.log("Dragging finished at", movableBlock.x, movableBlock.y)
    }
}
