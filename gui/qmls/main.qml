import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Dynamic MovableBlock Example"

    Rectangle {
        id: canvas
        anchors.fill: parent
    }

    Button {
        text: "Add Block"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: {
            let newBlock = blockFactory.createBlock(); // Call exposed factory method
            createBlockUI(newBlock);
        }
    }

    function createBlockUI(block) {
        let component = Qt.createComponent(block.qmlName);
        if (component.status === Component.Ready) {
            let blockItem = component.createObject(canvas, {
                x: Math.random() * (canvas.width - 50),
                y: Math.random() * (canvas.height - 50)
            });
            blockItem.blockLogic = block;
        } else {
            console.error("Component is not ready:", component.errorString());
        }
    }
}
