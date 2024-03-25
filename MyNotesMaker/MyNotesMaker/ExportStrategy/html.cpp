#include "html.h"
#include <QFile>
#include <QTextStream>

void Html::doExport(bool& flag,QString file, QString text)
{
    QFile outputFile(file);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        flag = false;
        return;
    }
    else{
        QTextStream outputStream(&outputFile);
        outputStream << text;

        outputFile.close();

        flag = true;
    }
}
