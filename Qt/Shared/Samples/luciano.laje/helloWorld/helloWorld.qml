import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        id: helloLaje
        text: qsTr("Hello Laje!")
        font.pointSize: 11
        font.strikeout: false
        font.underline: false
        font.italic: false
        font.bold: true
        anchors.centerIn: parent
    }
}
