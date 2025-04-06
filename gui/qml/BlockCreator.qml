// BlockCreator.qml
import QtQuick
import QtQuick.Effects
import QtQuick.Controls

import BlockDiagramManager

Rectangle {
    id: blockCreator
    objectName: "blockCreator"

    MouseArea {
        id: spawnerArea
        objectName: "spawnerArea"

        anchors.fill: parent
        drag.target: parent
        acceptedButtons: Qt.LeftButton

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
        delegate: BlockDiagram {
            model: itemModel
        }

        onObjectAdded: (index, object) => {
            object.parent = blockCreator.parent;

            object.model = itemModel;

            const itemData = itemModel.get(index);
            var localPos = blockCreator.mapToItem(blockCreator.parent, Qt.point(itemData.x, itemData.y));
            object.x = localPos.x;
            object.y = localPos.y;

            spawnerArea.drag.target = object;

            object.Drag.active = true;
            object.z = 9999;
        }
    }
}
