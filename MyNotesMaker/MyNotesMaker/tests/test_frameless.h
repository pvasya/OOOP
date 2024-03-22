#ifndef TEST_FRAMELESS_H
#define TEST_FRAMELESS_H

#include <QObject>
#include <QTest>

class Test_Frameless : public QObject
{
    Q_OBJECT
public:
    explicit Test_Frameless(QObject *parent = nullptr);


signals:

private slots:
    // Unit Tests
    void testFramelessWindowHint();
};

#endif // TEST_FRAMELESS_H
