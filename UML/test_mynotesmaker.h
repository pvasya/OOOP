#ifndef TEST_MYNOTESMAKER_H
#define TEST_MYNOTESMAKER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "QFontDialog"
#include <QTest>
#include <QMessageBox>

#include <nlohmann/json.hpp>
#include "mainwindow.h"
#include "historywindow.h"

class Test_MyNotesMaker : public QObject
{
    Q_OBJECT
public:
    explicit Test_MyNotesMaker(QObject *parent = nullptr);

signals:

private slots:
    // Unit Tests MainWindow
    void testMainWindowHideButton();
    void testMainWindowPinButton();
    void testMainWindowLineEdit();
    void testMainWindowPlainTextEdit();
    void testMainWindowLineEditEnter();


    // Unit Tests History
    void testHistoryOpenNote();
    void testHistoryDeleteButton();
    void testHistoryCancleButton();
};

#endif // TEST_MYNOTESMAKER_H

