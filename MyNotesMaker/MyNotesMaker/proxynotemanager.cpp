#include "proxynotemanager.h"



ProxyNoteManager::ProxyNoteManager() {
    realmanager = new RealNoteManager();
}

ProxyNoteManager::~ProxyNoteManager()
{
    delete realmanager;
}

QPair<QString, QString> ProxyNoteManager::getNoteTitleDate(int i)
{
    return realmanager->getNoteTitleDate(i);
}

void ProxyNoteManager::writeLog(const QString &message)
{
    QString filePath = QDir(QApplication::applicationDirPath()).filePath("mynotesmaker.txt");

    if (!QFile::exists(filePath)) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Cannot create log file: " << file.errorString();
            return;
        }
        file.close();
    }

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

int ProxyNoteManager::getLenght()
{
    return realmanager->getLenght();
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

QPair<QString, QString> ProxyNoteManager::getNote(QString title)
{
    QPair<QString, QString> note = realmanager->getNote(title);
    writeLog("Get note with title: " + title);
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

