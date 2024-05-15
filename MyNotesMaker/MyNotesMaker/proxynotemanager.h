#ifndef PROXYNOTEMANAGER_H
#define PROXYNOTEMANAGER_H

#include "notemanager.h"
#include "realnotemanager.h"

/*!
     * \brief Патерн Proxy. Керує нотатками в пам'яті програми
     */
class ProxyNoteManager : public NoteManager
{
private:
    RealNoteManager* realmanager;

    void writeLog(const QString &message);


public:
    ProxyNoteManager();
    ~ProxyNoteManager();

    void saveNote(QString title, QString text, QString date_time) override;
    void deleteNote(QString title) override;
    void changeNote(QString title, QString text) override;
    Note getNote(QString title) override;
    void load() override;
    void save() override;
    bool isExist(QString title) override;
    Note getNote(int i) override;
    int getLength() override;
};

#endif // PROXYNOTEMANAGER_H
