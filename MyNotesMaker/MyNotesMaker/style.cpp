#include "style.h"

#include <QFile>
#include <QApplication>

Style* Style::instance = nullptr;

Style& Style::getInstance(QApplication* a)
{
    if (!instance) {
        instance = new Style();
        instance->style = "Aqua";
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
        qDebug() << "Error opening " << style_name;
        style_name = "Aqua";
        styleSheetFile.setFileName(":/styles/styles/Aqua.qss");
        if (!styleSheetFile.open(QFile::ReadOnly)) {
            qDebug() << "Style 'Aqua' not found!";
            return;
        }
    }

    QString styleSheet = QLatin1String(styleSheetFile.readAll());

    app->setStyleSheet(styleSheet);
}

