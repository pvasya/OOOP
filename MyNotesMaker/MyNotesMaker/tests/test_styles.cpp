#include "test_styles.h"
#include "../style.h"
#include <QTest>

Test_Styles::Test_Styles( QObject *parent)
    : QObject(parent)
    , style(style)
{}

void Test_Styles::testAmoled()
{
    Style::get().setStyle("Amoled");
    QCOMPARE(Style::get().getStyleName(), QString("Amoled"));
}

void Test_Styles::testMacOS()
{
    Style::get().setStyle("MacOS");
    QCOMPARE(Style::get().getStyleName(), QString("MacOS"));
}

void Test_Styles::testElegantDark()
{
    Style::get().setStyle("ElegantDark");
    QCOMPARE(Style::get().getStyleName(), QString("ElegantDark"));
}

void Test_Styles::testMaterial()
{
    Style::get().setStyle("Material");
    QCOMPARE(Style::get().getStyleName(), QString("Aqua"));
}

void Test_Styles::testAqua()
{
    Style::get().setStyle("Aqua");
    QCOMPARE(Style::get().getStyleName(), QString("Aqua"));
}
