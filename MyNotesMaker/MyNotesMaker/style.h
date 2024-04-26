#ifndef STYLE_H
#define STYLE_H

#include <QApplication>
#include <QString>

// QSS styles https://github.com/GTRONICK/QSS


/*!
     * \brief Зміна стилів редактора нотаток
     */
class Style
{
protected:
    Style() {}

private:
    QString styleName;
    QApplication* app;

public:
    static Style& get(){
        static Style style;
        return style;
    }
    Style(Style const&) = delete;
    Style(Style&&) = delete;
    Style& operator=(Style const&) = delete;
    Style& operator=(Style &&) = delete;

    QString getStyleName();
    void setStyle(QString styleName);

    void setApplication(QApplication* a);
};

#endif // STYLE_H
