// BlockDiagram.qml
import QtQuick
import QtQuick.Effects
import QtQuick.Controls

import BlockDiagramManager

Rectangle {
    id: blockDiagram

    property string typeName: "blockDiagram"

    // Config
    property string name: "function"
    property color blockColor: "#CCE2CB"
    property color barColor: "#B6CfB6"
    property bool enableLeftAnchor: true
    property bool enableRightAnchor: true
    signal anchorNeedsUpdate()
    property var registeredSlots: []

    property var blockDiagramLogic

    // Sizing
    implicitWidth: 100
    implicitHeight: 100
    width: implicitWidth
    height: implicitHeight
    radius: 4
    z: 114
    color: blockColor
    border.color: "#84818E"

    Anchor {
        id: leftAnchor
        anchors.left: parent.left
        enabled: enableLeftAnchor
        visible: enableLeftAnchor

        height: parent.height * 0.33
        width: parent.height * 0.33
        anchors.top: parent.top
        radius: parent.radius
        border.width: parent.border.width
        border.color: parent.border.color
    }

    Anchor {
        id: rightAnchor
        anchors.right: parent.right
        enabled: enableRightAnchor
        visible: enableRightAnchor

        height: parent.height * 0.33
        width: parent.height * 0.33
        anchors.top: parent.top
        radius: parent.radius
        border.width: parent.border.width
        border.color: parent.border.color
    }

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

    Rectangle {
        id: topBar
        width: parent.width
        height: parent.height * 0.33
        color: barColor
        anchors.top: parent.top
        radius: parent.radius
        border.width: parent.border.width
        border.color: parent.border.color

        Text {
            text: name
            color: "#62717E"
            font.bold: true
            anchors.centerIn: parent
            font.pixelSize: Math.max(10, topBar.height * 0.6)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.NoWrap
        }
    }

    Component.onCompleted: {
        if (enableLeftAnchor) registerSlot(leftAnchor.update)
        if (enableRightAnchor) registerSlot(rightAnchor.update)

        blockDiagramLogic = blockDiagramFactory.newComponent();
        blockDiagramLogic.Associate(this);
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
        function onWidthChanged() { shadowEffect.update(); }
        function onHeightChanged() { shadowEffect.update(); }
    }

    MouseArea {
        anchors.fill: parent
        drag.target: blockDiagram
        z: 0

        onPositionChanged: {
            if (typeof draggableCanvas !== "undefined") {
                const scale = draggableCanvas.currentScale;
                const maxX = draggableCanvas.canvasWidth - blockDiagram.width / scale;
                const maxY = draggableCanvas.canvasHeight - blockDiagram.height / scale;

                if (blockDiagram.x < 0) blockDiagram.x = 0;
                if (blockDiagram.y < 0) blockDiagram.y = 0;
                if (blockDiagram.x > maxX) blockDiagram.x = maxX;
                if (blockDiagram.y > maxY) blockDiagram.y = maxY;
            }

            updateAnchors();
        }
    }
}
