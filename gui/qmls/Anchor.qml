import QtQuick 6.0
import QtQuick.Controls 6.0
import CollisionManager 1.0

Rectangle {
    id: anchor
    width: 50
    height: 50
    color: "blue"

    property bool isLeft: true

    property var connections: []
    property var anchorLogic
    property BezierConnection connection


    Component.onCompleted: {
        anchorLogic = anchorFactory.newComponent();
        anchorLogic.Associate(this);
    }

    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: null

        property bool followMouse: false

        onPressed: {
            followMouse = true;

            if (connection == null) {
                const rootItem = anchor.Window ? anchor.Window.contentItem : anchor.parent;
                const anchorCenter = anchor.mapToItem(rootItem, anchor.width / 2, anchor.height / 2);

                let component = Qt.createComponent("BezierConnection.qml");
                if (component.status === Component.Ready) {
                    connection = component.createObject(rootItem, {
                        "startPointX": anchorCenter.x,
                        "startPointY": anchorCenter.y,
                        "endPointX": anchorCenter.x,
                        "endPointY": anchorCenter.y
                    });

                    connections.push(connection)
                }
            }
        }

        onReleased: function (mouse) {
            followMouse = false;

            // Convert local position to parent (root) coordinates
            const rootItem = anchor.Window ? anchor.Window.contentItem : anchor.parent;
            const globalMousePos = anchor.mapToItem(rootItem, mouse.x, mouse.y);

            const item = CollisionManager.isOverAnAnchor(globalMousePos.x, globalMousePos.y, anchor)

            if (item != null) {
                // update with nodes
                connection.updateWithAnchors(anchor, item)
            } else {
                connection.destroy();
                connection = null;
            }
        }

        onPositionChanged: function (mouse) {
            if (followMouse && connection) {
                // Convert local position to parent (root) coordinates
                const rootItem = anchor.Window ? anchor.Window.contentItem : anchor.parent;
                const globalMousePos = anchor.mapToItem(rootItem, mouse.x, mouse.y);

                connection.endPointX = globalMousePos.x;
                connection.endPointY = globalMousePos.y;

                connection.canvas.requestPaint();
            }
        }
    }
}
