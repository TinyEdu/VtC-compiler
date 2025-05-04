import QtQuick 6.5
import QtQuick.Controls 6.5

Rectangle {
    id: terminalDisplay
    anchors.fill: parent

    property color backgroundColor: "#ffffff"
    property color textColor: "#333333"

    border.color: "black"
    border.width: 1

    Flickable {
        id: flickable
        anchors.fill: parent
        contentWidth: width
        contentHeight: contentColumn.implicitHeight
        clip: true

        Rectangle {
            width: flickable.width
            height: contentColumn.implicitHeight
            color: terminalDisplay.backgroundColor

            Column {
                id: contentColumn
                width: flickable.width
            }
        }
    }

    function append(newText) {
        lineComponent.createObject(contentColumn, {
            lineText: newText,
            lineColor: terminalDisplay.textColor
        })
        Qt.callLater(() => {
            flickable.contentY = flickable.contentHeight - flickable.height
        })
    }

    Component {
        id: lineComponent
        Text {
            id: lineTextItem
            property alias lineText: lineTextItem.text
            property alias lineColor: lineTextItem.color
            width: parent.width
            wrapMode: Text.Wrap
        }
    }
}
