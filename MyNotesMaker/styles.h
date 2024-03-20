#ifndef STYLES_H
#define STYLES_H

#include <QApplication>
#include <QString>

// QSS styles https://github.com/GTRONICK/QSS

class Styles
{
private:
    Styles() = default;
    ~Styles() = default;

    static Styles* instance;
    QString style = "Aqua";
    QApplication* app;

public:
    static Styles& getInstance(QApplication* a);

    Styles(const Styles&) = delete;
    Styles& operator=(const Styles&) = delete;

    QString getStyleName();
    void setStyle(QString);
};

#endif // STYLES_H
