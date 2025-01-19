import QtQuick 6.0
import QtQuick.Effects 6.5

Rectangle {
    property string name: "function"
    property color blockColor: "#CCE2CB"
    property color barColor: "#B6CfB6"

    id: blockDiagram
    width: 100
    height: 100
    radius: 10
    color: blockColor


    MultiEffect {
        id: shadowEffect
        source: blockDiagram
        anchors.fill: blockDiagram
        shadowEnabled: true
        shadowColor: "#62717E"  // Soft shadow effect
        shadowBlur: 0.3
        shadowVerticalOffset: 6
        shadowHorizontalOffset: 4
    }


    Rectangle {
        id: topBar
        width: parent.width
        height: 25
        color: barColor
        anchors.top: parent.top
        radius: 10
        border.width: 1.5
        border.color: "#62717E"

        Text {
            anchors.centerIn: parent
            text: name
            color: "#62717E"
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
        z: 4
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
    }

    // Smaller square 2
    Anchor {
        id: anchor2
        width: 15
        height: 15
        z: 4
        color: "white"
        radius: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
    }


    MouseArea {
        anchors.fill: parent
        drag.target: blockDiagram

        onPositionChanged : {
            anchor1.update()
            anchor2.update()
        }
    }
}