// EditableButton.qml
import QtQuick
import QtQuick.Controls

Rectangle {
    id: customButton

    property color backgroundColor: "#84818E"
    property color pressedBackgroundColor: "#ffffff"
    property color borderColor: "#84818E"
    property color textColor: "#333333"
    property alias text: buttonText.text
    property bool pressed: false

    signal clicked()

    width: implicitWidth
    height: implicitHeight
    radius: 8
    color: pressed ? backgroundColor : pressedBackgroundColor
    border.color: borderColor
    border.width: 3

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: customButton.clicked()
        onPressedChanged: customButton.pressed = pressed
    }

    Text {
        id: buttonText
        anchors.centerIn: parent
        font.pixelSize: 24
        color: textColor
    }
}
