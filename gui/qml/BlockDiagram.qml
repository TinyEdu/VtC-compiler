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

    height: 60
    width: 60
    visible: true
    Drag.active: mouseArea.drag.active

    radius: 4
    color: blockColor
    border.color: borderColor

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        drag.target: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

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

        // Account for scale and offset applied to the draggableCanvas
        var inverseScale = 1.0 / draggableCanvas.scale.x; // Assuming uniform scale
        var offsetX = draggableCanvas.x;
        var offsetY = draggableCanvas.y;

        // Adjust the local position by the inverse of scale and offset
        localPos.x = (localPos.x - offsetX) * inverseScale;
        localPos.y = (localPos.y - offsetY) * inverseScale;

        return draggableCanvas.contains(localPos);
    }

    function shouldBeRemoved(mouse) {
        return mouse.button === Qt.RightButton || Drag.target === null
            || Drag.target.objectName === null || Drag.target.objectName !== "dragTarget";
    }

    function removeIfNeeded(mouse) {
        if (shouldBeRemoved(mouse) && !isIntersecting2(mouse)) {
            model.remove(index)
        }
    }
}
