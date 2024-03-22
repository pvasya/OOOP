#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "style.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Style* st, QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_backBtn_clicked();

    void on_closebtn_clicked();

    void on_hidebtn_clicked();

    void on_topbtn_clicked();

    void on_fullbtn_clicked();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void moveEvent(QMoveEvent *event) override;


private:
    Ui::MainWindow *ui;
    Style* style;
};
#endif // MAINWINDOW_H
