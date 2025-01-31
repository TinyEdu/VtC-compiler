import QtQuick 6.0
import QtQuick.Controls 6.0

Item {
    id: bezierConnection
    width: draggableCanvas.width
    height: draggableCanvas.height
    z: 2

    property int startPointX
    property int startPointY
    property int endPointX
    property int endPointY

    property var leftAnchor
    property var rightAnchor

    function update() {
        const rootItem = draggableCanvas;

        // Convert local coordinates to draggableCanvas coordinates
        let leftGlobal = leftAnchor.mapToItem(rootItem, leftAnchor.width / 2, leftAnchor.height / 2);
        let rightGlobal = rightAnchor.mapToItem(rootItem, rightAnchor.width / 2, rightAnchor.height / 2);

        startPointX = leftGlobal.x;
        startPointY = leftGlobal.y;
        endPointX = rightGlobal.x;
        endPointY = rightGlobal.y;

        canvas.requestPaint();
    }

    function updateWithAnchors(_leftAnchor, _rightAnchor) {
        leftAnchor = _leftAnchor;
        rightAnchor = _rightAnchor;

        update();
    }

    property alias canvas: connectionCanvas

    Canvas {
        id: connectionCanvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, width, height);

            // Draw Bezier curve
            ctx.beginPath();
            ctx.moveTo(startPointX, startPointY);

            // Control points for a smooth curve
            var control1X = startPointX + (endPointX - startPointX) / 3;
            var control1Y = startPointY;
            var control2X = endPointX - (endPointX - startPointX) / 3;
            var control2Y = endPointY;

            ctx.bezierCurveTo(control1X, control1Y, control2X, control2Y, endPointX, endPointY);
            ctx.strokeStyle = "#62717E";
            ctx.lineWidth = 3;
            ctx.stroke();
        }
    }
}