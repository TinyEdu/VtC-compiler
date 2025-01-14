import QtQuick 6.0

Rectangle {
    id: anchor
    width: 100
    height: 100
    z: 1
    color: "#ffa500"

    property real initialX: 0
    property real initialY: 0

    // Property to hold the C++ logic object
    property var anchorLogic

    Component.onCompleted: {
        anchorLogic.Associate(this);
        x = initialX;
        y = initialY;
    }

    Text {
        anchors.centerIn: parent
        text: "Anchor"
        color: "white"
    }
}
