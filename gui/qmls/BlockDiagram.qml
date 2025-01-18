import QtQuick 6.0

Item {
    id: movableBlock
    property string name: "function"
    property color blockColor: "blue"
    property color barColor: "darkblue"

    width: 100
    height: 100

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
                text: name
                color: "white"
                font.bold: true
                font.pointSize: 10
            }
        }

        // Smaller square 1
        Anchor {
            id: anchor1
            width: 15
            height: 15
            color: "white"
            radius: 5
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }

        // Smaller square 2
        Anchor {
            id: anchor2
            width: 15
            height: 15
            color: "white"
            radius: 5
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.verticalCenter: parent.verticalCenter
        }


    }

    // MouseArea {
    //     anchors.fill: parent
    //     drag.target: movableBlock
    // }
}