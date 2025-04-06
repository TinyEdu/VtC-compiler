// Anchor.qml
import QtQuick
import QtQuick.Controls
import CollisionManager

Rectangle {
    id: anchor

    width: 20
    height: 20

    color: "white"

    property BezierConnection connection

    property var anchorId
    property string anchorDirection: "left"
    property string anchorType: "anchor"

}
