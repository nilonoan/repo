import QtQuick 2.4
import QtQuick.Controls 1.3
import com.mycompany.qmlcomponents 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Image Plugin")

    Label {
        text: qsTr("Image Plugin")
        anchors.left: parent.left
        anchors.leftMargin: 300
        anchors.top: sarasa.top
        anchors.topMargin: 300
        transformOrigin: Item.Center

    }


    MyItem {
        id: sarasa
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
	//replace this path with the path to any image
        imageLocation: "C:\\Users\\laura.e.lucas.alday\\Documents\\testPlugins\\MyUtilities\\img\\flor.jpg"
    }



}
