import QtQuick 2.4

Item {
    width: 400
    height: 400
    property alias pageLayoutForm1: pageLayoutForm1

    PageLayoutForm {
        id: pageLayoutForm1
        anchors.fill: parent
    }
}
