#ifndef READFILE_H
#define READFILE_H

#include <QList>
#include <QStringList>

class ReadFile
{
public:
    ReadFile();
    QList<QStringList> readFile(QWidget *parent);
};

#endif // READFILE_H
