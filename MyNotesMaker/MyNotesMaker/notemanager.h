#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QApplication>
#include "note.h"
/*!
 * \brief The NoteManager class, a Proxy pattern that manages notes in the program's memory.
 */
class NoteManager
{
public:
    /**
     * @brief Saves a note with the specified title, text, and date.
     * @param title The title of the note.
     * @param text The text content of the note.
     * @param date_time The date and time of the note.
     */
    virtual void saveNote(QString title, QString text, QString date_time) = 0;

    /**
     * @brief Deletes a note with the specified title.
     * @param title The title of the note to delete.
     */
    virtual void deleteNote(QString title) = 0;

    /**
     * @brief Gets the note at the specified index.
     * @param i The index of the note to retrieve.
     * @return The note at the specified index.
     */
    virtual Note getNote(int i) = 0;

    /**
     * @brief Gets the total number of notes.
     * @return The total number of notes.
     */
    virtual int getLength() = 0;

    /**
     * @brief Changes the text content of a note with the specified title.
     * @param title The title of the note to change.
     * @param text The new text content of the note.
     */
    virtual void changeNote(QString title, QString text) = 0;

    /**
     * @brief Gets the note with the specified title.
     * @param title The title of the note to retrieve.
     * @return The note with the specified title.
     */
    virtual Note getNote(QString title) = 0;

    /**
     * @brief Loads notes from storage.
     */
    virtual void load() = 0;

    /**
     * @brief Saves notes to storage.
     */
    virtual void save() = 0;

    /**
     * @brief Checks if a note with the specified title exists.
     * @param title The title of the note to check.
     * @return True if the note exists, otherwise false.
     */
    virtual bool isExist(QString title) = 0;
};

#endif // NOTEMANAGER_H
