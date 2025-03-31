// EditableConfirmField.qml
import QtQuick
import QtQuick.Controls

TextField {
    id: editableField
    placeholderText: "value"
    height: contentItem.height
    property bool isConfirmed: false

    padding: 6
    verticalAlignment: Text.AlignVCenter

    onAccepted: {
        isConfirmed = true
        readOnly = true
    }

    onPressed: {
        if (readOnly) {
            readOnly = false
            isConfirmed = false
            forceActiveFocus()
            selectAll()
        }
    }

    background: Rectangle {
        color: editableField.isConfirmed ? "#eeeeee" : "white"
        radius: 4
    }
}
