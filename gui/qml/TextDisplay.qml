// TextDisplay.qml
import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 200
    height: 50

    property color backgroundColor: "white"
    property color textColor: "black"
    property string displayText: "terminal..."

    Rectangle {
        anchors.fill: parent
        color: backgroundColor
        border.color: "#84818E"
        border.width: 1

        Text {
            id: textElement
            text: displayText
            anchors.centerIn: parent
            font.pointSize: 16
            color: textColor
        }
    }
}
