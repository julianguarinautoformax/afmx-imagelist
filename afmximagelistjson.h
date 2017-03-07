#ifndef AFMXIMAGELISTJSON_H
#define AFMXIMAGELISTJSON_H

#include <QDir>
#include <QObject>
#include <QVariantMap>


class AfmxImageListJson :public QObject
{
    Q_OBJECT
    bool m_valid;
    QVariantMap afmxImgListMap;
    QDir afmxImgDirPath;
    QStringList afmxNameFilters;
    
    
    Q_PROPERTY(QStringList filters READ filters WRITE setfilters)
    Q_PROPERTY(QString dirpath READ dirpath WRITE setdirpath)
	Q_PROPERTY(bool valid READ valid WRITE setvalid)
	
	
	void updateImageList();
public:
    AfmxImageListJson(QObject * parent = 0);
        
    
	QStringList filters() const{ return afmxNameFilters;}
	void  setfilters(QStringList namefilters); 
	
    QString dirpath() const{return afmxImgDirPath.absolutePath();}
	void setdirpath(QString & directoryPath);
    
    
    bool valid(){ return m_valid; }
	void setvalid(bool value){m_valid = value;}
	
signals:
	void afmxImgListViewUpdated();    
};

#endif // AFMXIMAGELISTJSON_H
