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
    std::initializer_list<QString> filters;
    
    
    Q_PROPERTY(QString filters READ filters WRITE setfilters NOTIFY filterschanged)
    Q_PROPERTY(QString dirpath READ dirpath WRITE setdirpath NOTIFY dirpathchanged)
    
public:
    AfmxImageListJson(QObject * parent = 0);
        
    
    QString dirpath() const{
        return afmxImgDirPath.absolutePath();
    }
    
    void setdirpath(QString & directoryPath);
    
    
    //bool isValid(){ return m_valid; }
       
    
    
};

#endif // AFMXIMAGELISTJSON_H
