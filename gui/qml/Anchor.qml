// Anchor.qml
import QtQuick
import QtQuick.Controls

Rectangle {
    id: anchor

    property var anchorId
    property var draggableCanvas
    property int connectionIndex: -1
    property string anchorDirection: "left"
    property string anchorType: "anchor"
    property bool isPreview: false

    width: 16
    height: 16
    color: "white"
    border.width: parent.border.width
    border.color: parent.border.color
    radius: parent.radius

    property var anchorLogic

    function resetConnection() {
        connectionIndex = -1;
    }

    Component.onCompleted: {
        anchorLogic = anchorFactory.newComponent();
        anchorLogic.Associate(this, anchorType);
    }

    Rectangle {
        id: circle
        anchors.centerIn: parent
        height: width
        width: Math.min(parent.width, parent.height) * 0.3
        radius: width / 2
        color: parent.border.color
    }

    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: null
        preventStealing: true
        hoverEnabled: true
        enabled: !anchor.isPreview

        property bool followMouse: false

        onPressed: function (mouse) {
            connectionIndex = bezierFactory.startConnection(anchor, draggableCanvas);
        }

        onReleased: function (mouse) {
            connectionIndex = bezierFactory.releaseConnection(anchor, mouse);
        }

        onPositionChanged: function (mouse) {
            bezierFactory.updateConnectionPosition(connectionIndex, mouse, anchor);
        }
    }
}
