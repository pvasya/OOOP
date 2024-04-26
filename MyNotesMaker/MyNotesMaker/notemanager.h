#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QApplication>
#include "note.h"
/*!
     * \brief Патерн Proxy. Керує нотатками в пам'яті програми
     */
class NoteManager
{
public:
    virtual void saveNote(QString title, QString text, QString date_time) = 0;
    virtual void deleteNote(QString title) = 0;
    virtual Note getNote(int i) = 0;
    virtual QPair<QString, QString> getNoteTitleDate(int i) = 0;
    virtual int getLenght() = 0;
    virtual void changeNote(QString title, QString text) = 0;
    virtual QPair<QString, QString> getNote(QString title) = 0;
    virtual void load() = 0;
    virtual void save() = 0;
    virtual bool isExist(QString title) = 0;
};

#endif // NOTEMANAGER_H
