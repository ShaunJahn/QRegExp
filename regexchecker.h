#ifndef REGEXCHECKER_H
#define REGEXCHECKER_H

#include <QStringList>

class RegExChecker
{
public:
    RegExChecker(QList<QStringList> list);
    QStringList check();
private:
    QList<QStringList> listToCheck;
};

#endif // REGEXCHECKER_H
