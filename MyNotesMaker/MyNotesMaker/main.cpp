#include "mainwindow.h"

#include <QApplication>

#include "frameless.h"
#include "style.h"

#ifdef QT_DEBUG
#include <QTest>
#include "./tests/test_styles.h"
#include "./tests/test_note.h"
#include "./tests/test_proxymanager.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Singleton Pattern
    Style::get().setApplication(&a);
    Style::get().setStyleName("Aqua");

    MainWindow w;
    FrameLess f(&w);
    w.setAttribute(Qt::WA_TranslucentBackground, true);

    w.show();

    // Unit Tests
#ifdef QT_DEBUG
    QTest::qExec(new Test_Styles());
    QTest::qExec(new Test_Note());
    QTest::qExec(new Test_ProxyManager);
#endif
    return a.exec();
}
