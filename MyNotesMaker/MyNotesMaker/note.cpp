#include "note.h"

Note::Note(QString title, QString text, QString date_time) {
    this->title = title;
    this->text = text;
    this->date_time = date_time;
}

void Note::setTitle(QString name)
{
    this->title = name;
}

void Note::setText(QString text)
{
    this->text = text;
}

void Note::setDateTime(QString date_time)
{
    this->date_time = date_time;
}

QString Note::getTitle() const
{
    return title;
}

QString Note::getText() const
{
    return text;
}

QString Note::getDateTime() const
{
    return date_time;
}
