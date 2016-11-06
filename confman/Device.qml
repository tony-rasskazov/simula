import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


/*
DeviceForm {

    property int inputDirection: 0
    property int outputDirection: 1
    property int direction: 1 // { inputDirection: inputDirection; outputDirectionr: outputDirection }

    property int cloud: 0
    property int gateway: 1
    property int deviceAt: { cloud: cloud; gateway: gateway }

}
*/

Item {
    property alias _name: _name.text
    property alias _descr: _descr.text
    property alias _img: _img.source
    property int _direction: 0
    property bool _hasChild: false
    property int _childCount: 7

    width: 200
    height: 50 + 20 * _childCount

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
            y: 20
            width: 31
            height: 15
            text: "DEVICE TITLE"
            font.pixelSize: 12
        }

        Image {
            id: _img
            x: 5
            y: 20
            width: 24
            height: 24
            source: "qrc:/res/cam.png"
        }

        Text {
            id: _descr
            x: 32
            y: 35
            width: 31
            height: 15
            color: "#5e5c5c"
            text: "DEV DESCR"
            font.pixelSize: 8
        }

        Text {
            id: directionTxt
            x: 7
            y: 4
            height: 16
            text: _direction == 0 ? "Исполнитель" : "Датчик"
            color: _direction == 0 ? "Blue" : "Red"
            font.family: "Tahoma"
            font.pixelSize: 10
        }

        DeviceChildren {
            y: 45
            listView.model: _childCount
        }
    }
}
