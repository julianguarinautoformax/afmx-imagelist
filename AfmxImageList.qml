import QtQuick 2.0

Item {
    id: afmxImageList 
    property real marginFactor:0.01
    
    property var listModelJsonString : '[{"image":"img0.png"},{"image":"im1.png"}]'
    
    
    Rectangle {
        
        
        id:container
        anchors.margins: parent.width*marginFactor
        anchors.fill:parent
        border.color:"red"
        
        Item {
            id:accordionContainer
            property int maxrows:10
            
            
            anchors.fill:parent
            ListView{
                id:accordionView
                anchors.fill:parent
                
                model:accordionModel
                delegate: accordionDelegate
                
            }
            ListModel{
                id:accordionModel
                
            }
            
            
            Component{
                id:accordionDelegate
                Rectangle{
                    width:accordionContainer.width
                    height:accordionContainer.height/accordionContainer.maxrows < accordionContainer.height/accordionModel.count ? accordionContainer.height/accordionContainer.maxrows : accordionContainer.height/accordionModel.count 
                    border.color: "green"
                    Text {
                        anchors.fill:parent
                        text:image                        
                    }
                }
            }
        }
        Component.onCompleted: {
            console.log(listModelJsonString)
            var listModelJson = JSON.parse(listModelJsonString)
            console.log(listModelJson)
            console.log(listModelJson[0])
            console.log(listModelJson[0]["image"])
            
            
            
        }        
        
    }
    
    
    
}
