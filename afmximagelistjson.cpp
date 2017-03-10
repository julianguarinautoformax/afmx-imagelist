#include "afmximagelistjson.h"

#include <QUrl>
#include <QList>
#include <QImage>
#include <QDebug>
#include <QDateTime>
#include <QFileInfoList>
#include <QRegularExpression>


AfmxImageListJson::AfmxImageListJson(QObject * parent):QObject(parent)
{
	qInfo()<<"<-Autoformax Image List View Controller->";
	
	afmxImgListMap = { };
	afmxNameFilters << "*.png";
	m_valid = false;
    
    
    
    
    
}
void AfmxImageListJson::updateImageList(){
	
	QFileInfoList fil = afmxImgDirPath.entryInfoList();
	QFileInfoList::const_iterator fil_it;
	QVariantList li;
	for (fil_it=fil.begin();fil_it!=fil.end();++fil_it){
		
		QFileInfo fi = *fil_it;
		if (fi.isDir())continue;
		QImage afmx_img = QImage(fi.absoluteFilePath());
		qint64 afmx_img_cache =	afmx_img.cacheKey();
		qInfo()<<afmx_img_cache;
		QString afmx_img_created = fi.created().toString("t-yyyyMMM-ddHHmmsszzz");
		QVariantMap fi_m {
			{
				{"afmx_img_basename_cache",fi.baseName()+ "_0x"+QString::number(afmx_img_cache,16)},
                {"afmx_img_basename",fi.baseName()},
                {"afmx_img_suffix",fi.suffix()},
                {"afmx_img_abspath",fi.absoluteFilePath()},
                {"afmx_img_basename_created",fi.baseName()+ "_"+afmx_img_created}
				
			}
		};
		li << fi_m;
		
		
		QList<QString>::const_iterator fi_m_keys_it;
		QList<QString> fi_m_keys = fi_m.keys();
		qInfo()<<fi_m["afmx_img_basename"]<<":{";
		qInfo()<<"IMGCACHE:"<<fi_m["afmx_img_basename_cache"];
		qInfo()<<"BASENAME:"<<fi_m["afmx_img_basename"];
		qInfo()<<"  SUFFIX:"<<fi_m["afmx_img_suffix"];
		qInfo()<<" ABSPATH:"<<fi_m["afmx_img_abspath"];
		qInfo()<<" CREATED:"<<fi_m["afmx_img_basename_created"];
			
		qInfo()<<"}";
	}
	afmxImgListMap["listMap"] = li;
	
	
}

void AfmxImageListJson::setfilters(QStringList namefilters){
	
	if (namefilters==afmxNameFilters || m_valid == false){
		return;
	}
	
	afmxNameFilters = namefilters;
	afmxImgDirPath.setNameFilters(afmxNameFilters);
	updateImageList();
	emit afmxImgListViewUpdated();
	
	
}

void AfmxImageListJson::setdirpath(QString & directoryPath){
    
    QRegularExpression rE("^(file:\/{2})|(qrc:\/{2})|(http:\/{2})");
	QUrl afmxImgDirPathUrl = QUrl::fromLocalFile(directoryPath.remove(rE));
	qInfo()<<"QUrl::path():"<<afmxImgDirPathUrl.path();
	afmxImgDirPath = QDir(afmxImgDirPathUrl.path());
	if (afmxImgDirPath.exists()){
                
		qInfo()<<"Directory Path changed:"<<directoryPath;
        setvalid(true);
		updateImageList();
        
    }else {
        
        qCritical()<<"Directory Path "<<directoryPath<<" does not exist";
        setvalid(false);
        
    }
	emit afmxImgListViewUpdated();
    
}
