import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Устройства")

    ListModel {
        id: devicesModel

        ListElement {
            name: "GPS трекер"
            title: "Парадная – вход"
            img: "qrc:/res/geo.png"
            direction: 1; //Device.inputDirection; //"source" //Device.outputDirection
            hasChild: true;
        }

        //
        ListElement {
            name: "Датчик движения"
            title: "Парадная – вход"
            img: "qrc:/res/motion.png"
            direction: 1; //"source"  //Device.outputDirection
        }
        ListElement {
            name: "Датчик влажности"
            title: "Комната"
            img: "qrc:/res/humidity.png"
            direction: 1; //"source"  //Device.outputDirection
        }
        ListElement {
            name: "Кондиционер"
            title: "Комната"
            img: "qrc:/res/cond.png"
            direction: 1; //"source"  //Device.outputDirection
        }

        //
        ListElement {
            name: "Датчик температуры"
            title: "Гостинная"
            img: "qrc:/res/temp.png"
            direction: 1; //"source"  //Device.outputDirection
        }
        ListElement {
            name: "GSM"
            title: "МТС 3G"
            img: "qrc:/res/gsm.png"
            direction: 0; //"source"  //Device.outputDirection
        }
        ListElement {
            name: "Котёл"
            title: "Подвал"
            img: "qrc:/res/heater.png"
            direction: 0; //"source"  //Device.outputDirection
        }

        //
        ListElement {
            name: "RFID сканер"
            title: "Парадная – вход"
            img: "qrc:/res/rfid.png"
            direction: 1; //"source"  //Device.outputDirection
        }
        ListElement {
            name: "Сканер отпечатков"
            title: "Парадная – вход"
            img: "qrc:/res/touchscan.png"
            direction: 1; //"source"  //Device.outputDirection
        }

        ListElement {
            name: "Датчик звука"
            title: "Парадная – вход"
            img: "qrc:/res/sound.png"
            direction: 1; //"source"  //Device.outputDirection
        }
        ListElement {
            name: "Замок"
            title: "Парадная – вход"
            img: "qrc:/res/lock.png"
            direction: 0; //"source"  //Device.outputDirection
        }
        ListElement {
            name: "Камера"
            title: "Парадная – вход"
            img: "qrc:/res/cam.png"
            direction: 0; //"source"  //Device.outputDirection
        }
        ListElement {
            name: "Запись звука"
            title: "Парадная – вход"
            img: "qrc:/res/mic.png"
            direction: 1; //"source"  //Device.outputDirection
        }
    }

    ListModel {
        id: modesModel

        ListElement {
            name: "Нормальный";
        }

        ListElement {
            name: "Охрана";
        }

    }

    ListModel {
        id: sourcesModel
        ListElement {
            name: "RFID1";
            descr: "RFID на входе"
        }
        ListElement {
            name: "RFID2";
            descr: "RFID на выходе"
        }
        ListElement {
            name: "SCAN1";
            descr: "Сканер на входе"
        }
        ListElement {
            name: "SCAN2";
            descr: "Сканер на выходе"
        }
    }

    ListModel {
        id: executorsModel

        ListElement {
            name: "DOOR";
            descr: "Дверь"
        }

        ListElement {
            name: "BEEP";
            descr: "Сирена"
        }

        ListElement {
            name: "SMS";
            descr: "Отправка СМС"
        }

        ListElement {
            name: "LOG";
            descr: "Лог"
        }
    }


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Develop { listView.model: devicesModel }

        AllDevices {  allDevicesListView.model: devicesModel  }

        OfficeDevices { }

        HouseDevices { }

        CarDevices { }

        //PageLayout { }

        /*
        Page {

            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }

        Page1 {

        }
        */
    }

    header: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Разработка")
        }

        TabButton {
            text: qsTr("Девайс")
        }

        TabButton {
            text: qsTr("Все устройства")
        }

        TabButton {
            text: qsTr("Офис")
        }

        TabButton {
            text: qsTr("Дом")
        }

        TabButton {
            text: qsTr("Автомобиль")
        }

        TabButton {
            text: qsTr("Фитнес")
        }
    }
}
