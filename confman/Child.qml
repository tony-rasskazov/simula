import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    Rectangle {
        width: 100
        height: 20
        x: 50
        y: 20 + index * height
        Text {
            anchors.fill: parent
            text: "chld: " + index
        }
    }
}
