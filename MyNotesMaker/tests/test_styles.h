#ifndef TEST_STYLES_H
#define TEST_STYLES_H

#include <QObject>
#include <QTest>

class Test_Styles : public QObject
{
    Q_OBJECT
public:
    explicit Test_Styles(QObject *parent = nullptr);


signals:

private slots:
    // Unit Tests
    void testAqua();
    void testAmoled();
    void testMacOS();
    void testElegantDark();
    void testMaterial();

};

#endif // TEST_STYLES_H
