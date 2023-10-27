#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"
#include "history.h"
#include "QFontDialog"
#include "savewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    cur_pos = event->globalPosition().toPoint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
    move(x()+new_pos.x(), y()+new_pos.y());
    cur_pos = event->globalPosition().toPoint();
}

void MainWindow::on_closebtn_clicked()
{
    close();
}


void MainWindow::on_settingsbtn_clicked()
{
    SettingsWindow settings;
    settings.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    settings.setModal(true);
    settings.setGeometry(this->x() + 10, this->y() + 35,250,300);
    settings.exec();
}


void MainWindow::on_historbtn_clicked()
{
    History historywin;
    historywin.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    historywin.setModal(true);
    historywin.setGeometry(this->x() + 10, this->y() + 35,250,400);
    historywin.exec();
}

void MainWindow::on_toolsbtn_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok ,QFont("Segoe Script",12),this);
    if(ok){
        ui->plainTextEdit->setFont(font);
    }
}

void MainWindow::on_newbtn_clicked()
{
    ui->plainTextEdit->setPlainText("");
}



void MainWindow::on_hidebtn_clicked()
{
    showMinimized();
}

void MainWindow::on_savebtn_clicked()
{
    SaveWindow savewin;
    savewin.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    savewin.setModal(true);
    savewin.setGeometry(this->x() + 10, this->y() + 35,250,400);
    savewin.exec();
}

void MainWindow::on_pinbtn_clicked()
{
    if (windowFlags() & Qt::WindowStaysOnTopHint) {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
        ui->pinbtn->setIcon(QIcon(":/img/pin-removebg.png"));
        }
    else {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
        ui->pinbtn->setIcon(QIcon(":/img/unpin-removebg.png"));
        }
    show();
}


bool bclicked = false;

void MainWindow::on_speechtextbtn_1_clicked()
{
    if (bclicked) {
        ui->speechtextbtn_1->setStyleSheet("QPushButton { border-image: url(:/img/voicetext.png); background-color: rgb(255, 0, 127); color: white;border-radius: 10px;padding: 10px;}");
    }
    else {
        ui->speechtextbtn_1->setStyleSheet("QPushButton { border-image: url(:/img/voicetextred.png); background-color:rgb(0, 0, 255); color: white;border-radius: 10px;padding: 10px;}");
    }
    bclicked = !bclicked;
    show();
}

