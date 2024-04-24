#ifndef REALNOTEMANAGER_H
#define REALNOTEMANAGER_H

#include "notemanager.h"
#include "note.h"

#include <QList>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDir>

class RealNoteManager : public NoteManager
{
public:
    RealNoteManager();
    ~RealNoteManager();

    void saveNote(QString title, QString text, QString date_time) override;
    void deleteNote(QString title) override;
    void changeNote(QString title, QString text) override;
    QPair<QString, QString> getNote(QString title) override;
    void load() override;
    void save() override;
    QPair<QString, QString> getNoteTitleDate(int i);
    bool isExist(QString title) override;
    Note getNote(int i) override;
    int getLenght() override;

private:
    QList<Note>* list;
};

#endif // REALNOTEMANAGER_H