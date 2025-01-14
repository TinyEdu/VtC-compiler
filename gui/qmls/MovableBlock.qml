import QtQuick 6.0

Rectangle {
    id: movableBlock
    width: 100
    height: 100
    z: 200
    color: "#4682b4"

    property real initialX: 0
    property real initialY: 0

    // Property to hold the C++ logic object
    property var blockLogic

    Component.onCompleted: {
        if(!blockLogic) {
            blockLogic = blockFactory.newComponent();

        }

        x = initialX;
        y = initialY;

        blockLogic.Associate(this)
    }

    MouseArea {
        anchors.fill: parent
        drag.target: parent
        onPressed: blockLogic.PressedMouse();
        onReleased: blockLogic.ReleasedMouse();

    }
}
