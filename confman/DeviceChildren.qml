import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias listView: listView



    Rectangle {
        height: 20 * listView.count

        //anchors.fill: parent
        ListView {
            id: listView

            anchors.fill: parent

            /*
            delegate: Child {
                //_n11ame: "name"
                //_descr: "title"
                //_img: "res://res/geo.phg"
                //_direction: 0
                //_hasChild: false
            }*/

            delegate: Rectangle {
            //    anchors.fill: parent
                width: 100
                height: 20
                x: 50
                y: 20 + index * height
                Text {
                    anchors.fill: parent
                    text: "chld: " + index + " " + listView.count
                }
            }
        }
    }
}
