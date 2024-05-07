#ifndef TEST_NOTE_H
#define TEST_NOTE_H

#include <QObject>
#include <QTest>

#include "../note.h"

class Test_Note : public QObject
{
    Q_OBJECT
public:
    explicit Test_Note(QObject *parent = nullptr);


private slots:
    // Unit Tests
    void testSetTitle();
    void testSetText();
    void testSetDate();


signals:
};

#endif // TEST_NOTE_H
