#include "mainwindow.h"

#include <QApplication>

#include "styles.h"

#ifdef QT_DEBUG
#include <QTest>
#include "./tests/test_styles.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Styles& style = Styles::getInstance();

    a.setStyleSheet(style.returnStyle());

    MainWindow w;
    w.show();

    // Unit Tests
#ifdef QT_DEBUG
    QTest::qExec(new Test_Styles);
#endif
    return a.exec();
}
