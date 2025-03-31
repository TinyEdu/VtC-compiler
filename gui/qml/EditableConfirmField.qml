// EditableConfirmField.qml
import QtQuick
import QtQuick.Controls

TextField {
    id: editableField
    placeholderText: "value"
    height: contentItem.height  // Ensure TextField height adjusts to the content

    property bool isConfirmed: false

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

    // Adjust padding
    padding: 6

    // Background color adjustment
    background: Rectangle {
        color: editableField.isConfirmed ? "#eeeeee" : "white"
        radius: 4
    }

    // Ensure proper vertical alignment
    verticalAlignment: Text.AlignVCenter
}
