import QtQuick 6.0
import QtQuick.Effects 6.5
import QtQuick.Controls 6.0  // Use this instead of setting Material globally

Rectangle {
    id: blockDiagram
    property string name: "function"
    property color blockColor: "#CCE2CB"
    property color barColor: "#B6CfB6"

    signal anchorNeedsUpdate()
    property var registeredSlots: []

    width: 100
    height: 100
    radius: 10
    color: blockColor
    z: 1  // Ensure block is always above the shadow

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
        z: -1  // Ensure shadow stays behind the block
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

    function registerSlot(slotFunction) {
        registeredSlots.push(slotFunction);
    }

    function updateAnchors() {
        for (var i = 0; i < registeredSlots.length; i++) {
            registeredSlots[i]();
        }
    }

    Connections {
        target: blockDiagram
        function onWidthChanged() { shadowEffect.update(); }
        function onHeightChanged() { shadowEffect.update(); }
    }

    MouseArea {
        anchors.fill: parent
        drag.target: blockDiagram

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
