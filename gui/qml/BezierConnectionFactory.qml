// bezierConnectionFactory.qml
import QtQuick
import QtQuick.Controls

import CollisionManager

Item {
    id: bezierConnectionFactory

    property var draggableCanvas

    ListModel {
        id: itemModel
    }

    Instantiator {
        id: instantiator
        model: itemModel
        delegate: BezierConnection { }

        onObjectAdded: function(index, connection) {
            const itemData = itemModel.get(index);
            connection.leftAnchor = itemData.leftAnchor;
        }
    }

    function startConnection(anchor) {
        itemModel.append({ "leftAnchor": anchor });
        return itemModel.count - 1;
    }

    function releaseConnection(anchor, mousePos) {
        const rootItem = (anchor.Window ? anchor.Window.contentItem : anchor.parent);
        const globalMousePos = anchor.mapToItem(rootItem, mousePos.x, mousePos.y);
        const item = CollisionManager.isOverAnAnchor(globalMousePos.x, globalMousePos.y, anchor);
        const index = itemModel.count - 1;

        if (item !== null && item.visible && item.enabled && item.anchorDirection !== anchor.anchorDirection &&
            item.anchorType === anchor.anchorType) {
            // in case there is already a connection
            if (item.connectionIndex) {
                itemModel.remove(item.connectionIndex);
            }

            item.connectionIndex = anchor.connectionIndex;
            return index;
        }

        itemModel.remove(index)
        anchor.connectionIndex = 1;
        return -1;
    }

    function updateConnectionPosition(connectionIndex, mouse, anchor) {
        let mousePos = anchor.mapToItem(draggableCanvas, mouse.x, mouse.y);

        var connection = instantiator.objectAt(connectionIndex);
        connection.updateWithMousePosition(mousePos.x, mousePos.y);
    }

    function deleteConnection(connectionIndex) {
        var connection = instantiator.objectAt(connectionIndex);
        connection.reset();
        itemModel.remove(connectionIndex);
    }
}
