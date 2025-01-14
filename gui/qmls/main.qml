import QtQuick 6.0
import QtQuick.Controls 6.0
import MovableBlock 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "MovableBlock Example"

    Rectangle {
        id: canvas
        anchors.fill: parent
        color: "#f0f0f0"

        Button {
            text: "Add Block"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: createBlockUI();
        }
    }

    function createBlockUI() {
        let block = blockFactory.createBlock();
        let component = Qt.createComponent(block.qmlName);
        if (component.status === Component.Ready) {
            let blockItem = component.createObject(canvas, {
                blockLogic: block,
                initialX: 100,
                initialY: 100
            });
        }

    }
}
