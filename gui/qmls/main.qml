import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    color: "black"

    BlockDiagram {
        width: 140
        height: 80
        name: "function1"
    }

    BlockDiagram {
        width: 140
        height: 80
        name: "function2"
        blockColor: "yellow"
        barColor: "orange"
    }

    BezierConnection {
        startX: 40
        startY: 100
        endX: 200
        endY: 100
        anchors.fill: parent
    }
}
