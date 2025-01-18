import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: bezierConnection
    width: 800
    height: 600
    z: 2

    property int startPointX: 100
    property int startPointY: 100
    property int endPointX: 300
    property int endPointY: 300

    property alias canvas: connection

    Canvas {
        id: connection
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, width, height);

            // Bézier Curve Points
            var curveStartX = startPointX;
            var curveStartY = startPointY;
            var curveEndX = endPointX;
            var curveEndY = endPointY;

            // Control points for the curve
            var control1X = curveStartX + (curveEndX - curveStartX) / 3;
            var control1Y = curveStartY;
            var control2X = curveEndX - (curveEndX - curveStartX) / 3;
            var control2Y = curveEndY;

            // Draw Bézier curve
            ctx.beginPath();
            ctx.moveTo(curveStartX, curveStartY);
            ctx.bezierCurveTo(control1X, control1Y, control2X, control2Y, curveEndX, curveEndY);
            ctx.strokeStyle = "red";
            ctx.lineWidth = 3;
            ctx.stroke();
        }
    }
}
