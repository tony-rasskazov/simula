import QtQuick 2.4

Item {
    width: 200
    height: 60
    property alias _name: _name.text
    property alias _descr: _descr.text
    property alias _img: _img.source
    property int direction: direction

    Rectangle {
        id: rectangle1
        color: "#d2d2d2"
        anchors.rightMargin: 0
        anchors.bottomMargin: 2
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Text {
            id: _name
            x: 32
            y: 5
            width: 31
            height: 15
            text: "DEVICE TITLE"
            font.pixelSize: 12
        }

        Image {
            id: _img
            x: 5
            y: 5
            width: 24
            height: 24
            source: "qrc:/res/cam.png"
        }

        Text {
            id: _descr
            x: 32
            y: 20
            width: 31
            height: 15
            color: "#5e5c5c"
            text: "DEV DESCR"
            font.pixelSize: 8
        }

        Text {
            id: directionTxt
            x: 7
            y: 40
            height: 16
            text: direction == 0 ? "Исполнитель" : "Датчик"
            color: direction == 0 ? "Blue" : "Red"
            font.family: "Tahoma"
            font.pixelSize: 10
        }
    }
}
