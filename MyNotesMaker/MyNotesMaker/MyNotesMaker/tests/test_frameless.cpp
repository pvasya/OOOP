#include "test_frameless.h"

#include "../frameless.h"
#include "../mainwindow.h"

#include <QTest>

Test_Frameless::Test_Frameless(QObject *parent)
    : QObject{parent}
{}

void Test_Frameless::testFramelessWindowHint()
{
    MainWindow w(NULL);
    FrameLess f(&w);

    QVERIFY(w.windowFlags() & Qt::FramelessWindowHint);
}



