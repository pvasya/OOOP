#include "style.h"

#include <QFile>
#include <QApplication>

Style* Style::instance = nullptr;

Style& Style::getInstance(QApplication* a)
{
    if (!instance) {
        instance = new Style();
        QApplication* app = a;
    }
    return *instance;
}


QString Style::getStyleName()
{
    return style;
}

void Style::setStyle(QString style_name)
{   
    QFile styleSheetFile(":/styles/styles/" + style_name + ".qss");

    if (!styleSheetFile.open(QFile::ReadOnly)) {
        qDebug()<<"Error opening "<<style;
        style = "Aqua";
        styleSheetFile.setFileName(":/styles/styles/Aqua.qss");
        styleSheetFile.open(QFile::ReadOnly);
    }
    else {
        style = style_name;
    }

    QString styleSheet = QLatin1String(styleSheetFile.readAll());

    app->setStyleSheet(styleSheet);
}
