import QtQuick
import QtQuick.Controls

Item {
    id: searchableList
    anchors.fill: parent

    property string searchText: ""
    property Item draggableCanvas
    property Item rootObj

    ListModel {
        id: originalModel

        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CallEventBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/ForLoopBlock.qml"}
        ListElement { blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"}
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
                    "name": "name",
                    "blockDiagramUrl": item.blockDiagramUrl,
                    "previewScaleFactor": 1.0
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

        height: 40
        font.pixelSize: 18
        verticalAlignment: Text.AlignVCenter
        padding: 10

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
                parent: searchableList
                blockName: "name"
                blockDiagramUrl: model.blockDiagramUrl
                previewScaleFactor: 1.0

                draggableCanvas: searchableList.draggableCanvas
                rootObj: searchableList.rootObj
            }
        }
    }

    Component.onCompleted: updateFilter()
}
