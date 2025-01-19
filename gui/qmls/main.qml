import QtQuick 6.0
import QtQuick.Controls 6.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600

    property var bezierConnections: []

    BlockDiagram {
        name: "function1"
        x: 333
        y: 333
    }
    BlockDiagram {
        name: "function2"
        x: 100
        y: 100
    }
    BlockDiagram {
        name: "function3"
        x: 400
        y: 144
    }
}
