import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ComboBox {
    id: root
    model: [""]
    implicitHeight: 55
    implicitWidth: 300

    property real radius: 4
    property color backgroundColor: "white"
    property color checkedColor: "white"

    property var borderWidth: 0
    property var borderColor: "black"

    delegate: ItemDelegate {
        id: itemDelegate
        width: root.implicitWidth * 1.2
        height: root.implicitHeight
        hoverEnabled: true
        focus: true

        background: Rectangle {
            anchors.fill: parent
            radius: 8
            color: itemDelegate.hovered ? root.backgroundColor : "transparent"
        }

        RowLayout {
            Layout.alignment: Qt.AlignVCenter
            width: parent.width
            height: parent.height
            anchors.fill: parent
            spacing: 10
            Layout.leftMargin: 2
            Layout.rightMargin: 10

            Label {
                opacity: 0.9
                text: modelData
                font.pixelSize: 11
                color: itemDelegate.hovered ? "black" : "gray"
                Layout.fillWidth: true
                verticalAlignment: Text.AlignVCenter
                Layout.alignment: Qt.AlignVCenter
                Layout.leftMargin: 3
            }
        }
    }

    contentItem: Item {
        width: root.background.width - root.indicator.width - 10
        height: root.background.height

        RowLayout {
            anchors.fill: parent
            spacing: 10

            Label {
                opacity: 0.9
                text: root.displayText
                font.pixelSize: 11
                Layout.fillWidth: true
                verticalAlignment: Text.AlignVCenter
                Layout.alignment: Qt.AlignVCenter
                Layout.leftMargin: 3
                color: "black"
            }
        }
    }

    background: Rectangle {
        implicitWidth: root.implicitWidth
        implicitHeight: root.implicitHeight
        color: root.down ? Qt.darker(root.checkedColor, 1.2) : root.checkedColor
        radius: root.radius
        border.width: root.activeFocus ? borderWidth : borderWidth * 0.8
        border.color: root.activeFocus ? borderColor : "gray"
    }

    popup: Popup {
        y: root.height + 2
        width: root.implicitWidth
        implicitHeight: Math.min(contentItem.implicitHeight, 250)
        padding: 4

        contentItem: ListView {
            leftMargin: 3
            implicitHeight: contentHeight
            keyNavigationEnabled: true
            model: root.popup.visible ? root.delegateModel : null
            clip: true
            focus: true
            currentIndex: root.highlightedIndex
        }

        background: Rectangle {
            anchors.fill: parent
            color: "white"
            radius: 6
            border.width: borderWidth * 0.8
            border.color: borderColor
            clip: true
        }
    }
}
