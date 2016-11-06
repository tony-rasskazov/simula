import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias button1: button1
    property alias button2: button2
    property alias slider1: slider1
    property alias spinBox1: spinBox1
    property alias spinBox2: spinBox2
    property alias switch1: switch1
    property alias textInput1: textInput1

    RowLayout {
        anchors.verticalCenterOffset: 22
        anchors.horizontalCenterOffset: -2
        anchors.centerIn: parent

        Button {
            id: button1
            text: qsTr("Press Me 1")
        }

        Button {
            id: button2
            text: qsTr("Press Me 2")
        }
    }

    ProgressBar {
        id: progressBar1
        x: 220
        y: 310
        value: 0.5
    }

    Slider {
        id: slider1
        x: 211
        y: 31
        value: 0.5
    }

    SpinBox {
        id: spinBox1
        x: 250
        y: 102
    }

    TextInput {
        id: textInput1
        x: 196
        y: 205
        width: 243
        height: 20
        text: qsTr("Input text value here")
        font.pixelSize: 12
    }

    Switch {
        id: switch1
        x: 260
        y: 148
        text: qsTr("Switch")
        checked: true
    }

    SpinBox {
        id: spinBox2
        x: 211
        y: 345
    }
}
