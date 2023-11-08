#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"
#include "history.h"
#include "QFontDialog"
#include <QFile>
#include <QSettings>
#include <QDir>
#include <curl/curl.h>
#include "openai.hpp"
#include <nlohmann/json.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings(QDir::homePath()+ "/Desktop/mynotesmaker settings.ini", QSettings::IniFormat);
    restoreGeometry(settings.value("geometry").toByteArray());
}

MainWindow::~MainWindow()
{
    QSettings settings(QDir::homePath()+ "/Desktop/mynotesmaker settings.ini", QSettings::IniFormat);
    settings.setValue("geometry", saveGeometry());
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
    SettingsWindow *settings = new SettingsWindow;
    settings->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    settings->setModal(true);
    settings->setGeometry(this->x() + 10, this->y() + 35,250,170);
    settings->show();
}


void MainWindow::on_historbtn_clicked()
{
    History *historywin = new History;
    historywin->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    historywin->setModal(true);
    historywin->setGeometry(this->x() + 10, this->y() + 35,250,430);
    historywin->show();
    connect(historywin, &History::open, this, &MainWindow::slot);
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
    MainWindow *mainWindow = new MainWindow();
    mainWindow->setWindowFlags(Qt::FramelessWindowHint);
    mainWindow->setGeometry(this->x() + 30, this->y() + 30,300,480);
    mainWindow->show();
}

void MainWindow::on_hidebtn_clicked()
{
    showMinimized();
}

void MainWindow::on_savebtn_clicked()
{
    QString filePath = QDir::homePath() + "/Desktop/mynotesmaker.json";
    nlohmann::json data;
    if (QFile::exists(filePath)) {
        QFile existingFile(filePath);
        if (existingFile.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&existingFile);
            QString jsonString = in.readAll();
            existingFile.close();
            try {
                data = nlohmann::json::parse(jsonString.toStdString());
            } catch (const std::exception& e) {
                qWarning() << "Error parsing JSON: " << e.what();
                return;
            }
            nlohmann::json note;
            note["name"] = ui->lineEdit->text().toStdString();
            note["text"] = ui->plainTextEdit->toPlainText().toStdString();
            note["font"] = ui->plainTextEdit->font().toString().toStdString();
            data.insert(data.begin(), note);
        } else {
            qWarning() << "Error reading the existing file.";
        }
    }
    else {
        nlohmann::json note;
        note["name"] = ui->lineEdit->text().toStdString();
        note["text"] = ui->plainTextEdit->toPlainText().toStdString();
        note["font"] = ui->plainTextEdit->font().toString().toStdString();
        data.push_back(note);
    }
    QFile file(filePath);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&file);
        out << QString::fromStdString(data.dump());
        file.close();
    } else {
        qWarning() << "ERROR";
    }
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
    openai::start("key");
    std::string req = ui->plainTextEdit->toPlainText().toStdString();
    nlohmann::json jsonRequest;
    QSettings settings(QDir::homePath()+ "/Desktop/mynotesmaker settings.ini", QSettings::IniFormat);
    jsonRequest["model"] = settings.value("GPT version", QString("gpt-3.5-turbo")).toString().toStdString();
    jsonRequest["messages"] = {
        {{"role", "user"}, {"content", req}}
    };
    jsonRequest["max_tokens"] = 30;
    jsonRequest["temperature"] = 0;
    auto chat = openai::chat().create(jsonRequest);
    ui->plainTextEdit->setPlainText(QString::fromStdString(chat["choices"][0]["message"]["content"].get<std::string>()));
}


void MainWindow::on_gptbtn_2_clicked()
{
    openai::start("key");
    std::string req = "Rewrite it correctly, beautifully and give just the text: " + ui->plainTextEdit->toPlainText().toStdString();
    nlohmann::json jsonRequest;
    QSettings settings(QDir::homePath()+ "/Desktop/mynotesmaker settings.ini", QSettings::IniFormat);
    jsonRequest["model"] = settings.value("GPT version", QString("gpt-3.5-turbo")).toString().toStdString();
    jsonRequest["messages"] = {
        {{"role", "user"}, {"content", req}}
    };
    jsonRequest["max_tokens"] = 30;
    jsonRequest["temperature"] = 0;
    auto chat = openai::chat().create(jsonRequest);
    ui->plainTextEdit->setPlainText(QString::fromStdString(chat["choices"][0]["message"]["content"].get<std::string>()));

}

void MainWindow::slot(QString name, QString text, QFont font)
{
    ui->lineEdit->setText(name);
    ui->plainTextEdit->setPlainText(text);
    ui->plainTextEdit->setFont(font);
}
