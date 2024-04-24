#ifndef NOTE_H
#define NOTE_H

#include <QApplication>

class Note
{
private:
    QString title;
    QString text;
    QString date_time;

public:
    Note(QString title,QString text, QString date_time);

    void setTitle(QString title);
    void setText(QString text);
    void setDateTime(QString date_time);

    QString getTitle() const;
    QString getText() const;
    QString getDateTime() const;
};

#endif // NOTE_H
