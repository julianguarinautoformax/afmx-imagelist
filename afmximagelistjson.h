#ifndef AFMXIMAGELISTJSON_H
#define AFMXIMAGELISTJSON_H

#include <QDir>
#include <QObject>
#include <QJsonObject>

class AfmxImageListJson :public QObject
{
    Q_OBJECT
    bool m_valid;
    QJsonObject afmxImgListJson;
    QDir afmxImgDirPath;
    
public:
    AfmxImageListJson(QObject * parent = 0);
    AfmxImageListJson(QString & directoryPath, std::initializer_list<QString> filterNames = {"*.png"}, QObject * parent = 0);
        
    
    
    
    
    bool isValid(){ return m_valid; }
       
    
    
};

#endif // AFMXIMAGELISTJSON_H
