import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


Item {
    width: 400
    height: 400
    property alias listView: listView

    ListView {
        id: listView

        anchors.fill: parent

        delegate: Device {
            _name: name
            _descr: title
            _img: img
        }
    }
}
