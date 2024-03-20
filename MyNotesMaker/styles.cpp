#include "styles.h"

#include <QFile>
#include <QApplication>

Styles* Styles::instance = nullptr;

Styles& Styles::getInstance(QApplication* a)
{
    if (!instance) {
        instance = new Styles();
        QApplication* app = a;
    }
    return *instance;
}


QString Styles::getStyleName()
{
    return style;
}

void Styles::setStyle(QString style_name)
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
