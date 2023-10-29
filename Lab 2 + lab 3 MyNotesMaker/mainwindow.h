#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_closebtn_clicked();

    void on_settingsbtn_clicked();

    void on_historbtn_clicked();

    void on_toolsbtn_clicked();

    void on_newbtn_clicked();

    void on_hidebtn_clicked();

    void on_pinbtn_clicked();

    void on_savebtn_clicked();

    void on_gptbtn_1_clicked();

    void on_gptbtn_2_clicked();

    void on_timeout();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QPoint cur_pos;
    QPoint new_pos;
};

#endif // MAINWINDOW_H
