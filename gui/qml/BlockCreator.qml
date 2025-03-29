import QtQuick 6.0
import QtQuick.Controls 6.0

Rectangle {
    id: blockCreator
    width: 100
    height: 120
    color: "#E0E0E0"
    border.color: "#B0B0B0"
    radius: 4

    property string blockName: ""
    property url blockDiagramUrl: "BlockDiagram.qml"
    property var currentBlock: null
    property Item draggableCanvas
    property Component blockDiagramComponent: null
    property var previewBlock: null

    Item {
        id: blockHolder
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: label.top
            margins: 5
        }
    }

    Label {
        id: label
        text: blockName
        height: 20
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
        color: "#404040"
    }

    Component.onCompleted: {
        if (blockDiagramUrl !== "") {
            blockDiagramComponent = Qt.createComponent(blockDiagramUrl);
        }

        if (blockDiagramComponent) {
            previewBlock = blockDiagramComponent.createObject(blockHolder, {
                "scale": 0.7,
                "anchors.centerIn": blockHolder
            });
            if (previewBlock) {
                previewBlock.name = blockName;
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        preventStealing: true
        hoverEnabled: true

        property point pressOffset: Qt.point(0, 0)

        onPressed: (mouse) => {
            // Convert to global coordinates
            const globalPos = blockCreator.mapToGlobal(mouse.x, mouse.y);
            // Map into the draggableCanvas coordinate space
            const canvasPos = draggableCanvas.mapFromGlobal(globalPos.x, globalPos.y);

            if (blockDiagramComponent) {
                currentBlock = blockDiagramComponent.createObject(draggableCanvas, {
                    "x": canvasPos.x,
                    "y": canvasPos.y,
                    "parent": draggableCanvas
                });

                if (currentBlock) {
                    pressOffset = Qt.point(currentBlock.width / 2, currentBlock.height / 2);
                    currentBlock.x -= pressOffset.x;
                    currentBlock.y -= pressOffset.y;
                }
            }
        }

        onPositionChanged: (mouse) => {
            if (!currentBlock) return;

            const globalPos = blockCreator.mapToGlobal(mouse.x, mouse.y);
            const canvasPos = draggableCanvas.mapFromGlobal(globalPos.x, globalPos.y);

            currentBlock.x = canvasPos.x - pressOffset.x;
            currentBlock.y = canvasPos.y - pressOffset.y;
        }

        onReleased: function(mouse) {
            const globalPos = blockCreator.mapToGlobal(mouse.x, mouse.y);
            const item = draggableCanvas.childAt(mouse.x, mouse.y);
            if (item) {
                const objType = item.typeName ?? "Unknown";
                if (objType != "draggableCanvas") {
                    currentBlock.destroy();
                } else {
                    const localPos = item.mapFromGlobal(globalPos.x, globalPos.y);
                    currentBlock.parent = item;
                    currentBlock.x = localPos.x - pressOffset.x;
                    currentBlock.y = localPos.y - pressOffset.y;
                }
            }
            currentBlock = null;
        }
    }
}
