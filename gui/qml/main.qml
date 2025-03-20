import QtQuick 6.0
import QtQuick.Controls 6.0

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: qsTr("Searchable BlockCreator List Example")

    SearchableList {
        anchors.fill: parent
    }
}
