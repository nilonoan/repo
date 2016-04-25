import QtQuick 2.4
import QtQuick.Controls 1.3
import People 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Window {
        id: window1
        persona: Person {
            id: person1
            name: "Lazaro"
            objectName: "persona"
        }
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Label {
        id: label1
        text: qsTr(person1.name) + qsTr(" (value taken from same qml file)")
        anchors.centerIn: parent
        objectName: "label"
    }

    Button {
        id: button1
        text: qsTr("Change label")
        anchors.top: parent
        objectName: "button"
        onClicked: {
            label1.text = qsTr("Pedro (changed from qml file)")
        }
    }
}
