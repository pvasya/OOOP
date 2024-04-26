#include "style.h"

#include <QFile>
#include <QApplication>

QString Style::getStyleName()
{
    if(app==nullptr)
        styleName = "Aqua";

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
            this->styleName = "Aqua";
            return;
        }

        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        this->styleName = styleName;
        app->setStyleSheet(styleSheet);
    }
}

void Style::setApplication(QApplication *a)
{
    app = a;
}

