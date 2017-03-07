#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "afmximagelistjson.h"


void registerAfmxImageList(){
    
    qmlRegisterType<AfmxImageListJson>("com.afmx.imagelist",1,0,"AfmxImageListViewController");
}


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    
    registerAfmxImageList();
    
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    return app.exec();
}
