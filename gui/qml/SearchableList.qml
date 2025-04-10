// SearchableList.qml
import QtQuick
import QtQuick.Controls

import "Blocks"
import "Blocks/Operations"

Item {
    id: searchableList
    anchors.fill: parent

    property string searchText: ""
    property var blockCreators: []

    // --- Delegate components ---
    Component { id: blockDiagram; BlockDiagram { model: itemModel } }
    Component { id: breakBlock; BreakBlock { model: itemModel } }
    Component { id: callEventBlock; CallEventBlock { model: itemModel } }
    Component { id: createVariableBySignalBlock; CreateVariableBySignalBlock { model: itemModel } }
    Component { id: createVariableByValueBlock; CreateVariableByValueBlock { model: itemModel } }
    Component { id: endBlock; EndBlock { model: itemModel } }
    Component { id: forLoopBlock; ForLoopBlock { model: itemModel } }
    Component { id: getVariableBlock; GetVariableBlock { model: itemModel } }
    Component { id: ifBlock; IfBlock { model: itemModel } }
    Component { id: listenEventBlock; ListenEventBlock { model: itemModel } }
    Component { id: printBySignalBlock; PrintBySignalBlock { model: itemModel } }
    Component { id: printByValueBlock; PrintByValueBlock { model: itemModel } }
    Component { id: setVariableBySignalBlock; SetVariableBySignalBlock { model: itemModel } }
    Component { id: setVariableByValueBlock; SetVariableByValueBlock { model: itemModel } }
    Component { id: skipBlock; SkipBlock { model: itemModel } }
    Component { id: sleepBySignalBlock; SleepBySignalBlock { model: itemModel } }
    Component { id: sleepByValueBlock; SleepByValueBlock { model: itemModel } }
    Component { id: startBlock; StartBlock { model: itemModel } }
    Component { id: valueBlock; ValueBlock { model: itemModel } }
    Component { id: whileBlock; WhileBlock { model: itemModel } }
    Component { id: binaryOperationBlock; BinaryOperationBlock { model: itemModel } }
    Component { id: unaryOperationBlock; UnaryOperationBlock { model: itemModel } }

    // --- BlockCreator wrapper ---
    Component {
        id: blockCreatorComponent
        BlockCreator {
            width: contentColumn.width
            height: 140
        }
    }

    // --- Delegate lookup map ---
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

    // --- Original static block list ---
    ListModel {
        id: originalModel

        ListElement { name: "Start"; blockDiagramUrl: "Blocks/StartBlock.qml"; delegateKey: "startBlock" }
        ListElement { name: "End"; blockDiagramUrl: "Blocks/EndBlock.qml"; delegateKey: "endBlock" }
        ListElement { name: "Print (By Signal)"; blockDiagramUrl: "Blocks/PrintBySignalBlock.qml"; delegateKey: "printBySignalBlock" }
        ListElement { name: "Print (By Value)"; blockDiagramUrl: "Blocks/PrintByValueBlock.qml"; delegateKey: "printByValueBlock" }
        ListElement { name: "Value"; blockDiagramUrl: "Blocks/ValueBlock.qml"; delegateKey: "valueBlock" }

        ListElement { name: "Break"; blockDiagramUrl: "Blocks/BreakBlock.qml"; delegateKey: "breakBlock" }
        ListElement { name: "Call Event"; blockDiagramUrl: "Blocks/CallEventBlock.qml"; delegateKey: "callEventBlock" }
        ListElement { name: "Create Variable (By Signal)"; blockDiagramUrl: "Blocks/CreateVariableBySignalBlock.qml"; delegateKey: "createVariableBySignalBlock" }
        ListElement { name: "Create Variable (By Value)"; blockDiagramUrl: "Blocks/CreateVariableByValueBlock.qml"; delegateKey: "createVariableByValueBlock" }
        ListElement { name: "For Loop"; blockDiagramUrl: "Blocks/ForLoopBlock.qml"; delegateKey: "forLoopBlock" }
        ListElement { name: "Get Variables"; blockDiagramUrl: "Blocks/GetVariableBlock.qml"; delegateKey: "getVariableBlock" }
        ListElement { name: "If Condition"; blockDiagramUrl: "Blocks/IfBlock.qml"; delegateKey: "ifBlock" }
        ListElement { name: "Listen Event"; blockDiagramUrl: "Blocks/ListenEventBlock.qml"; delegateKey: "listenEventBlock" }
        ListElement { name: "Ser Variable (By Signal)"; blockDiagramUrl: "Blocks/SetVariableBySignalBlock.qml"; delegateKey: "setVariableBySignalBlock" }
        ListElement { name: "Ser Variable (By Value)"; blockDiagramUrl: "Blocks/SetVariableByValueBlock.qml"; delegateKey: "setVariableByValueBlock" }
        ListElement { name: "Skip"; blockDiagramUrl: "Blocks/SkipBlock.qml"; delegateKey: "skipBlock" }
        ListElement { name: "While Loop"; blockDiagramUrl: "Blocks/WhileBlock.qml"; delegateKey: "whileBlock" }
        ListElement { name: "Binary Operation"; blockDiagramUrl: "Blocks/Operations/BinaryOperationBlock.qml"; delegateKey: "binaryOperationBlock" }
        ListElement { name: "Unary Operation"; blockDiagramUrl: "Blocks/Operations/UnaryOperationBlock.qml"; delegateKey: "unaryOperationBlock" }
    }

    // --- Search input ---
    EditableConfirmField {
        id: searchField
        placeholderText: "Search..."
        text: searchText

        anchors {
            left: parent.left
            right: parent.right
            top: parent.top

            margins: 4
        }

        height: 40
        font.pixelSize: 18
        verticalAlignment: Text.AlignVCenter
        padding: 10

        onTextChanged: {
            searchText = text;
            for (let i = 0; i < blockCreators.length; ++i) {
                const entry = blockCreators[i];
                entry.ref.visible = searchText === "" || entry.name.toLowerCase().indexOf(searchText.toLowerCase()) !== -1;
            }
        }
    }

    // --- Scrollable list of static BlockCreators ---
    Flickable {
        id: flickable
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: searchField.bottom
        anchors.bottom: parent.bottom
        contentWidth: width
        contentHeight: contentColumn.implicitHeight
        clip: true

        Column {
            id: contentColumn
            width: flickable.width
            spacing: 6
        }
    }

    // --- Instantiate all blocks once on startup ---
    Component.onCompleted: {
        for (let i = 0; i < originalModel.count; ++i) {
            const item = originalModel.get(i);
            const creator = blockCreatorComponent.createObject(contentColumn, {
                blockName: item.name,
                blockDiagramUrl: item.blockDiagramUrl,
                blockDiagramDelegate: delegateMap[item.delegateKey],
                previewScaleFactor: 1.0
            });
            creator.visible = searchText === "" || item.name.toLowerCase().indexOf(searchText.toLowerCase()) !== -1;
            blockCreators.push({ name: item.name, ref: creator });
        }
    }
}
