#ifndef LOADER_H
#define LOADER_H

#include <QObject>
#include <QXmlStreamReader>
#include <QString>
#include <QDebug>
#include <QFile>
#include <exception>
#include <iostream>

class XMLLoader : public QObject
{
    Q_OBJECT

private:
    QXmlStreamReader parser;
    QString m_filename;
    QFile m_file;

public:
    explicit XMLLoader(QObject * parent = nullptr);
    virtual ~XMLLoader();
    XMLLoader(const QString & filename, QObject * parent = nullptr);
    void setFile(const QString & filename);
    void parse();
};

#endif // LOADER_H
