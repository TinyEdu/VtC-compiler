import QtQuick 6.0
import QtQuick.Effects 6.5
import QtQuick.Controls 6.0

Rectangle {
    id: blockDiagram
    property string name: "function"
    property color blockColor: "#CCE2CB"
    property color barColor: "#B6CfB6"

    signal anchorNeedsUpdate()
    property var registeredSlots: []

    width: 100
    height: 100
    z: 1
    radius: 2
    color: blockColor

    // Static shadow source to prevent scaling issues
    Rectangle {
        id: shadowSource
        width: blockDiagram.width
        height: blockDiagram.height
        radius: blockDiagram.radius
        visible: false
    }

    MultiEffect {
        id: shadowEffect
        source: shadowSource
        anchors.fill: blockDiagram
        shadowEnabled: true
        shadowColor: "#62717E"
        shadowBlur: 0.3
        shadowVerticalOffset: 6
        shadowHorizontalOffset: 4
        z: -1
    }

    Anchor {
        id: leftAnchor
        anchors.left: parent.left
    }

    Anchor {
        id: rightAnchor
        anchors.right: parent.right
    }

    Rectangle {
        id: topBar
        width: parent.width
        height: 20
        color: barColor
        anchors.top: parent.top
        radius: 2
        border.width: 1.5
        border.color: "#62717E"

        Text {
            text: name
            color: "#62717E"
            font.bold: true
            font.pointSize: 10
            anchors.centerIn: parent
        }
    }

    Component.onCompleted: {
        registerSlot(leftAnchor.update)
        registerSlot(rightAnchor.update)
    }

    function registerSlot(slotFunction) {
        registeredSlots.push(slotFunction);
    }

    function updateAnchors() {
        registeredSlots.forEach(function(slot) {
            slot();
        });
    }

    Connections {
        target: blockDiagram
        onWidthChanged: shadowEffect.update
        onHeightChanged: shadowEffect.update
    }

    // Lower the z value to allow child anchors to receive mouse events
    MouseArea {
        anchors.fill: parent
        drag.target: blockDiagram
        z: 0

        onPositionChanged: {
            if (blockDiagram.x < 0) blockDiagram.x = 0;
            if (blockDiagram.y < 0) blockDiagram.y = 0;
            if (blockDiagram.x + blockDiagram.width > draggableCanvas.width)
                blockDiagram.x = draggableCanvas.width - blockDiagram.width;
            if (blockDiagram.y + blockDiagram.height > draggableCanvas.height)
                blockDiagram.y = draggableCanvas.height - blockDiagram.height;

            updateAnchors();
        }
    }
}
