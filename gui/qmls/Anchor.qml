import QtQuick 6.0
import QtQuick.Controls 6.0

Rectangle {
    id: anchor
    width: 50
    height: 50
    color: "blue"

    property var bezierConnections: []
    property var bezierConnection

    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: null

        property bool followMouse: false

        onPressed: {
            followMouse = true;

            if (bezierConnection == null) {
                console.log("Creating new Bézier connection...");

                const rootItem = anchor.Window ? anchor.Window.contentItem : anchor.parent;
                const anchorCenter = anchor.mapToItem(rootItem, anchor.width / 2, anchor.height / 2);

                let component = Qt.createComponent("BezierConnection.qml");
                if (component.status === Component.Ready) {
                    bezierConnection = component.createObject(rootItem, {
                        "startPointX": anchorCenter.x,
                        "startPointY": anchorCenter.y,
                        "endPointX": anchorCenter.x + 100,
                        "endPointY": anchorCenter.y + 100
                    });
                }
            }
        }

        onReleased: {
            followMouse = false;
        }

        onPositionChanged: function (mouse) {
            if (followMouse && bezierConnection) {
                console.log("Moving anchor");

                // Convert local position to parent (root) coordinates
                const rootItem = anchor.Window ? anchor.Window.contentItem : anchor.parent;
                const globalMousePos = anchor.mapToItem(rootItem, mouse.x, mouse.y);

                bezierConnection.endPointX = globalMousePos.x;
                bezierConnection.endPointY = globalMousePos.y;

                bezierConnection.canvas.requestPaint();
            }
        }
    }
}
