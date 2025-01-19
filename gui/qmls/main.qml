import QtQuick 6.0
import QtQuick.Controls 6.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600

    property var bezierConnections: []

    Anchor {
        id: anchor
        bezierConnections: bezierConnections
        x: 50
        y: 50
    }

    Anchor {
        id: anchor2
        bezierConnections: bezierConnections
        x: 211
        y: 222
    }
}
