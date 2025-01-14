import QtQuick 6.0
import QtQuick.Controls 6.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600

    // Block (Node) Component
    Rectangle {
        id: block1
        width: 20; height: 20
        color: "blue"
        x: 200; y: 200
        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }
    }

    Rectangle {
        id: block2
        width: 20; height: 20
        color: "green"
        x: 500; y: 300
        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }
    }

    // Line connecting the blocks
    Canvas {
        id: connection
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, width, height);

            // Positions of the blocks
            var startX = block1.x + block1.width / 2;
            var startY = block1.y + block1.height / 2;
            var endX = block2.x + block2.width / 2;
            var endY = block2.y + block2.height / 2;

            // Control points for asymmetrical "S" curve
            var control1X = startX + (endX - startX) ; // Control closer to start block
            var control1Y = startY;                // Move upward for the initial curve
            var control2X = endX - (endX - startX) ;  // Control closer to end block
            var control2Y = endY;                 // Move downward for the ending curve

            // Draw Bézier curve
            ctx.beginPath();
            ctx.moveTo(startX, startY);
            ctx.bezierCurveTo(control1X, control1Y, control2X, control2Y, endX, endY);
            ctx.strokeStyle = "red"; // Use red for now
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
