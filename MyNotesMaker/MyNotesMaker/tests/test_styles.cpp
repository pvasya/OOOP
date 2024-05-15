#include "test_styles.h"
#include "../style.h"
#include <QTest>

Test_Styles::Test_Styles( QObject *parent)
    : QObject(parent)
    , style(style)
{}

void Test_Styles::testAmoled()
{
    Style::get().setStyleName("Amoled");
    QCOMPARE(Style::get().getStyleName(), QString("Amoled"));
}

void Test_Styles::testMacOS()
{
    Style::get().setStyleName("MacOS");
    QCOMPARE(Style::get().getStyleName(), QString("MacOS"));
}

void Test_Styles::testElegantDark()
{
    Style::get().setStyleName("ElegantDark");
    QCOMPARE(Style::get().getStyleName(), QString("ElegantDark"));
}

void Test_Styles::testMaterial()
{
    Style::get().setStyleName("Material");
    QCOMPARE(Style::get().getStyleName(), QString("Aqua"));
}

void Test_Styles::testAqua()
{
    Style::get().setStyleName("Aqua");
    QCOMPARE(Style::get().getStyleName(), QString("Aqua"));
}
