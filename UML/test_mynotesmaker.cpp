#include "test_mynotesmaker.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

Test_MyNotesMaker::Test_MyNotesMaker(QObject *parent)
    : QObject{parent}
{}

void Test_MyNotesMaker::testMainWindowHideButton()
{
    MainWindow mainWindow;

    QVERIFY(!mainWindow.isMinimized());

    QPushButton* hideButton = mainWindow.findChild<QPushButton*>("hidebtn");
    QVERIFY(hideButton != nullptr);

    QTest::mouseClick(hideButton, Qt::LeftButton);

    QVERIFY(mainWindow.isMinimized());
}

void Test_MyNotesMaker::testMainWindowPinButton()
{
    MainWindow mainWindow;

    QVERIFY(!(mainWindow.windowFlags() & Qt::WindowStaysOnTopHint));

    QPushButton* pinButton = mainWindow.findChild<QPushButton*>("pinbtn");
    QVERIFY(pinButton != nullptr);

    QTest::mouseClick(pinButton, Qt::LeftButton);

    QVERIFY(mainWindow.windowFlags() & Qt::WindowStaysOnTopHint);
}

void Test_MyNotesMaker::testMainWindowLineEdit()
{
    MainWindow mainWindow;

    QLineEdit *lineEdit = mainWindow.findChild<QLineEdit*>("lineEdit");

    QVERIFY(lineEdit != nullptr);

    QTest::keyClicks(lineEdit, "qwerty12345!");

    QCOMPARE(lineEdit->text(), QString("qwerty12345!"));

    QTest::keyClicks(lineEdit, " Hi#####");

    QCOMPARE(lineEdit->text(), QString("qwerty12345! Hi#####"));

    QTest::keyClicks(lineEdit, "    How are you?");

    QCOMPARE(lineEdit->text(), QString("qwerty12345! Hi#####    How are you?"));
}



void Test_MyNotesMaker::testMainWindowPlainTextEdit()
{
    MainWindow mainWindow;

    QLineEdit *lineEdit = mainWindow.findChild<QLineEdit*>("lineEdit");

    QVERIFY(lineEdit != nullptr);

    QTest::keyClicks(lineEdit, "Hi!");

    QCOMPARE(lineEdit->text(), QString("Hi!"));

    QTest::keyClicks(lineEdit, " How are you?");

    QCOMPARE(lineEdit->text(), QString("Hi! How are you?"));

    QTest::keyClicks(lineEdit, " I'm fine");

    QCOMPARE(lineEdit->text(), QString("Hi! How are you? I'm fine"));
}

void Test_MyNotesMaker::testMainWindowLineEditEnter()
{
    MainWindow mainWindow;

    QLineEdit *lineEdit = mainWindow.findChild<QLineEdit*>("lineEdit");
    QVERIFY(lineEdit != nullptr);

    QPlainTextEdit *plainTextEdit = mainWindow.findChild<QPlainTextEdit*>("plainTextEdit");
    QVERIFY(plainTextEdit != nullptr);

    QTest::keyClicks(lineEdit, "Hi!");

    QTest::keyClicks(plainTextEdit, " How are you?");


    QPushButton* savebtn = mainWindow.findChild<QPushButton*>("savebtn");

    QVERIFY(savebtn != nullptr);

    QTest::mouseClick(savebtn, Qt::LeftButton);

    QTest::keyClicks(lineEdit, " 2");
    QTest::keyClicks(plainTextEdit, " 2");

    QTest::mouseClick(savebtn, Qt::LeftButton);

    QString filePath = QDir::homePath() + "/Desktop/mynotesmaker.json";
    QVERIFY(QFile::exists(filePath));

    QFile jsonFile(filePath);
    QVERIFY(jsonFile.open(QIODevice::ReadOnly | QIODevice::Text));

    QString jsonString = jsonFile.readAll();
    jsonFile.close();

    nlohmann::json jsonData = nlohmann::json::parse(jsonString.toStdString());

    QVERIFY(jsonData.size() > 0);
}

void Test_MyNotesMaker::testHistoryOpenNote()
{
    HistoryWindow historyWin;

    QListWidget* listWidget = historyWin.findChild<QListWidget*>("listWidget");
    QVERIFY(listWidget != nullptr);

    listWidget->setCurrentRow(0);

    QPushButton* open = historyWin.findChild<QPushButton*>("openbtn");
    QVERIFY(open != nullptr);
    QTest::mouseClick(open, Qt::LeftButton);

    QVERIFY(historyWin.isHidden());
}


void Test_MyNotesMaker::testHistoryDeleteButton()
{
    HistoryWindow historyWin;

    QListWidget* listWidget = historyWin.findChild<QListWidget*>("listWidget");
    QVERIFY(listWidget != nullptr);

    int expectedInitialSize = listWidget->count();

    QPushButton* deleteButton = historyWin.findChild<QPushButton*>("deletebtn");
    QVERIFY(deleteButton != nullptr);

    if (expectedInitialSize > 0) {
        listWidget->setCurrentRow(0);

        QTest::mouseClick(deleteButton, Qt::LeftButton);

        QCOMPARE(listWidget->count(), expectedInitialSize - 1);
    }

    if (listWidget->count() > 0) {
        listWidget->setCurrentRow(0);

        QTest::mouseClick(deleteButton, Qt::LeftButton);

        QCOMPARE(listWidget->count(), expectedInitialSize - 2);
    }
}

void Test_MyNotesMaker::testHistoryCancleButton()
{
    HistoryWindow historyWin;

    QPushButton* cancel = historyWin.findChild<QPushButton*>("okbtn");
    QVERIFY(cancel != nullptr);

    QTest::mouseClick(cancel, Qt::LeftButton);

    QVERIFY(historyWin.isHidden());
}

