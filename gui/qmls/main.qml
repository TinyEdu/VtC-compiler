import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 600
    height: 400
    title: "Reusable Movable Block Example"

    Rectangle {
        anchors.fill: parent
        color: "#f0f0f0"

        MovableBlock {
            id: block1
            x: 100
            y: 150
            name: "Block 1"
        }

        MovableBlock {
            id: block2
            x: 300
            y: 150
            name: "Block 2"
        }

        Button {
            text: "Change Block 1 Color"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20

            // Toggle block1's color between blue and red
            onClicked: block1.blockColor = "red"
        }
    }
}
