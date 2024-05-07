#include "test_note.h"

Test_Note::Test_Note(QObject *parent)
    : QObject{parent}
{}

void Test_Note::testSetTitle()
{
    Note note("n1","text1","04-04-2024");
    note.setTitle("test");
    QCOMPARE("test", note.getTitle());
}

void Test_Note::testSetText()
{
    Note note("n1","text1","04-04-2024");
    note.setText("test");
    QCOMPARE("test", note.getText());
}

void Test_Note::testSetDate()
{
    Note note("n1","text1","04-04-2024");
    note.setDateTime("01.11.2011");
    QCOMPARE("01.11.2011",note.getDateTime());
}
