// Theme.qml
pragma Singleton
import QtQuick 6.5

QtObject {
    property bool darkMode: true

    property color backgroundColor: darkMode ? "#161E24" : "#FCFCFF"
    property color borderColor: darkMode ? "#2A3947" : "#3E5469"

    property color accentColor: "#4EA5F0"
    property color lightAccentColor: "#E0E0E0"
    property color darkAccentColor: "#446587"

    property int borderWidth: 1
    property int anchorBorderRadius: 8
}
