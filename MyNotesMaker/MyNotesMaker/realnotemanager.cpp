#include "realnotemanager.h"

RealNoteManager::RealNoteManager() {
    list = new QList<Note>;
}

RealNoteManager::~RealNoteManager()
{
    delete list;
}

void RealNoteManager::saveNote(QString title, QString text, QString date_time)
{
    list->prepend(Note(title, text, date_time));
}

void RealNoteManager::deleteNote(QString title)
{
    for(int i = 0; i<list->length();i++){
        if(list->at(i).getTitle().compare(title, Qt::CaseInsensitive) == 0){
            list->removeAt(i);
            break;
        }
    }

}

void RealNoteManager::changeNote(QString title, QString text)
{
    for(int i = 0; i<list->length();i++){
        if(list->at(i).getTitle() == title){
            Note updatedNote = list->at(i);
            updatedNote.setText(text);
            list->replace(i, updatedNote);
            break;
        }
    }
}

Note RealNoteManager::getNote(QString title)
{
    for(int i = 0; i<list->length();i++){
        if(list->at(i).getTitle() == title){
            return list->at(i);
            break;
        }
    }
    return list->at(0);
}

int RealNoteManager::getLength()
{
    return list->length();
}

void RealNoteManager::load()
{
    QString filePath = QDir(QApplication::applicationDirPath()).filePath("mynotesmaker.json");

    if (!QFile::exists(filePath)) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Cannot create JSON file: " << file.errorString();
            return;
        }
        file.close();
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file for reading: " << file.errorString();
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
        QJsonObject jsonObj = jsonDoc.object();
        QJsonArray notesArray = jsonObj["notes"].toArray();

        list->clear();

        for (const auto& noteValue : notesArray) {
            QJsonObject noteObj = noteValue.toObject();
            Note note(
                noteObj["title"].toString(),
                noteObj["text"].toString(),
                noteObj["date_time"].toString()
                );
            list->append(note);
        }
    }

    file.close();
}


void RealNoteManager::save()
{
    QString filePath = QDir(QApplication::applicationDirPath()).filePath("mynotesmaker.json");

    QJsonArray notesArray;
    for (const auto& note : *list) {
        QJsonObject noteObj;
        noteObj["title"] = note.getTitle();
        noteObj["text"] = note.getText();
        noteObj["date_time"] = note.getDateTime();
        notesArray.append(noteObj);
    }

    QJsonObject jsonObj;
    jsonObj["notes"] = notesArray;

    QJsonDocument jsonDoc(jsonObj);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Cannot open file for writing: " << file.errorString();
        return;
    }

    file.write(jsonDoc.toJson());

    file.close();
}

bool RealNoteManager::isExist(QString title)
{
    for(int i = 0; i<list->length();i++){
        if(list->at(i).getTitle() == title){
            return true;
            break;
        }
    }
    return false;
}

Note RealNoteManager::getNote(int i)
{
    return list->at(i);
}
