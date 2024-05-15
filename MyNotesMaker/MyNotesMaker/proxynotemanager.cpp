#include "proxynotemanager.h"



ProxyNoteManager::ProxyNoteManager() {
    realmanager = new RealNoteManager();
}

ProxyNoteManager::~ProxyNoteManager()
{
    delete realmanager;
}

void ProxyNoteManager::writeLog(const QString &message)
{
    QString filePath = QDir(QApplication::applicationDirPath()).filePath("mynotesmaker.txt");

    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Cannot open log file for writing: " << file.errorString();
        return;
    }

    QTextStream out(&file);
    out << QDateTime::currentDateTime().toString(Qt::ISODate) << " - " << message << "\n";

    file.close();
}


Note ProxyNoteManager::getNote(int i)
{
    return realmanager->getNote(i);
}

int ProxyNoteManager::getLength()
{
    return realmanager->getLength();
}



void ProxyNoteManager::saveNote(QString title, QString text, QString date_time)
{
    realmanager->saveNote(title, text, date_time);
    writeLog("Saved note with title: " + title);
}

void ProxyNoteManager::deleteNote(QString title)
{
    realmanager->deleteNote(title);
    writeLog("Deleted note with title: " + title);
}

void ProxyNoteManager::changeNote(QString title, QString text)
{
    realmanager->changeNote(title, text);
    writeLog("Changed note with title: " + title);
}

Note ProxyNoteManager::getNote(QString title)
{
    Note note = realmanager->getNote(title);
    writeLog("Get note with title: " + note.getTitle());
    return note;
}

void ProxyNoteManager::load()
{
    realmanager->load();
    writeLog("Loaded notes from file");
}

void ProxyNoteManager::save()
{
    realmanager->save();
    writeLog("Saved notes to file");
}

bool ProxyNoteManager::isExist(QString title)
{
    bool exists = realmanager->isExist(title);
    if (exists) {
        writeLog("Note with title '" + title + "' exists");
    } else {
        writeLog("Note with title '" + title + "' does not exist");
    }
    return exists;
}

