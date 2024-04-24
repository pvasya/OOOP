#ifndef PROXYNOTEMANAGER_H
#define PROXYNOTEMANAGER_H

#include "notemanager.h"
#include "realnotemanager.h"

class ProxyNoteManager : public NoteManager
{
private:
    RealNoteManager* realmanager;


public:
    ProxyNoteManager();
    ~ProxyNoteManager();

    void saveNote(QString title, QString text, QString date_time) override;
    void deleteNote(QString title) override;
    void changeNote(QString title, QString text) override;
    QPair<QString, QString> getNote(QString title) override;
    void load() override;
    void save() override;
    QPair<QString, QString> getNoteTitleDate(int i);
    bool isExist(QString title) override;
    void writeLog(const QString &message);
    Note getNote(int i) override;
    int getLenght() override;
};

#endif // PROXYNOTEMANAGER_H
