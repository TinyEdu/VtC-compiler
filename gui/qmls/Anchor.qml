import QtQuick 6.0
import Anchor 1.0

Item {
    id: anchor
    width: 100
    height: 100

    // Visual representation of the anchor
    Rectangle {
        anchors.fill: parent
        color: anchor.color // Bind to the C++ property
        border.color: "black"
    }
}
