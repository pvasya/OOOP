#include "style.h"

#include <QFile>
#include <QApplication>

QString Style::getStyleName()
{
    if(app==nullptr)
        return "standart";

    return styleName;
}

void Style::setStyle(QString styleName)
{
    if(!app)
        qInfo()<<"set application";
    else{
        QFile styleSheetFile(":/styles/styles/" + styleName + ".qss");

        if (!styleSheetFile.open(QFile::ReadOnly)) {
            qWarning() << "Error opening " << styleName;
            styleName = "Aqua";
            styleSheetFile.setFileName(":/styles/styles/Aqua.qss");
            if (!styleSheetFile.open(QFile::ReadOnly)) {
                qWarning() << "Style 'Aqua' not found!";
                return;
            }
        }

        QString styleSheet = QLatin1String(styleSheetFile.readAll());

        app->setStyleSheet(styleSheet);
    }
}

void Style::setApplication(QApplication *a)
{
    app = a;
}

