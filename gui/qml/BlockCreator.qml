import QtQuick 6.0
import QtQuick.Controls 6.0

Rectangle {
    id: blockCreator
    anchors.left: parent.left
    anchors.right: parent.right
    height: Math.max(label.height + blockHolder.implicitHeight + 10, 100)
    color: "#E0E0E0"
    border.color: "#B0B0B0"
    radius: 8

    property string blockName: ""
    property url blockDiagramUrl: "BlockDiagram.qml"
    property var currentBlock: null

    property Item draggableCanvas
    property Item rootObj

    property Component blockDiagramComponent: null
    property var previewBlock: null

    Item {
        id: blockHolder
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: label.top
            margins: 6
        }
        height: implicitHeight
    }

    Label {
        id: label
        text: blockName
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 22
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
        color: "#404040"
    }

    Component.onCompleted: {
        if (blockDiagramUrl !== "") {
            blockDiagramComponent = Qt.createComponent(blockDiagramUrl);

            if (blockDiagramComponent.status === Component.Ready) {
                createPreviewBlock();
            } else if (blockDiagramComponent.status === Component.Loading) {
                blockDiagramComponent.statusChanged.connect(function() {
                    if (blockDiagramComponent.status === Component.Ready) {
                        createPreviewBlock();
                    } else if (blockDiagramComponent.status === Component.Error) {
                        console.error("Error loading component:", blockDiagramComponent.errorString());
                    }
                });
            } else if (blockDiagramComponent.status === Component.Error) {
                console.error("Component load error:", blockDiagramComponent.errorString());
            }
        }
    }

    function createPreviewBlock() {
        if (previewBlock) previewBlock.destroy();

        previewBlock = blockDiagramComponent.createObject(blockHolder, {
            scale: Math.min(blockCreator.width, blockCreator.height) / 150
        });

        if (previewBlock) {
            previewBlock.name = blockName;

            // ✅ Manual centering
            previewBlock.x = (blockHolder.width - previewBlock.width * previewBlock.scale) / 2;
            previewBlock.y = (blockHolder.height - previewBlock.height * previewBlock.scale) / 2;
        } else {
            console.error("Failed to create previewBlock.");
        }
    }

    MouseArea {
        anchors.fill: parent
        preventStealing: true
        hoverEnabled: true

        property point pressOffset: Qt.point(0, 0)

        onPressed: (mouse) => {
            const globalPos = blockCreator.mapToGlobal(mouse.x, mouse.y);
            const scenePos = rootObj.mapFromGlobal(globalPos.x, globalPos.y);

            if (blockDiagramComponent) {
                currentBlock = blockDiagramComponent.createObject(rootObj, {
                    x: scenePos.x,
                    y: scenePos.y,
                    z: 1000
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
            const scenePos = rootObj.mapFromGlobal(globalPos.x, globalPos.y);

            currentBlock.x = scenePos.x - pressOffset.x;
            currentBlock.y = scenePos.y - pressOffset.y;
        }

        onReleased: function(mouse) {
            const dropTarget = findCanvasDropTarget(mouse.x, mouse.y);

            if (dropTarget) {
                const globalPos = blockCreator.mapToGlobal(mouse.x, mouse.y);
                const contentItem = dropTarget.contentItem;
                const localPos = contentItem.mapFromGlobal(globalPos.x, globalPos.y);

                currentBlock.parent = contentItem;
                currentBlock.x = localPos.x - pressOffset.x / dropTarget.currentScale;
                currentBlock.y = localPos.y - pressOffset.y / dropTarget.currentScale;
                currentBlock.z = 3;
            } else {
                currentBlock.destroy();
            }

            currentBlock = null;
        }

        function findCanvasDropTarget(x, y) {
            function findIn(item) {
                if (!item || !item.visible || !item.enabled) return null;

                if (item.typeName === "draggableCanvas") {
                    const localPos = item.mapFromItem(blockCreator, x, y);
                    if (localPos.x >= 0 && localPos.x <= item.width &&
                        localPos.y >= 0 && localPos.y <= item.height) {
                        return item;
                    }
                }

                if (item.children) {
                    for (let i = item.children.length - 1; i >= 0; --i) {
                        const result = findIn(item.children[i]);
                        if (result) return result;
                    }
                }

                return null;
            }

            return findIn(rootObj);
        }
    }
}
