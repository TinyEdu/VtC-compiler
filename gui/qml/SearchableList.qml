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

        ListElement { name: "Break"; blockDiagramUrl: "Blocks/BreakBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Call Event"; blockDiagramUrl: "Blocks/CallEventBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Create Variable (by signal)"; blockDiagramUrl: "Blocks/CreateVariableBySignalBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Create Variable (by value)"; blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "End Block"; blockDiagramUrl: "Blocks/EndBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "For Loop"; blockDiagramUrl: "Blocks/ForLoopBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Get Variable"; blockDiagramUrl: "Blocks/GetVariableBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "If"; blockDiagramUrl: "Blocks/IfBlock.qml"; previewScaleFactor: 1.1 }
        ListElement { name: "Listen for Event"; blockDiagramUrl: "Blocks/ListenEventBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Print"; blockDiagramUrl: "Blocks/PrintBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Set Variable (by signal)"; blockDiagramUrl: "Blocks/SetVariableBySignalBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Set Variable (by value)"; blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Skip"; blockDiagramUrl: "Blocks/SkipBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Sleep (by signal)"; blockDiagramUrl: "Blocks/SleepBySignalBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Sleep (by value)"; blockDiagramUrl: "Blocks/SleepByValueBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Start Block"; blockDiagramUrl: "Blocks/StartBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Value"; blockDiagramUrl: "Blocks/ValueBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "While Loop"; blockDiagramUrl: "Blocks/WhileBlock.qml"; previewScaleFactor: 1.33 }

        ListElement { name: "While Loop"; blockDiagramUrl: "Blocks/WhileBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "While Loop"; blockDiagramUrl: "Blocks/WhileBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "While Loop"; blockDiagramUrl: "Blocks/WhileBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "While Loop"; blockDiagramUrl: "Blocks/WhileBlock.qml"; previewScaleFactor: 1.33 }

        ListElement { name: "Adding Binary Operation"; blockDiagramUrl: "Blocks/Operations/AddingBinaryOperationBlock.qml"; previewScaleFactor: 1.33 }
        ListElement { name: "Negation Operation"; blockDiagramUrl: "Blocks/Operations/NegationUnaryOperationBlock.qml"; previewScaleFactor: 1.33 }
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
                    "blockDiagramUrl": item.blockDiagramUrl,
                    "previewScaleFactor": item.previewScaleFactor
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
                blockName: model.name
                blockDiagramUrl: model.blockDiagramUrl
                previewScaleFactor: model.previewScaleFactor
                draggableCanvas: root.draggableCanvas
                rootObj: root.rootObj
            }
        }
    }

    Component.onCompleted: updateFilter()
}
