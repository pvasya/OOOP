#ifndef STYLE_H
#define STYLE_H

#include <QApplication>
#include <QString>

// QSS styles https://github.com/GTRONICK/QSS

class Style
{
private:
    Style() = default;
    ~Style() = default;
    
    static Style* instance;
    QString style = "Aqua";
    QApplication* app;

public:
    static Style& getInstance(QApplication* a);
    
    Style(const Style&) = delete;
    Style& operator=(const Style&) = delete;

    QString getStyleName();
    void setStyle(QString);
};

#endif // STYLE_H
