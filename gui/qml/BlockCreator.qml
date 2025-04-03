import QtQuick
import QtQuick.Controls

Rectangle {
    id: blockCreator
    width: parent ? parent.width : 100

    property string blockName: ""
    property url blockDiagramUrl: "BlockDiagram.qml"
    property var currentBlock: null
    property Item draggableCanvas
    property Item rootObj

    property Component blockDiagramComponent: null
    property var previewBlock: null
    property var previewScaleFactor: null

    color: "#E0E0E0"
    border.color: "#000000"
    radius: 8

    Column {
        id: layoutColumn
        anchors.fill: parent
        anchors.margins: 5
        spacing: 5

        Item {
            id: blockHolder
            width: parent.width
            implicitHeight: previewBlock ? previewBlock.implicitHeight : 0
        }

        Label {
            id: label
            text: blockName
            font.weight: Font.Bold
            font.pixelSize: 16
            height: 22
            color: "#404040"
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Component.onCompleted: {
        if (blockDiagramUrl !== "") {
            blockDiagramComponent = Qt.createComponent(blockDiagramUrl);

            if (blockDiagramComponent.status === Component.Ready) {
                createPreviewBlock();
            } else if (blockDiagramComponent.status === Component.Loading) {
                blockDiagramComponent.statusChanged.connect(function () {
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
            "anchors.centerIn": blockHolder, "scale": previewScaleFactor, "shouldBeRegistered": false
        });

        if (previewBlock) {
            Qt.callLater(() => {
                blockHolder.implicitHeight = previewBlock.implicitHeight || previewBlock.height;
                blockCreator.height = label.height + blockHolder.implicitHeight + 20;
            });
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
                    x: scenePos.x, y: scenePos.y, z: 1000
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

        onReleased: function (mouse) {
            if (draggableCanvas) {
                const globalPos = blockCreator.mapToGlobal(mouse.x, mouse.y);
                const contentItem = draggableCanvas.contentItem;
                const localPos = contentItem.mapFromGlobal(globalPos.x, globalPos.y);

                currentBlock.parent = contentItem;
                currentBlock.x = localPos.x - pressOffset.x / draggableCanvas.currentScale;
                currentBlock.y = localPos.y - pressOffset.y / draggableCanvas.currentScale;
                currentBlock.z = 3;
            } else {
                currentBlock.destroy();
            }

            currentBlock = null;
        }
    }
}
