// BezierConnection.qml
import QtQuick
import QtQuick.Controls

Item {
    id: bezierConnection

    property var leftAnchor
    property var rightAnchor
    property var model
    property var bezierConnectionLogic

    property int startX
    property int startY
    property int endX
    property int endY

    parent: draggableCanvas
    width: draggableCanvas.width
    height: draggableCanvas.height
    visible: true
    clip: false

    Component.onCompleted: {
        bezierConnectionLogic = bezierConnectionFactoryCPP.newComponent();
        bezierConnectionLogic.Associate(this);
    }

    Component.onDestruction: {
        bezierConnectionLogic.Disassociate(this);
        bezierConnectionLogic = null;
    }

    function redraw() {
        connectionCanvas.requestPaint();
    }

    function getLeftAnchor() {
        return leftAnchor;
    }

    function getRightAnchor() {
        return rightAnchor;
    }

    function update() {
        // check if the anchors are valid
        if (leftAnchor === null || rightAnchor === null) {
            return;
        }
        let leftGlobal = leftAnchor.mapToItem(draggableCanvas, leftAnchor.width / 2, leftAnchor.height / 2);
        let rightGlobal = rightAnchor.mapToItem(draggableCanvas, rightAnchor.width / 2, rightAnchor.height / 2);

        startX = leftGlobal.x;
        startY = leftGlobal.y;
        endX = rightGlobal.x;
        endY = rightGlobal.y;

        redraw();
    }

    function updateWithMousePosition(x, y) {
        let leftGlobal = leftAnchor.mapToItem(draggableCanvas, leftAnchor.width / 2, leftAnchor.height / 2);

        startX = leftGlobal.x;
        startY = leftGlobal.y;
        endX = x;
        endY = y;

        redraw();
    }

    function reset() {
        if (leftAnchor) leftAnchor.resetConnection();
        if (rightAnchor) rightAnchor.resetConnection();
    }

    Canvas {
        id: connectionCanvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, width, height);

            // Draw Bezier curve
            ctx.beginPath();
            ctx.moveTo(startX, startY);

            // Smooth control points
            var control1X = startX + (endX - startX) / 3;
            var control1Y = startY;
            var control2X = endX - (endX - startX) / 3;
            var control2Y = endY;

            ctx.bezierCurveTo(control1X, control1Y, control2X, control2Y, endX, endY);
            ctx.strokeStyle = "#62717E";
            ctx.lineWidth = 3;
            ctx.stroke();
        }
    }
}

