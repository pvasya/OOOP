#include "test_styles.h"
#include "../style.h"
#include <QTest>

Test_Styles::Test_Styles(Style* style, QObject *parent)
    : QObject(parent)
    , style(style)
{}

void Test_Styles::testAqua()
{
    style->setStyle("Aqua");
    QCOMPARE(style->getStyleName(), QString("Aqua"));
}

void Test_Styles::testAmoled()
{
    style->setStyle("Amoled");
    QCOMPARE(style->getStyleName(), QString("Amoled"));
}

void Test_Styles::testMacOS()
{
    style->setStyle("MacOS");
    QCOMPARE(style->getStyleName(), QString("MacOS"));
}

void Test_Styles::testElegantDark()
{
    style->setStyle("ElegantDark");
    QCOMPARE(style->getStyleName(), QString("ElegantDark"));
}

void Test_Styles::testMaterial()
{
    style->setStyle("Material");
    QCOMPARE(style->getStyleName(), QString("Aqua"));
}
