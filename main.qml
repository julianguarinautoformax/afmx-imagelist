import QtQuick.Window 2.0
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0


ApplicationWindow {
    visible: true
    width: 640
    height: 800
    title: qsTr("Hello World")
    
    AfmxImageList{
        anchors.fill:parent
        marginFactor: 0.05
    }
    
    
    
}
