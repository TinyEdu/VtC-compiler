import QtQuick 6.0
import QtQuick.Controls 6.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600

    property var bezierConnections: []

    Anchor {
        id: anchor
        connections: bezierConnections
        isLeft: true
        x: 50
        y: 50
    }

    Anchor {
        id: anchor2
        connections: bezierConnections
        isLeft: false
        x: 211
        y: 222
    }

    BlockDiagram {
        x: 333
        y: 333
    }
}
