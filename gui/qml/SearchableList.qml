// SearchableList.qml
import QtQuick
import QtQuick.Controls

import "Blocks"

Item {
    id: searchableList
    anchors.fill: parent

    property string searchText: ""

    Component {
        id: blockDiagram
        BlockDiagram { model: itemModel }
    }

    Component {
        id: breakBlock
        BreakBlock { model: itemModel }
    }

    property var delegateMap: ({
        "blockDiagram": blockDiagram,
        "breakBlock": breakBlock
    })

    ListModel {
        id: originalModel

        ListElement { name: "Block 1"; blockDiagramUrl: "BlockDiagram.qml"; delegateKey: "blockDiagram" }
        ListElement { name: "Block 2"; blockDiagramUrl: "Blocks/BreakBlock.qml"; delegateKey: "breakBlock" }
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
