import QtQuick 6.0
import QtQuick.Controls 6.0

Rectangle {
    id: anchor
    width: 50
    height: 50
    x: 50
    y: 50
    z: parent.z + 1
    color: "blue"

    property var anchorLogic

    Component.onCompleted: {
        if (!anchorFactory) {
            console.error("anchorFactory is undefined!");
            return;
        }

        if (!anchorLogic) {
            anchorLogic = anchorFactory.newComponent();
            if (!anchorLogic) {
                console.error("Failed to initialize anchorLogic!");
                return;
            }
        }

        anchorLogic.Associate(this);
    }

    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: null

        property bool followMouse: false

        onPressed: {
            console.log("onPressed");
            followMouse = true;
        }

        onReleased: {
            console.log("onReleased");
            followMouse = false;
        }

        onPositionChanged: function(mouse) {
            if (followMouse) {
                // Map the mouse position to the BezierConnection's coordinate system
                const localPos = bezierCurve.mapFromItem(null, mouse.x, mouse.y);

                // Update the start point of the Bezier curve
                bezierCurve.endPointX = localPos.x;
                bezierCurve.endPointY = localPos.y;

                // Request the canvas to repaint
                bezierCurve.canvas.requestPaint();
            }
        }

    }

    BezierConnection {
        id: bezierCurve
        anchors.fill: parent

        // Initialize the start and end points
        startPointX: x
        startPointY: y
        endPointX: x + 1
        endPointY: y + 1
    }
}
