#ifndef TEST_PROXYMANAGER_H
#define TEST_PROXYMANAGER_H

#include <QObject>
#include <QTest>

#include "../proxynotemanager.h"

class Test_ProxyManager : public QObject
{
    Q_OBJECT
public:
    explicit Test_ProxyManager(QObject *parent = nullptr);

private slots:
    // Unit Tests
    void testSave();
    void testDelete();
    void testChange();
    void testLenght();
    void testIsExist();

signals:
};

#endif // TEST_PROXYMANAGER_H
