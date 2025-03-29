import QtQuick 6.0
import QtQuick.Controls 6.0

Item {
    id: root
    anchors.fill: parent

    property string searchText: ""
    property Item draggableCanvas
    property Item rootObj

    ListModel {
        id: originalModel
        ListElement { name: "Break"; blockDiagramUrl: "Blocks/BreakBlock.qml" }
        ListElement { name: "Call Event"; blockDiagramUrl: "Blocks/CallEventBlock.qml" }
        ListElement { name: "End"; blockDiagramUrl: "Blocks/EndBlock.qml" }
        ListElement { name: "End"; blockDiagramUrl: "Blocks/EndBlock.qml" }
        ListElement { name: "If"; blockDiagramUrl: "Blocks/IfBlock.qml" }
        ListElement { name: "Start"; blockDiagramUrl: "Blocks/StartBlock.qml" }
    }

    ListModel {
        id: filteredModel
    }

    function updateFilter() {
        filteredModel.clear();
        for (let i = 0; i < originalModel.count; ++i) {
            const item = originalModel.get(i);
            if (searchText === "" ||
                item.name.toLowerCase().indexOf(searchText.toLowerCase()) !== -1) {
                filteredModel.append({
                    "name": item.name,
                    "blockDiagramUrl": item.blockDiagramUrl
                });
            }
        }
    }

    TextField {
        id: searchField
        placeholderText: "Search..."
        text: searchText
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        onTextChanged: {
            searchText = text;
            updateFilter();
        }
    }

    ScrollView {
        id: scrollView
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: searchField.bottom
        anchors.topMargin: 8
        anchors.bottom: parent.bottom

        ListView {
            id: listView
            model: filteredModel
            spacing: 6
            clip: true

            delegate: BlockCreator {
                blockName: model.name
                blockDiagramUrl: model.blockDiagramUrl
                draggableCanvas: root.draggableCanvas
                rootObj: root.rootObj
            }
        }
    }

    Component.onCompleted: updateFilter()
}
