import QtQuick 6.0
import QtQuick.Controls 6.0

Rectangle {
    id: blockCreator
    width: 100
    height: 120
    color: "#E0E0E0"
    border.color: "#B0B0B0"
    radius: 4

    property Component blockDiagramComponent: Qt.createComponent("BlockDiagram.qml")
    property var currentBlock: null

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
        text: previewBlock.name
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

    property var previewBlock: null

    Component.onCompleted: {
        previewBlock = blockDiagramComponent.createObject(blockHolder, {
            "scale": 0.7,
            "anchors.centerIn": blockHolder
        });
    }

    MouseArea {
        anchors.fill: parent

        onPressed: (mouse) => {
            let globalPos = blockCreator.mapToItem(blockCreator.parent, mouse.x, mouse.y);
            currentBlock = blockDiagramComponent.createObject(blockCreator.parent, {
                "x": globalPos.x,
                "y": globalPos.y
            });

            currentBlock.x -= currentBlock.width / 2;
            currentBlock.y -= currentBlock.height / 2;
        }

        onPositionChanged: (mouse) => {
            if (currentBlock) {
                let globalPos = blockCreator.mapToItem(blockCreator.parent, mouse.x, mouse.y);
                currentBlock.x = Math.max(0, Math.min(globalPos.x - currentBlock.width / 2, blockCreator.parent.width - currentBlock.width));
                currentBlock.y = Math.max(0, Math.min(globalPos.y - currentBlock.height / 2, blockCreator.parent.height - currentBlock.height));
                currentBlock.updateAnchors();
            }
        }

        onReleased: {
            currentBlock = null;
        }
    }
}
