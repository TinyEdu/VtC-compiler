// BlockCreator.qml
import QtQuick
import QtQuick.Effects
import QtQuick.Controls

import BlockDiagramManager

Rectangle {
    id: blockCreator
    objectName: "blockCreator"

    property string blockName: ""
    property Component blockDiagramDelegate: BlockDiagram { model: itemModel }
    property url blockDiagramUrl: "BlockDiagram.qml"

    property Component blockDiagramComponent: null
    property var previewBlock: null
    property var previewScaleFactor: 1.0

    color: "#E0E0E0"
    border.color: "#000000"
    border.width: 1
    radius: 8

    Item {
        id: blockHolder
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: label.top
            margins: 5
        }

        onWidthChanged: if (previewBlock) Qt.callLater(createPreviewBlock)
        onHeightChanged: if (previewBlock) Qt.callLater(createPreviewBlock)
    }

    // Label aligned at the bottom
    Label {
        id: label
        text: blockName
        font.weight: Font.Bold
        font.pixelSize: 16
        height: 22
        color: "#404040"
        horizontalAlignment: Text.AlignHCenter
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            margins: 5
        }
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
        if (previewBlock) {
            previewBlock.destroy();
        }

        previewBlock = blockDiagramComponent.createObject(blockHolder, {
            "shouldBeRegistered": false,
            "enabled": true
        });

        if (!previewBlock) {
            console.error("Failed to create previewBlock.");
            return;
        }

        Qt.callLater(() => {
            const pw = previewBlock.implicitWidth || previewBlock.width;
            const ph = previewBlock.implicitHeight || previewBlock.height;

            const margin = 10;
            const cw = Math.max(1, blockHolder.width - margin);
            const ch = Math.max(1, blockHolder.height - margin);

            const scaleW = cw / pw;
            const scaleH = ch / ph;
            previewScaleFactor = Math.min(scaleW, scaleH);

            previewBlock.scale = previewScaleFactor;
            previewBlock.anchors.centerIn = blockHolder;
        });
    }

    MouseArea {
        id: spawnerArea
        objectName: "spawnerArea"
        anchors.fill: parent
        drag.target: parent
        acceptedButtons: Qt.LeftButton
        preventStealing: true
        z: 10

        onPressed: function (mouse) {
            itemModel.append({"x": mouse.x, "y": mouse.y});
        }

        onReleased: function (mouse) {
            var newestIndex = itemModel.count - 1;
            var newestObject = instantiator.objectAt(newestIndex);

            if (!newestObject.isIntersecting(mouse)) {
                itemModel.remove(newestIndex)
            }

            newestObject.parent = draggableCanvas.dragTarget;
            var localPos = blockCreator.mapToItem(draggableCanvas, Qt.point(mouse.x, mouse.y));
            newestObject.x  = (localPos.x - draggableCanvas.offsetX * draggableCanvas.currentScale) /
                draggableCanvas.currentScale;
            newestObject.y  = (localPos.y - draggableCanvas.offsetY * draggableCanvas.currentScale) /
                draggableCanvas.currentScale;
        }
    }

    ListModel {
        id: itemModel
    }

    Instantiator {
        id: instantiator
        model: itemModel
        delegate: blockDiagramDelegate

        onObjectAdded: (index, object) => {
            object.parent = dragLayer;
            object.model = itemModel;

            const itemData = itemModel.get(index);
            var localPos = blockCreator.mapToItem(dragLayer, Qt.point(itemData.x, itemData.y));
            object.x = localPos.x;
            object.y = localPos.y;

            object.blockCreator = blockCreator;
            spawnerArea.drag.target = object;

            object.Drag.active = true;
            object.z = 9999;
        }
    }
}
