#include "mainwindow.h"

#include <QApplication>

#include "frameless.h"
#include "styles.h"

#ifdef QT_DEBUG
#include <QTest>
#include "./tests/test_styles.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Styles& style = Styles::getInstance(&a);

    style.setStyle("MacOS");

    MainWindow w;
    FrameLess f(&w);
    w.show();

    // Unit Tests
#ifdef QT_DEBUG
    QTest::qExec(new Test_Styles);
#endif
    return a.exec();
}
