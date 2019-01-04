#include "regexchecker.h"

RegExChecker::RegExChecker(QList<QStringList> list): listToCheck(list)
{
}

QStringList RegExChecker::check()
{
    QRegExp numberInWord("[a-z]*\\d+[a-z]*");
    QRegExp capsInWord("[a-zA-Z]{1,1}[a-z]*[A-Z]+[a-z]*");
    QRegExp symbolInWord("[a-z]*(\\W[^\\n]|@)+[a-z]*");
    QRegExp otherInWord("[a-z]*[@*<#]+[a-z]*");

    QString errorLine;
    QStringList listOfErrors;

    for (int line=0; line<listToCheck.size(); line++)
    {
        for (int word=0; word<listToCheck.at(line).size(); word++)
        {
            QString currentWord = listToCheck.at(line).at(word);
            if (numberInWord.exactMatch(currentWord) || capsInWord.exactMatch(currentWord)
                    || symbolInWord.exactMatch(currentWord) || otherInWord.exactMatch(currentWord))
            {
                errorLine.clear();
                errorLine += "Line " + QString::number(line+1) + ", word " + QString::number(word+1) + ": " + currentWord;
                listOfErrors.append(errorLine);
            }
        }
    }

    return listOfErrors;
}
