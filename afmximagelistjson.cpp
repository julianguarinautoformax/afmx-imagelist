#include "afmximagelistjson.h"

#include <QImage>
#include <QDebug>
#include <QDateTime>
#include <QJsonValue>
#include <QFileInfoList>
AfmxImageListJson::AfmxImageListJson()
{
    
    
    
    
    
}
AfmxImageListJson::AfmxImageListJson(QString & directoryPath, std::initializer_list<QString> filterNames){
    
    
    afmxImgDirPath = QDir(directoryPath);
    afmxImgListJson = { };
    
    if (afmxImgDirPath.exists()){
        /* The directory exists, get png list.*/
        QStringList fltrs(filterNames);
        afmxImgDirPath.setNameFilters(fltrs);
        
        
        QFileInfoList fil = afmxImgDirPath.entryInfoList();
        QFileInfoList::const_iterator fil_it;
        
        for (fil_it = fil.begin();fil_it!=fil.end();++fil_it){
            
            QFileInfo fi = *fil_it;
            
            QImage afmx_img = QImage(fi.absoluteFilePath());
            qint64 afmx_img_cache = afmx_img.cacheKey();
            QString afmx_img_created = fi.created().toString("t-yyyyMMM-ddHHmmsszzz");
            
            QJsonObject fi_j {
                {"afmx_img_basename_cache",QJsonValue(fi.baseName()+ "_0x"+QString::number(afmx_img_cache,16))},
                {"afmx_img_basename",QJsonValue(fi.baseName())},
                {"afmx_img_suffix",QJsonValue(fi.suffix())},
                {"afmx_img_abspath",QJsonValue(fi.absoluteFilePath())},
                {"afmx_img_basename_created",QJsonValue(fi.baseName()+ "_"+afmx_img_created)}
            };
            
            
            
        }
        
        m_valid = true;
        
    }else {
        
        qCritical()<<"Directory Path "<<directoryPath<<" does not exist";
        m_valid = false;
        
        
    }
    
    
    
    
    
}
