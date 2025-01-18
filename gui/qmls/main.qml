import QtQuick 6.0
import QtQuick.Controls 6.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true

    Rectangle {
        id: parentItem
        width: 222
        height: 222
        color: "#dddddd"

        Anchor {
            id: movableChildA
            x: 50
            y: 50
        }

        MouseArea {
            id: dragAreaB
            anchors.fill: parent
            drag.target: parent

            onPressed: {
                if (!movableChildA.containsMouse) {
                    console.log("b");
                }
            }
        }

    }
}
