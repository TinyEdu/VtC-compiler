// SearchableList.qml
import QtQuick
import QtQuick.Controls

import "Blocks"
import "Blocks/Operations"

Item {
    id: searchableList
    anchors.fill: parent

    property string searchText: ""

    Component {
        id: blockDiagram
        BlockDiagram {
            model: itemModel
        }
    }

    Component {
        id: breakBlock
        BreakBlock {
            model: itemModel
        }
    }

    Component {
        id: callEventBlock
        CallEventBlock {
            model: itemModel
        }
    }

    Component {
        id: createVariableBySignalBlock
        CreateVariableBySignalBlock {
            model: itemModel
        }
    }
    Component {
        id: createVariableByValueBlock
        CreateVariableByValueBlock {
            model: itemModel
        }
    }
    Component {
        id: endBlock
        EndBlock {
            model: itemModel
        }
    }
    Component {
        id: forLoopBlock
        ForLoopBlock {
            model: itemModel
        }
    }
    Component {
        id: getVariableBlock
        GetVariableBlock {
            model: itemModel
        }
    }
    Component {
        id: ifBlock
        IfBlock {
            model: itemModel
        }
    }
    Component {
        id: listenEventBlock
        ListenEventBlock {
            model: itemModel
        }
    }
    Component {
        id: printBySignalBlock
        PrintBySignalBlock {
            model: itemModel
        }
    }
    Component {
        id: printByValueBlock
        PrintByValueBlock {
            model: itemModel
        }
    }
    Component {
        id: setVariableBySignalBlock
        SetVariableBySignalBlock {
            model: itemModel
        }
    }

    Component {
        id: setVariableByValueBlock
        SetVariableByValueBlock {
            model: itemModel
        }
    }

    Component {
        id: skipBlock
        SkipBlock {
            model: itemModel
        }
    }
    Component {
        id: sleepBySignalBlock
        SleepBySignalBlock {
            model: itemModel
        }
    }
    Component {
        id: sleepByValueBlock
        SleepByValueBlock {
            model: itemModel
        }
    }
    Component {
        id: startBlock
        StartBlock {
            model: itemModel
        }
    }
    Component {
        id: valueBlock
        ValueBlock {
            model: itemModel
        }
    }
    Component {
        id: whileBlock
        WhileBlock {
            model: itemModel
        }
    }
    Component {
        id: binaryOperationBlock
        BinaryOperationBlock {
            model: itemModel
        }
    }
    Component {
        id: unaryOperationBlock
        UnaryOperationBlock {
            model: itemModel
        }
    }
    property var delegateMap: ({
        "blockDiagram": blockDiagram,
        "breakBlock": breakBlock,
        "callEventBlock": callEventBlock,
        "createVariableBySignalBlock": createVariableBySignalBlock,
        "createVariableByValueBlock": createVariableByValueBlock,
        "endBlock": endBlock,
        "forLoopBlock": forLoopBlock,
        "getVariableBlock": getVariableBlock,
        "ifBlock": ifBlock,

        "listenEventBlock": listenEventBlock,
        "printBySignalBlock": printBySignalBlock,
        "printByValueBlock": printByValueBlock,
        "setVariableBySignalBlock": setVariableBySignalBlock,
        "setVariableByValueBlock": setVariableByValueBlock,

        "skipBlock": skipBlock,
        "sleepBySignalBlock": sleepBySignalBlock,
        "sleepByValueBlock": sleepByValueBlock,
        "startBlock": startBlock,
        "valueBlock": valueBlock,

        "whileBlock": whileBlock,
        "binaryOperationBlock": binaryOperationBlock,
        "unaryOperationBlock": unaryOperationBlock
    })

    ListModel {
        id: originalModel

        ListElement {
            name: "Block 1"; blockDiagramUrl: "BlockDiagram.qml"; delegateKey: "blockDiagram"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/BreakBlock.qml"; delegateKey: "breakBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/CallEventBlock.qml"; delegateKey: "callEventBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/CreateVariableBySignalBlock.qml"; delegateKey: "createVariableBySignalBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"; delegateKey: "createVariableByValueBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/EndBlock.qml"; delegateKey: "endBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/ForLoopBlock.qml"; delegateKey: "forLoopBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/GetVariableBlock.qml"; delegateKey: "getVariableBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/IfBlock.qml"; delegateKey: "ifBlock"
        }

        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/ListenEventBlock.qml"; delegateKey: "listenEventBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/PrintBySignalBlock.qml"; delegateKey: "printBySignalBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/PrintByValueBlock.qml"; delegateKey: "printByValueBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/SetVariableBySignalBlock.qml"; delegateKey: "setVariableBySignalBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"; delegateKey: "setVariableByValueBlock"
        }

        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/SkipBlock.qml"; delegateKey: "skipBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/SleepBySignalBlock.qml"; delegateKey: "sleepBySignalBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/SleepByValueBlock.qml"; delegateKey: "sleepByValueBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/StartBlock.qml"; delegateKey: "startBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/ValueBlock.qml"; delegateKey: "valueBlock"
        }

        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/WhileBlock.qml"; delegateKey: "whileBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"; delegateKey: "binaryOperationBlock"
        }
        ListElement {
            name: "Block 2"; blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"; delegateKey: "unaryOperationBlock"
        }
    }

    ListModel {
        id: filteredModel
    }

    function updateFilter() {
        filteredModel.clear();
        for (let i = 0; i < originalModel.count; ++i) {
            const item = originalModel.get(i);
            if (searchText === "" || item.name.toLowerCase().indexOf(searchText.toLowerCase()) !== -1) {
                filteredModel.append({
                    "name": item.name,
                    "blockDiagramUrl": item.blockDiagramUrl,
                    "delegateKey": item.delegateKey,
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
            clip: false

            delegate: Item {
                parent: searchableList
                width: listView.width
                height: 140

                BlockCreator {
                    id: blockCreator
                    anchors.fill: parent
                    blockName: model.name
                    blockDiagramUrl: model.blockDiagramUrl
                    blockDiagramDelegate: delegateMap[model.delegateKey]
                    previewScaleFactor: 1.0
                }
            }
        }
    }

    Component.onCompleted: updateFilter()
}
