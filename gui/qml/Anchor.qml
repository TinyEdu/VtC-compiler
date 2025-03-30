// Anchor.qml
import QtQuick 6.0
import QtQuick.Controls 6.0
import CollisionManager 1.0

Rectangle {
    id: anchor

    implicitWidth: 20
    implicitHeight: 20
    width: implicitWidth
    height: implicitHeight

    z: 100
    radius: 4
    border.width: 1.5
    border.color: "#84818E"
    color: "white"

    property bool isLeft: true
    property var connections: []
    property var anchorLogic
    property BezierConnection connection

    property var anchorId

    Rectangle {
        id: anchorCircle
        anchors.centerIn: parent
        width: Math.min(parent.width, parent.height) * 0.3
        height: width
        radius: width / 2
        color: "#62717E"
    }

    Component.onCompleted: {
        anchorLogic = anchorFactory.newComponent();
        anchorLogic.Associate(this);
    }

    function update() {
        if (connection !== null) {
            connection.update();
        }
    }

    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: null
        z: 101
        preventStealing: true
        hoverEnabled: true

        property bool followMouse: false

        onPressed: function(mouse) {
            followMouse = true;

            if (connection == null) {
                const rootItem = draggableCanvas;
                const anchorCenter = anchor.mapToItem(rootItem, anchor.width / 2, anchor.height / 2);

                let component = Qt.createComponent("BezierConnection.qml");
                if (component.status === Component.Ready) {
                    connection = component.createObject(rootItem, {
                        startPointX: anchorCenter.x,
                        startPointY: anchorCenter.y,
                        endPointX: anchorCenter.x,
                        endPointY: anchorCenter.y
                    });
                    connections.push(connection);
                }
            }
        }

        onReleased: function(mouse) {
            followMouse = false;

            const rootItem = (anchor.Window ? anchor.Window.contentItem : anchor.parent);
            const globalMousePos = anchor.mapToItem(rootItem, mouse.x, mouse.y);

            const item = CollisionManager.isOverAnAnchor(globalMousePos.x, globalMousePos.y, anchor);

            if (item !== null && item.visible && item.enabled) {
                if (item.connection) {
                    item.connection.destroy();
                    item.connection = null;
                }
                connection.updateWithAnchors(anchor, item);
                item.connection = connection;
            } else {
                connection.destroy();
                connection = null;
            }
        }

        onPositionChanged: function(mouse) {
            if (followMouse && connection) {
                const rootItem = draggableCanvas;
                let globalMousePos = dragArea.mapToItem(rootItem, mouse.x, mouse.y);

                globalMousePos.x = Math.max(0, Math.min(globalMousePos.x, draggableCanvas.width - anchor.width));
                globalMousePos.y = Math.max(0, Math.min(globalMousePos.y, draggableCanvas.height - anchor.height));

                connection.endPointX = globalMousePos.x + anchor.width / 2;
                connection.endPointY = globalMousePos.y + anchor.height / 2;
                connection.canvas.requestPaint();
            }
        }
    }
}
