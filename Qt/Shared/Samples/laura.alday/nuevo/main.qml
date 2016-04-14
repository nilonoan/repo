import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.0

Window {
    width: 300
    height: 300
    visible: true


    Text {
        id: elTexto
        text: myProperty

        anchors.centerIn: parent


    }
    Button {
        x: 38
        y: 67
        text: "Click me"
        onClicked: {
            myMessages.myProperty = "seteado en qml";
            elTexto.text = myProperty;
            var result = myMessages.postMessage("Hello from QML")
            console.log("Result of postMessage():", result)
            myMessages.refresh();

        }
    }



}
