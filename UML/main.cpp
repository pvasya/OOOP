#include "mainwindow.h"
#include <QApplication>
#include <QTest>

#ifdef QT_DEBUG
#include "test_mynotesmaker.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();


    // Unit Tests
#ifdef QT_DEBUG
    QTest::qExec(new Test_MyNotesMaker);
#endif

    return a.exec();
}
