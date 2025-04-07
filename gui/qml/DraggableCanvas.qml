// DraggableCanvas.qml
import QtQuick
import QtQuick.Controls

Rectangle {
    id: draggableCanvas
    property string typeName: "draggableCanvas"
    property real canvasWidth: 2000
    property real canvasHeight: 2000
    property real maxScale: 4.0
    property real currentScale: 1.0
    readonly property real minScale: Math.max(width / canvasWidth, height / canvasHeight)
    property alias contentItem: canvasGroup

    property real offsetX: 0
    property real offsetY: 0

    property var dragTarget: dragTarget

    anchors.fill: parent
    visible: true

    Flickable {
        id: flickable
        anchors.fill: parent
        interactive: false
        clip: true
        visible: true

        contentWidth: canvasWidth * maxScale
        contentHeight: canvasHeight * maxScale

        Item {
            id: canvasContainer
            width: flickable.contentWidth
            height: flickable.contentHeight
            visible: true

            Item {
                id: canvasGroup
                width: canvasWidth
                height: canvasHeight

                transform: [Translate {
                    x: offsetX; y: offsetY
                }, Scale {
                    xScale: currentScale; yScale: currentScale; origin.x: 0; origin.y: 0
                }]


                Rectangle {
                    anchors.fill: parent
                    color: "#eeeeee"
                    border.color: "black"
                    visible: true

                    DropArea {
                        id: dragTarget
                        objectName: "dragTarget"
                        anchors.fill: parent
                        visible: true
                    }

                    Canvas {
                        anchors.fill: parent
                        onPaint: {
                            const ctx = getContext("2d");
                            ctx.clearRect(0, 0, width, height);
                            ctx.strokeStyle = "#cccccc";
                            ctx.lineWidth = 1;
                            for (let x = 0; x <= width; x += 100) {
                                ctx.beginPath();
                                ctx.moveTo(x, 0);
                                ctx.lineTo(x, height);
                                ctx.stroke();
                            }
                            for (let y = 0; y <= height; y += 100) {
                                ctx.beginPath();
                                ctx.moveTo(0, y);
                                ctx.lineTo(width, y);
                                ctx.stroke();
                            }
                        }
                    }
                }
            }
        }

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AlwaysOff
        }
        ScrollBar.horizontal: ScrollBar {
            policy: ScrollBar.AlwaysOff
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.MiddleButton
            hoverEnabled: true
            preventStealing: true

            property real lastX: 0
            property real lastY: 0
            property bool dragging: false

            onPressed: function (mouse) {
                if (mouse.button === Qt.MiddleButton) {
                    dragging = true;
                    lastX = mouse.x;
                    lastY = mouse.y;
                }
            }

            onReleased: function (mouse) {
                dragging = false;
            }

            onPositionChanged: function (mouse) {
                if (dragging) {
                    const dx = (mouse.x - lastX);
                    const dy = (mouse.y - lastY);
                    offsetX += dx / currentScale;
                    offsetY += dy / currentScale;
                    lastX = mouse.x;
                    lastY = mouse.y;

                    bezierFactory.updateAllConnections();
                }
            }

            onWheel: function (wheel) {
                wheel.accepted = true;

                if (wheel.modifiers & Qt.ControlModifier) {
                    const factor = wheel.angleDelta.y > 0 ? 1.1 : 1 / 1.1;
                    const newScale = Math.max(minScale, Math.min(maxScale, currentScale * factor));

                    if (Math.abs(newScale - currentScale) > 0.0001) {
                        const mouseX = wheel.x;
                        const mouseY = wheel.y;

                        const sx = (mouseX - offsetX * currentScale) / currentScale;
                        const sy = (mouseY - offsetY * currentScale) / currentScale;

                        offsetX -= sx * (newScale - currentScale);
                        offsetY -= sy * (newScale - currentScale);
                        currentScale = newScale;
                    }
                } else {
                    offsetX -= wheel.angleDelta.x / currentScale;
                    offsetY -= wheel.angleDelta.y / currentScale;
                }

                bezierFactory.updateAllConnections();
            }
        }
    }
}
