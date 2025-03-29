import QtQuick 6.0
import QtQuick.Controls 6.0

Item {
    id: root
    width: 400
    height: 600

    property string searchText: ""
    property Item draggableCanvas

    ListModel {
        id: originalModel
        ListElement { name: "Break"; blockDiagramUrl: "Blocks/BreakBlock.qml" }
        ListElement { name: "Call Event"; blockDiagramUrl: "Blocks/CallEventBlock.qml" }
        ListElement { name: "End"; blockDiagramUrl: "Blocks/EndBlock.qml" }
        ListElement { name: "If"; blockDiagramUrl: "Blocks/IfBlock.qml" }
        ListElement { name: "Start"; blockDiagramUrl: "Blocks/StartBlock.qml" }
    }

    ListModel {
        id: filteredModel
    }

    function updateFilter() {
        filteredModel.clear();
        for (var i = 0; i < originalModel.count; i++) {
            var item = originalModel.get(i);
            if (searchText === "" ||
                item.name.toLowerCase().indexOf(searchText.toLowerCase()) !== -1) {
                filteredModel.append({
                    "name": item.name,
                    "blockDiagramUrl": item.blockDiagramUrl
                });
            }
        }
    }

    Column {
        anchors.fill: parent
        spacing: 10

        TextField {
            id: searchField
            placeholderText: "Search..."
            text: searchText
            onTextChanged: {
                searchText = text;
                updateFilter();
            }
        }

        Component.onCompleted: updateFilter();

        ScrollView {
            id: scrollArea
            width: parent.width
            height: parent.height - searchField.height - 20

            ListView {
                id: listView
                width: parent.width
                height: parent.height
                model: filteredModel
                delegate: BlockCreator {
                    blockName: model.name
                    blockDiagramUrl: model.blockDiagramUrl
                    draggableCanvas: root.draggableCanvas
                }

            }
        }
    }
}
