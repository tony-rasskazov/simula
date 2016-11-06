import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    id: item1
    property alias allDevicesListView: allDevicesListView

    Row {
        id: row3
        height: 400
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        Column {
            id: column1
            height: 192
            anchors.left: parent.left
            anchors.leftMargin: 0

            Row {
                id: row1
                spacing: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0

                Column {
                    id: column3
                    spacing: 4

                    Row {
                        id: row2
                        width: 200
                        height: 20
                        spacing: 3

                        Column {
                            id: column7
                            width: 200
                            height: 20
                            spacing: 3

                            Text {
                                id: text3
                                text: qsTr("Датчики")
                                anchors.left: parent.left
                                anchors.leftMargin: 3
                                font.pixelSize: 12
                            }
                        }
                    }

                    Row {
                        id: row6
                        width: 200
                        height: 40

                        Column {
                            id: column4
                            width: 200
                            height: 400
                            spacing: 3

                            ListView {
                                id: allDevicesListView
                                anchors.fill: parent
                                model: ListModel {
                                    ListElement {
                                        name: "Grey"
                                        colorCode: "grey"
                                    }

                                    ListElement {
                                        name: "Red"
                                        colorCode: "red"
                                    }

                                    ListElement {
                                        name: "Blue"
                                        colorCode: "blue"
                                    }

                                    ListElement {
                                        name: "Green"
                                        colorCode: "green"
                                    }
                                }
                                delegate: Item {
                                    x: 5
                                    width: 80
                                    height: 40
                                    Row {
                                        id: row4
                                        spacing: 10
                                        Rectangle {
                                            width: 40
                                            height: 40
                                            color: colorCode
                                        }

                                        Text {
                                            text: name
                                            anchors.verticalCenter: parent.verticalCenter
                                            font.bold: true
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }


        }

        Column {
            id: column5
            height: 192
            anchors.right: parent.right
            anchors.rightMargin: 0
            Row {
                id: row10
                anchors.leftMargin: 0
                anchors.right: parent.right
                Column {
                    id: column6
                    Row {
                        id: row7
                        width: 200
                        height: 20

                        Column {
                            id: column8
                            width: 200
                            height: 400

                            Text {
                                id: text5
                                text: qsTr("Устройства")
                                anchors.left: parent.left
                                anchors.leftMargin: 3
                                font.pixelSize: 12
                            }
                        }
                    }

                    Row {
                        id: row8
                        width: 200
                        height: 40
                        Column {
                            id: column2
                            width: 200
                            height: 400
                            spacing: 3

                            Button {
                                id: button19
                                text: qsTr("Замок")
                                anchors.right: parent.right
                                anchors.rightMargin: 3
                                anchors.left: parent.left
                                anchors.leftMargin: 3
                                checkable: false
                            }

                            Button {
                                id: button20
                                text: qsTr("Замок")
                                anchors.leftMargin: 3
                                anchors.right: parent.right
                                checkable: false
                                anchors.left: parent.left
                                anchors.rightMargin: 3
                            }

                            Button {
                                id: button21
                                text: qsTr("Замок")
                                anchors.leftMargin: 3
                                anchors.right: parent.right
                                checkable: false
                                anchors.left: parent.left
                                anchors.rightMargin: 3
                            }

                            Button {
                                id: button22
                                text: qsTr("Замок")
                                anchors.leftMargin: 3
                                anchors.right: parent.right
                                checkable: false
                                anchors.left: parent.left
                                anchors.rightMargin: 3
                            }

                            Button {
                                id: button23
                                text: qsTr("Замок")
                                anchors.leftMargin: 3
                                anchors.right: parent.right
                                checkable: false
                                anchors.left: parent.left
                                anchors.rightMargin: 3
                            }

                            Button {
                                id: button24
                                text: qsTr("Замок")
                                anchors.leftMargin: 3
                                anchors.right: parent.right
                                checkable: false
                                anchors.left: parent.left
                                anchors.rightMargin: 3
                            }

                            Button {
                                id: button25
                                text: qsTr("Замок")
                                anchors.leftMargin: 3
                                anchors.right: parent.right
                                checkable: false
                                anchors.left: parent.left
                                anchors.rightMargin: 3
                            }


                        }

                    }
                    spacing: 4
                }
                spacing: 0
                anchors.left: parent.left
                anchors.rightMargin: 0
            }
        }

    }


}
