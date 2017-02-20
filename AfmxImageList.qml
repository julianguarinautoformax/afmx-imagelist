import QtQuick 2.0

Item {
    id: afmxImageList 
    property real marginFactor:0.01
    
    property var listModelJsonString : '[]'
    
    property bool testPath: false


    Rectangle {
        
        
        id:container
        anchors.margins: parent.width*marginFactor
        anchors.fill:parent
        border.color:"red"
        
        Item {
            id:accordionContainer
            property int maxrows:4
            
            
            anchors.fill:parent
            GridView{
                id:accordionView
                clip:true
                anchors.fill:parent
                cellHeight: parent.height/accordionContainer.maxrows
                cellWidth: cellHeight

                flow: GridView.FlowTopToBottom
                layoutDirection: Qt.RightToLeft
                verticalLayoutDirection: GridView.BottomToTop

                model:accordionModel
                delegate: accordionDelegate
                
            }
            ListModel{
                id:accordionModel

                
            }
            
            
            Component{
                id:accordionDelegate
                Rectangle{
                    //width:accordionContainer.width
                    //height:accordionContainer.height/accordionContainer.maxrows < accordionContainer.height/accordionModel.count ? accordionContainer.height/accordionContainer.maxrows : accordionContainer.height/accordionModel.count
                    width:accordionView.cellWidth
                    height:accordionView.cellHeight
                    border.color: "green"
                    Text {
                        //anchors.fill:parent
                        anchors.centerIn: parent
                        text:image                        
                    }
                }
            }
        }
        Component.onCompleted: {
            if (testPath == true){
                console.log("Test Path Enabled")
                var index = 0
                var limit =  Math.floor((Math.random() * 10) + 1)
                limit = 100
                for (index = 0; index < limit; index ++ ){
                    // This is available in all editors.
                    accordionModel.append({"image":index})
                }

            }


        }        
        
    }
    
    
    
}
