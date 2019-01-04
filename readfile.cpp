#include "readfile.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

ReadFile::ReadFile()
{
}

QList<QStringList> ReadFile::readFile(QWidget *parent)
{
    QList<QStringList> contents;
    QString fileName = QFileDialog::getOpenFileName(parent, "Open file", ".", "Text files (*.txt)");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(parent, "File error", "Could not open file " + fileName, QMessageBox::Ok);
        return QList<QStringList>();
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList splitLine = line.split(" ");
        contents << splitLine;
    }
    file.close();
    return contents;
}
