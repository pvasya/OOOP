#include "test_styles.h"

#include "../styles.h"

#include <QTest>

Test_Styles::Test_Styles(QObject *parent)
    : QObject{parent}
{}

void Test_Styles::testAqua()
{
    Styles& style = Styles::getInstance();
    QVERIFY(style.getStyleName() == "Aqua");
}

void Test_Styles::testAmoled()
{
    Styles& style = Styles::getInstance();
    style.setStyle("Amoled");
    QVERIFY(style.getStyleName() == "Amoled");
}

void Test_Styles::testMacOS()
{
    Styles& style = Styles::getInstance();
    style.setStyle("MacOS");
    QVERIFY(style.getStyleName() == "MacOS");
}

void Test_Styles::testElegantDark()
{
    Styles& style = Styles::getInstance();
    style.setStyle("ElegantDark");
    QVERIFY(style.getStyleName() == "ElegantDark");
}

void Test_Styles::testMaterial()
{
        Styles& style = Styles::getInstance();
        style.setStyle("Material");
        QVERIFY(style.getStyleName() == "Aqua");
}
