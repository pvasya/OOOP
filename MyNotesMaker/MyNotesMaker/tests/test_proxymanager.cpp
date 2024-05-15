#include "test_proxymanager.h"

Test_ProxyManager::Test_ProxyManager(QObject *parent)
    : QObject{parent}
{}

void Test_ProxyManager::testSave()
{
    ProxyNoteManager manager;
    manager.saveNote("test","text","01.01.2001");
    QCOMPARE(manager.getNote(0).getTitle(),"test");
    QCOMPARE(manager.getNote(0).getText(),"text");
    QCOMPARE(manager.getNote(0).getDateTime(),"01.01.2001");
}

void Test_ProxyManager::testDelete()
{
    ProxyNoteManager manager;
    QCOMPARE(manager.getLength(),0);
    manager.saveNote("test","text","01.01.2001");
    QCOMPARE(manager.getLength(),1);
    manager.deleteNote("test");
    QCOMPARE(manager.getLength(),0);
}

void Test_ProxyManager::testChange()
{
    ProxyNoteManager manager;
    manager.saveNote("test","text","01.01.2001");
    QCOMPARE(manager.getNote(0).getTitle(),"test");
    QCOMPARE(manager.getNote(0).getText(),"text");
    QCOMPARE(manager.getNote(0).getDateTime(),"01.01.2001");
    manager.changeNote("test","long long text");
    QCOMPARE(manager.getNote(0).getTitle(),"test");
    QCOMPARE(manager.getNote(0).getText(),"long long text");
    QCOMPARE(manager.getNote(0).getDateTime(),"01.01.2001");
}

void Test_ProxyManager::testLenght()
{
    ProxyNoteManager manager;
    manager.saveNote("test1","text","01.01.2001");
    QCOMPARE(manager.getLength(),1);
    manager.saveNote("test2","text","01.01.2001");
    QCOMPARE(manager.getLength(),2);
    manager.saveNote("test3","text","01.01.2001");
    QCOMPARE(manager.getLength(),3);
    manager.saveNote("test4","text","01.01.2001");
    QCOMPARE(manager.getLength(),4);
    manager.saveNote("test5","text","01.01.2001");
    QCOMPARE(manager.getLength(),5);

}

void Test_ProxyManager::testIsExist()
{
    ProxyNoteManager manager;
    manager.saveNote("test","text","01.01.2001");
    QCOMPARE(manager.isExist("1"),false);
    QCOMPARE(manager.isExist("test"),true);
}
