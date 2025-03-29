import QtQuick
import QtQuick.Controls

Item {
    id: root
    anchors.fill: parent

    property string typeName: "draggableCanvas"
    property real canvasWidth: 2000
    property real canvasHeight: 2000
    property real maxScale: 4.0
    property real currentScale: 1.0
    readonly property real minScale: Math.max(width / canvasWidth, height / canvasHeight)
    property alias contentItem: canvasGroup

    // Manual offsets for transform
    property real offsetX: 0
    property real offsetY: 0

    Flickable {
        id: flickable
        anchors.fill: parent
        interactive: false
        clip: true

        // Fixed large surface
        contentWidth: canvasWidth * maxScale
        contentHeight: canvasHeight * maxScale

        onContentXChanged: updateAllAnchors()
        onContentYChanged: updateAllAnchors()

        Item {
            id: canvasContainer
            width: flickable.contentWidth
            height: flickable.contentHeight

            Item {
                id: canvasGroup
                width: canvasWidth
                height: canvasHeight

                transform: [
                    Translate { x: offsetX; y: offsetY },
                    Scale { xScale: currentScale; yScale: currentScale; origin.x: 0; origin.y: 0 }
                ]

                Rectangle {
                    anchors.fill: parent
                    color: "#eeeeee"
                    border.color: "black"

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

        ScrollBar.vertical: ScrollBar { policy: ScrollBar.AlwaysOn }
        ScrollBar.horizontal: ScrollBar { policy: ScrollBar.AlwaysOn }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.MiddleButton
            hoverEnabled: true
            preventStealing: true

            property real lastX: 0
            property real lastY: 0
            property bool dragging: false

            onPressed: function(mouse) {
                if (mouse.button === Qt.MiddleButton) {
                    dragging = true;
                    lastX = mouse.x;
                    lastY = mouse.y;
                }
            }

            onReleased: function(mouse) {
                dragging = false;
            }

            onPositionChanged: function(mouse) {
                if (dragging) {
                    const dx = (mouse.x - lastX);
                    const dy = (mouse.y - lastY);
                    offsetX += dx / currentScale;
                    offsetY += dy / currentScale;
                    lastX = mouse.x;
                    lastY = mouse.y;
                }

                updateAllAnchors()
            }

            onWheel: function(wheel) {
                wheel.accepted = true;

                if (wheel.modifiers & Qt.ControlModifier) {
                    const factor = wheel.angleDelta.y > 0 ? 1.1 : 1 / 1.1;
                    const newScale = Math.max(minScale, Math.min(maxScale, currentScale * factor));

                    if (Math.abs(newScale - currentScale) > 0.0001) {
                        const mouseX = wheel.x;
                        const mouseY = wheel.y;

                        // Zoom relative to mouse pointer
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

                updateAllAnchors()
            }
        }
    }

    function updateAllAnchors() {
        for (let i = 0; i < contentItem.children.length; ++i) {
            const child = contentItem.children[i];
            if (child && child.typeName === "blockDiagram" && typeof child.updateAnchors === "function") {
                child.updateAnchors();
            }
        }
    }
}
