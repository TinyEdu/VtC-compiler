import QtQuick 6.0

Rectangle {
    id: movableBlock
    width: 100
    height: 100
    color: "#4682b4"

    property real initialX: 0
    property real initialY: 0
    property var blockLogic // To hold the C++ MovableBlock instance

    Component.onCompleted: {
        x = initialX;
        y = initialY;
    }

    MouseArea {
        anchors.fill: parent
        drag.target: parent

        onReleased: blockLogic.ReleasedMouse();

    }
}
