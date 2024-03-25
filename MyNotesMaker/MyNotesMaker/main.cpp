#include "mainwindow.h"

#include <QApplication>

#include "frameless.h"
#include "style.h"

#include "./FormattingCommand/invoker.h"
#include "./FormattingCommand/bold.h"
#include "./FormattingCommand/italic.h"
#include "./FormattingCommand/underline.h"
#include "./FormattingCommand/color.h"
#include "./FormattingCommand/backgroundcolor.h"

#ifdef QT_DEBUG
#include <QTest>
#include "./tests/test_styles.h"
#include "./tests/test_frameless.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // Singleton Pattern
    Style& style = Style::getInstance(&a);

    style.setStyle("Aqua");

    MainWindow w(&style);
    FrameLess f(&w);
    w.setAttribute(Qt::WA_TranslucentBackground, true);

    // Command Pattern
    Bold b(w);
    Italic i(w);
    Underline u(w);
    Color c(w);
    BackgroundColor bc(w);

    Invoker& inv = Invoker::getInstance();

    inv.addCommand(&b);
    inv.addCommand(&i);
    inv.addCommand(&u);
    inv.addCommand(&c);
    inv.addCommand(&bc);

    w.show();

    // Unit Tests
#ifdef QT_DEBUG
    QTest::qExec(new Test_Styles(&style));
    QTest::qExec(new Test_Frameless);
#endif
    return a.exec();
}
