#include "styles.h"

#include <QFile>
#include <QApplication>

Styles* Styles::instance = nullptr;

Styles& Styles::getInstance()
{
    if (!instance) {
        instance = new Styles();
    }
    return *instance;
}

QString Styles::returnStyle()
{
    QFile styleSheetFile(":/styles/styles/" + style + ".qss");

    if (!styleSheetFile.open(QFile::ReadOnly)) {
        qDebug()<<"Error opening "<<style;
        styleSheetFile.setFileName(":/styles/styles/Aqua.qss");
        styleSheetFile.open(QFile::ReadOnly);
    }

    QString styleSheet = QLatin1String(styleSheetFile.readAll());

    return styleSheet;
}



QString Styles::getStyleName()
{
    return style;
}

void Styles::setStyle(QString style_name)
{
    QFile styleSheetFile(":/styles/styles/" + style_name + ".qss");

    if (!styleSheetFile.open(QFile::ReadOnly)) {
        qDebug()<<"Error opening "<<style_name;
        style = "Aqua";
    }
    else{
        style = style_name;
    }
}
