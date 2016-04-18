import QtQuick 2.4
import QtQuick.Window 2.2
//import MyLibr 1.0 //esto no funciono, reconocia el "MyData.name" pero no lo leia desde la libreria

Window {
    visible: true

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        text: mylib.name //myData.name no funciono
        anchors.centerIn: parent
    }
}
