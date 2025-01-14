import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: bezierConnection
    width: 800
    height: 600
    z:2

    property alias startX: block1.x
    property alias startY: block1.y
    property alias endX: block2.x
    property alias endY: block2.y

    // Blocks to connect
    MovableBlock {
        id: block1
        width: 20; height: 20
        color: "blue"
        x: 50; y: 100
    }

    MovableBlock {
        id: block2
        width: 20; height: 20
        color: "green"
        x: 50; y: 200
    }

    // Canvas to draw the curve
    Canvas {
        id: connection
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, width, height);

            // Positions of the blocks
            var curveStartX = block1.x + block1.width / 2;
            var curveStartY = block1.y + block1.height / 2;
            var curveEndX = block2.x + block2.width / 2;
            var curveEndY = block2.y + block2.height / 2;

            // Control points for asymmetrical "S" curve
            var control1X = curveStartX + (curveEndX - curveStartX);
            var control1Y = curveStartY;
            var control2X = curveEndX - (curveEndX - curveStartX);
            var control2Y = curveEndY;

            // Draw Bézier curve
            ctx.beginPath();
            ctx.moveTo(curveStartX, curveStartY);
            ctx.bezierCurveTo(control1X, control1Y, control2X, control2Y, curveEndX, curveEndY);
            ctx.strokeStyle = "red"; // Curve color
            ctx.lineWidth = 3;
            ctx.stroke();
        }
    }

    Connections {
        target: block1
        function onXChanged() {
            connection.requestPaint();
        }
        function onYChanged() {
            connection.requestPaint();
        }
    }

    Connections {
        target: block2
        function onXChanged() {
            connection.requestPaint();
        }
        function onYChanged() {
            connection.requestPaint();
        }
    }
}
