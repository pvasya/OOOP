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

/*!
     * \brief Патерн Proxy. Керує нотатками в пам'яті програми
     */
class RealNoteManager : public NoteManager
{
public:
    RealNoteManager();
    ~RealNoteManager();

    void saveNote(QString title, QString text, QString date_time) override;
    void deleteNote(QString title) override;
    void changeNote(QString title, QString text) override;
    Note getNote(QString title) override;
    void load() override;
    void save() override;
    bool isExist(QString title) override;
    Note getNote(int i) override;
    int getLength() override;

private:
    QList<Note>* list;
};

#endif // REALNOTEMANAGER_H
