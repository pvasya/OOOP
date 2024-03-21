#include "mainwindow.h"

#include <QApplication>

#include "frameless.h"
#include "style.h"

#ifdef QT_DEBUG
#include <QTest>
#include "./tests/test_styles.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Style& style = Style::getInstance(&a);

    style.setStyle("Aqua");

    MainWindow w(&style);
    FrameLess f(&w);
    w.setAttribute(Qt::WA_TranslucentBackground, true);
    w.show();

    // Unit Tests
#ifdef QT_DEBUG
    QTest::qExec(new Test_Styles);
#endif
    return a.exec();
}
