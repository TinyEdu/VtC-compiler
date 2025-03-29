// DraggableCanvas.qml
import QtQuick
import QtQuick.Controls

Item {
    id: root
    anchors.fill: parent

    // Configuration
    property string typeName: "draggableCanvas"
    property real canvasWidth: 2000
    property real canvasHeight: 2000
    property real maxScale: 4.0

    property real currentScale: 1.0
    readonly property real minScale: Math.max(width / canvasWidth, height / canvasHeight)

    Flickable {
        id: flickable
        anchors.fill: parent
        interactive: false
        clip: true

        contentWidth: Math.max(canvasWidth * currentScale, width)
        contentHeight: Math.max(canvasHeight * currentScale, height)

        Item {
            id: container
            width: flickable.contentWidth
            height: flickable.contentHeight
            anchors.centerIn: parent

            Rectangle {
                id: canvas
                width: root.canvasWidth
                height: root.canvasHeight
                color: "#eeeeee"
                border.color: "black"
                transformOrigin: Item.Center
                scale: root.currentScale
                anchors.centerIn: parent

                Canvas {
                    anchors.fill: parent
                    onPaint: {
                        var ctx = getContext("2d");
                        ctx.clearRect(0, 0, width, height);
                        ctx.strokeStyle = "#cccccc";
                        ctx.lineWidth = 1;
                        for (var x = 0; x <= width; x += 100) {
                            ctx.beginPath();
                            ctx.moveTo(x, 0);
                            ctx.lineTo(x, height);
                            ctx.stroke();
                        }
                        for (var y = 0; y <= height; y += 100) {
                            ctx.beginPath();
                            ctx.moveTo(0, y);
                            ctx.lineTo(width, y);
                            ctx.stroke();
                        }
                    }
                }
            }
        }

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }

        ScrollBar.horizontal: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            preventStealing: true
            acceptedButtons: Qt.MiddleButton

            property real pressX
            property real pressY
            property real startX
            property real startY

            function clampScroll() {
                flickable.contentX = Math.max(0, Math.min(flickable.contentX, flickable.contentWidth - flickable.width));
                flickable.contentY = Math.max(0, Math.min(flickable.contentY, flickable.contentHeight - flickable.height));
            }

            onPressed: function(mouse) {
                if (mouse.button === Qt.MiddleButton) {
                    pressX = mouse.x;
                    pressY = mouse.y;
                    startX = flickable.contentX;
                    startY = flickable.contentY;
                }
            }

            onPositionChanged: function(mouse) {
                if (mouse.buttons & Qt.MiddleButton) {
                    flickable.contentX = startX - (mouse.x - pressX);
                    flickable.contentY = startY - (mouse.y - pressY);
                    clampScroll();
                }
            }

            onWheel: function(wheel) {
                if (wheel.modifiers & Qt.ControlModifier) {
                    wheel.accepted = true;

                    let factor = (wheel.angleDelta.y > 0) ? 1.1 : 1 / 1.1;
                    let newScale = root.currentScale * factor;
                    newScale = Math.max(root.minScale, Math.min(root.maxScale, newScale));

                    if (Math.abs(newScale - root.currentScale) > 0.0001) {
                        root.currentScale = newScale;
                        clampScroll();
                    }
                } else {
                    wheel.accepted = true;
                    flickable.contentY -= wheel.angleDelta.y;
                    flickable.contentX -= wheel.angleDelta.x;
                    clampScroll();
                }
            }
        }
    }
}
