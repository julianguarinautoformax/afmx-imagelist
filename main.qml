import QtQuick.Window 2.0
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    
    visible: true
    width: 640
    height: 800
    title: qsTr("Hello World")
    
    AfmxImageList{
        id:afmxImageList
        anchors.fill:parent
        marginFactor: 0.02
    }
    
    Rectangle{
        id:pathSelector
        anchors.fill: parent
        Text{
            anchors.centerIn: parent
            text:"Touch Me!"
            
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                root.state = "Select"
            }
        }
    }
    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        selectFolder: true
        onAccepted: {
            console.log("You chose: " + Qt.resolvedUrl(fileDialog.folder))
            afmxImageList.folderPath = fileDialog.folder
            root.state = "Selected"
            
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
        
    }
    Item {
        id:root
        states: [
            State {
                name: "Select"
                PropertyChanges {target: fileDialog; visible: true}
            },
            State {
                name: "Start"
                PropertyChanges {target: pathSelector; visible:true}
            },
            State {
                name: "Selected"
                PropertyChanges {target: pathSelector; visible: false}
            }

        ]
    }
}
