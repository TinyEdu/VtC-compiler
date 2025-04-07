// BlockDiagram.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: blockDiagram
    objectName: "blockDiagram"

    property string name: "function"
    property color blockColor: "#CCE2CB"
    property color barColor: "#B6CfB6"
    property color borderColor: "#84818E"
    property bool enableLeftAnchor: true
    property bool enableRightAnchor: true
    property bool shouldBeRegistered: true
    property var blockDiagramLogic
    property var model

    height: 100
    width: 100
    visible: true
    Drag.active: mouseArea.drag.active

    radius: 4
    color: blockColor
    border.color: borderColor

    Anchor {
        id: leftAnchor
        objectName: "leftAnchor"

        anchors.left: parent.left
        anchors.top: parent.top
        z: 2

        anchorType: "anchor"
        anchorDirection: "left"

        enabled: enableLeftAnchor
        visible: enableLeftAnchor
    }

    Anchor {
        id: rightAnchor
        objectName: "rightAnchor"

        anchors.right: parent.right
        anchors.top: parent.top
        z: 2

        anchorType: "anchor"
        anchorDirection: "right"

        enabled: enableRightAnchor
        visible: enableRightAnchor
    }

    Rectangle {
        id: topBar
        width: parent.width
        height: 16
        z: 1
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

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        drag.target: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onPositionChanged: bezierFactory.updateAllConnections();

        onReleased: function (mouse) {
            removeIfNeeded(mouse);
        }
    }

    function isIntersecting(mouse) {
        var localPos = blockCreator.mapToItem(draggableCanvas, Qt.point(mouse.x, mouse.y));
        return draggableCanvas.contains(localPos);
    }

    function isIntersecting2(mouse) {
        var localPos = blockCreator.mapToItem(draggableCanvas, Qt.point(mouse.x, mouse.y));

        var inverseScale = 1.0 / draggableCanvas.scale.x;
        var offsetX = draggableCanvas.x;
        var offsetY = draggableCanvas.y;

        localPos.x = (localPos.x - offsetX) * inverseScale;
        localPos.y = (localPos.y - offsetY) * inverseScale;

        return draggableCanvas.contains(localPos);
    }

    function shouldBeRemoved(mouse) {
        return mouse.button === Qt.RightButton;
    }

    function removeIfNeeded(mouse) {
        if (shouldBeRemoved(mouse) && !isIntersecting2(mouse)) {
            if (enableLeftAnchor) {
                bezierFactory.deleteConnection(leftAnchor.connectionIndex);
            }
            else if (enableRightAnchor) {
                bezierFactory.deleteConnection(rightAnchor.connectionIndex);
            }

            model.remove(index);
        }
    }
}
