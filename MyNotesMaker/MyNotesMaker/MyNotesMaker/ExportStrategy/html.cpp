#include "html.h"
#include <QFile>
#include <QTextStream>

bool Html::doExport(QString file, QString text)
{
    QFile outputFile(file);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    else{
        QTextStream outputStream(&outputFile);
        outputStream << text;

        outputFile.close();

        return true;
    }
}
