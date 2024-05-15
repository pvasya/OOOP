#ifndef STYLE_H
#define STYLE_H

#include <QApplication>
#include <QString>

// QSS styles https://github.com/GTRONICK/QSS


/*!
 * \brief The Style class for changing the application's styles.
 */
class Style
{
protected:
    Style() {}

private:
    QString styleName; /**< The name of the style. */
    QApplication* app; /**< Pointer to the application object. */


public:
    static Style& get(){
        static Style style;
        return style;
    }
    Style(Style const&) = delete;
    Style(Style&&) = delete;
    Style& operator=(Style const&) = delete;
    Style& operator=(Style &&) = delete;

    /**
     * @brief Gets the name of the current style.
     */
    QString getStyleName();
    /**
     * @brief Sets the style of the application.
     * @param styleName The name of the style to set.
     */
    void setStyleName(QString styleName);

    void setApplication(QApplication* a);
};

#endif // STYLE_H
