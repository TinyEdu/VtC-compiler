import QtQuick 2.15

Item {
    id: rootDraw

    property int lineWidth: 8
    property color lineColor: "#FFF"
    property int startPointX
    property int startPointY
    property int endPointX
    property int endPointY
    z: 3
    
    property bool dottedAnimation: false

    Item {
        id: priv
        property int multiple: dottedAnimation ? 20 : 5;
    }

    Behavior on opacity {
        PropertyAnimation{ duration:1000 }
    }

    PathView {
        id: rooPath
        anchors.fill: parent
        model: (Math.abs(startPointX - endPointX)+ Math.abs(startPointY - endPointY))/priv.multiple
        interactive: false
        delegate: Rectangle{ color:lineColor;width:lineWidth;height:lineWidth;radius: lineWidth/2;smooth: true }
        path: Path {
            startX: startPointX; startY: startPointY
            PathLine {
                x:endPointX; y: endPointY
            }
        }

        SequentialAnimation{
            running: dottedAnimation
            loops: -1
            PropertyAnimation{ target: rooPath; property: "offset"; to: 0; duration: 0 }
            PropertyAnimation{ target: rooPath; property: "offset"; to: 1; duration: 500 }
        }
    }
}