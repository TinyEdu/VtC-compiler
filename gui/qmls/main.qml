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

        // Button to add a new MovableBlock
        Button {
            text: "Add Block"
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 10
            onClicked: createBlockUI();
        }

        // Button to add a new Anchor
        Button {
            text: "Add Anchor"
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 10
            onClicked: createAnchorUI();
        }
    }

    // Function to create and display a MovableBlock
    function createBlockUI() {
        let block = blockFactory.newComponent();
        let component = Qt.createComponent(block.qmlName);
        if (component.status === Component.Ready) {
            let blockItem = component.createObject(canvas, {
                blockLogic: block,
                initialX: 100,
                initialY: 100
            });
        }
    }

    function createAnchorUI() {
        let anchor = anchorFactory.newComponent();
        let component = Qt.createComponent(anchor.qmlName);
        if (component.status === Component.Ready) {
            let anchorItem = component.createObject(canvas, {
                anchorLogic: anchor,
                initialX: Math.floor(Math.random() * (600)),
                initialY: 100
            });
        }
    }
}
