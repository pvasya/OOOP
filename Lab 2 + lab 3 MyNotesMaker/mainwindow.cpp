#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"
#include "history.h"
#include "QFontDialog"
#include "savewindow.h"
#include "view.h"
#include <QTime>
#include <QTimer>
#include <QFile>
#include <curl/curl.h>
#include "openai.hpp"
#include <nlohmann/json.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(QFile::exists("mynotemaker.json")){

    }
    else{

    }

    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timeout()));
    timer->start(60000);
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
    settings.setGeometry(this->x() + 10, this->y() + 35,250,170);
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

void MainWindow::on_gptbtn_1_clicked()
{
    openai::start();
    std::string req = ui->plainTextEdit->toPlainText().toStdString();
    nlohmann::json jsonRequest;
    jsonRequest["model"] = "gpt-3.5-turbo";
    jsonRequest["messages"] = {
        {{"role", "user"}, {"content", req}}
    };
    jsonRequest["max_tokens"] = 7;
    jsonRequest["temperature"] = 0;
    auto chat = openai::chat().create(jsonRequest);
    ui->plainTextEdit->setPlainText(QString::fromStdString(chat.dump(2)));
}


void MainWindow::on_gptbtn_2_clicked()
{
    openai::start();
    std::string req = "Rewrite it correctly beautifully and give just the text: " + ui->plainTextEdit->toPlainText().toStdString();
    nlohmann::json jsonRequest;
    jsonRequest["model"] = "gpt-3.5-turbo";
    jsonRequest["messages"] = {
        {{"role", "user"}, {"content", req}}
    };
    jsonRequest["max_tokens"] = 7;
    jsonRequest["temperature"] = 0;
    auto chat = openai::chat().create(jsonRequest);
    ui->plainTextEdit->setPlainText(QString::fromStdString(chat.dump(2)));
}

void MainWindow::on_timeout()
{
    View viewwin;
    viewwin.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    viewwin.setModal(true);
    viewwin.exec();
}

