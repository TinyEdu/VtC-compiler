// Anchor.qml
import QtQuick
import QtQuick.Controls

import Theme

Item {
    id: root

    property var anchorId
    property var draggableCanvas
    property var anchorLogic

    property int connectionIndex: -1
    property string anchorDirection: "left"
    property string anchorType: "anchor"
    property bool isPreview: false

    width: 16
    height: 16

    Rectangle {
        id: outerCircle
        height: 100
        width: 100
        radius: 100
        scale:0.1

        anchors.centerIn: parent
        color: Theme.lightAccentColor
        layer.smooth: true

        border.width: 8
        border.color: Theme.darkAccentColor

        Rectangle {
            id: innerCircle
            width: 37.5
            height: 37.5
            radius: 37.5

            anchors.centerIn: parent
            color: Theme.darkMode ? Theme.darkAccentColor : Theme.lightAccentColor
            layer.smooth: true
        }
    }

    function resetConnection() {
        connectionIndex = -1;
    }

    Component.onCompleted: {
        anchorLogic = anchorFactory.newComponent();
        anchorLogic.Associate(this, anchorType);
    }

    Component.onDestruction: {
        if (connectionIndex !== -1) {
            bezierFactory.deleteConnection(connectionIndex);
        }
    }

    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: null
        preventStealing: true
        hoverEnabled: true
        enabled: !isPreview

        property bool followMouse: false

        onPressed: function (mouse) {
            connectionIndex = bezierFactory.startConnection(root, draggableCanvas);
        }

        onReleased: function (mouse) {
            connectionIndex = bezierFactory.releaseConnection(root, mouse);
        }

        onPositionChanged: function (mouse) {
            bezierFactory.updateConnectionPosition(connectionIndex, mouse, root);
        }
    }
}
