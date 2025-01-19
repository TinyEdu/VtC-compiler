import QtQuick 6.0
import QtQuick.Controls 6.0

Item {
    id: bezierConnection
    width: 800
    height: 600
    z: 2

    property int startPointX
    property int startPointY
    property int endPointX
    property int endPointY

    property var leftAnchor
    property var rightAnchor

    function update() {
        startPointX = leftAnchor.x + leftAnchor.width / 2
        startPointY = leftAnchor.y + leftAnchor.height / 2
        endPointX = rightAnchor.x + rightAnchor.width / 2
        endPointY = rightAnchor.y + rightAnchor.height / 2

        canvas.requestPaint()
    }

    function updateWithAnchors(_leftAnchor, _rightAnchor) {
        leftAnchor = _leftAnchor
        rightAnchor = _rightAnchor

        update()
    }

    property alias canvas: connectionCanvas

    Canvas {
        id: connectionCanvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, width, height);

            // Draw Bézier curve
            ctx.beginPath();
            ctx.moveTo(startPointX, startPointY);

            // Control points for a smooth curve
            var control1X = startPointX + (endPointX - startPointX) / 3;
            var control1Y = startPointY;
            var control2X = endPointX - (endPointX - startPointX) / 3;
            var control2Y = endPointY;

            ctx.bezierCurveTo(control1X, control1Y, control2X, control2Y, endPointX, endPointY);
            ctx.strokeStyle = "red";
            ctx.lineWidth = 3;
            ctx.stroke();
        }
    }
}
