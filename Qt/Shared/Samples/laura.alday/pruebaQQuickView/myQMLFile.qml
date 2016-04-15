import QtQuick 2.0
import QtQuick.Controls 1.5

Rectangle
{
    id: rectangle1
    anchors.fill: parent
    color: "#fbe748"
    property alias text1: text1
    width: 100
    height: 100
    gradient: Gradient {
        GradientStop {
            position: 0.07;
            color: "#fbe748";
        }
        GradientStop {
            position: 1.00;
            color: "#ffffff";
        }
    }
    Text {
        id: text1
        x: 26
        y: 37
        text: myProperty
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Button {
        id: button1
        x: 12
        y: 69
        text: qsTr("Ok")
        anchors.right: parent.right
        anchors.bottomMargin: 8
        anchors.rightMargin: 14
        anchors.bottom: parent.bottom

        onClicked: {
            myViewerBackEnd.printDebugMsg("clicked");
            var result = myViewerBackEnd.printDebugMsgInvokable("bye")
            print("this is a message printed from qml");
            console.log("Result of printDebugMsgInvokable():", result)
        }
    }


}
