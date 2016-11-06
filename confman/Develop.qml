import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


/*
DevelopForm {

}
*/
Item {

    property alias listView: listView

    property int inputDirection: 0
    property int outputDirection: 1

    //property int direction: 0; //{ inputDirection: inputDirection; outputDirectionr: outputDirection }
    //property alias direction: Device.direction; //{ inputDirection: inputDirection; outputDirectionr: outputDirection }

    ListView {
        id: listView

        anchors.fill: parent

        delegate: Device {
            _name: name
            _descr: title
            _img: img
            _direction: direction
            _hasChild: hasChild
        }
    }

}
