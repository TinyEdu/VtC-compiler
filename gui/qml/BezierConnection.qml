import QtQuick 6.0
import QtQuick.Controls 6.0

Item {
    id: bezierConnection
    width: draggableCanvas.width
    height: draggableCanvas.height
    z: 115
    visible: true
    clip: false

    property string typeName: "BezierConnection"

    // Connection coordinates
    property int startPointX
    property int startPointY
    property int endPointX
    property int endPointY

    // Anchors
    property var leftAnchor
    property var rightAnchor

    // Public method to update coordinates
    function update() {
        const rootItem = draggableCanvas;

        let leftGlobal = leftAnchor.mapToItem(rootItem, leftAnchor.width / 2, leftAnchor.height / 2);
        let rightGlobal = rightAnchor.mapToItem(rootItem, rightAnchor.width / 2, rightAnchor.height / 2);

        startPointX = leftGlobal.x;
        startPointY = leftGlobal.y;
        endPointX = rightGlobal.x;
        endPointY = rightGlobal.y;

        canvas.requestPaint();
    }

    // Assign anchors and trigger update
    function updateWithAnchors(_leftAnchor, _rightAnchor) {
        leftAnchor = _leftAnchor;
        rightAnchor = _rightAnchor;
        update();
    }

    function getOtherAnchor(anchor) {
        if (anchor === leftAnchor) {
            return rightAnchor;
        } else if (anchor === rightAnchor) {
            return leftAnchor;
        }
        return null;
    }

    // External access to canvas if needed
    property alias canvas: connectionCanvas

    // Drawing surface
    Canvas {
        id: connectionCanvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, width, height);

            // Draw Bezier curve
            ctx.beginPath();
            ctx.moveTo(startPointX, startPointY);

            // Smooth control points
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
