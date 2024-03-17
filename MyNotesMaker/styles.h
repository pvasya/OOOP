#ifndef STYLES_H
#define STYLES_H

#include <QString>

// QSS styles https://github.com/GTRONICK/QSS

class Styles
{
private:
    Styles() = default;
    ~Styles() = default;

    static Styles* instance;
    QString style = "Aqua";

public:
    static Styles& getInstance();

    Styles(const Styles&) = delete;
    Styles& operator=(const Styles&) = delete;

    QString returnStyle();
    QString getStyleName();
    void setStyle(QString);
};

#endif // STYLES_H
