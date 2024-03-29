#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QFile>
#include <QSettings>
#include <QDir>

#include <nlohmann/json.hpp>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    QSettings settings(QDir::homePath()+ "/Desktop/mynotesmaker settings.ini", QSettings::IniFormat);
    if (settings.value("GPT version", "gpt-3.5-turbo") == "gpt-3.5-turbo"){
        ui->probtn->setStyleSheet("QPushButton {"
                                 "    font: 700 10pt 'Segoe Script';"
                                 "    background-color: rgb(251, 230, 127);"
                                 "    border-radius: 30px;"
                                 "}"
                                 "QPushButton:hover {"
                                 "    background-color: rgb(251, 180, 82);"
                                 "}"
                                 "QPushButton:pressed {"
                                 "    background-color: rgb(255, 140, 0);"
                                 "}");
        ui->standartbtn->setStyleSheet("QPushButton {"
                                 "    font: 700 10pt 'Segoe Script';"
                                 "    background-color: rgb(251, 230, 127);"
                                 "    border-radius: 30px;"
                                 "    border: 2px solid blue;"
                                 "}"
                                 "QPushButton:hover {"
                                 "    background-color: rgb(251, 180, 82);"
                                 "}"
                                 "QPushButton:pressed {"
                                 "    background-color: rgb(255, 140, 0);"
                                 "}");
    }
    else{
        ui->probtn->setStyleSheet("QPushButton {"
                                 "    font: 700 10pt 'Segoe Script';"
                                 "    background-color: rgb(251, 230, 127);"
                                 "    border-radius: 30px;"
                                 "    border: 2px solid blue;"
                                 "}"
                                 "QPushButton:hover {"
                                 "    background-color: rgb(251, 180, 82);"
                                 "}"
                                 "QPushButton:pressed {"
                                 "    background-color: rgb(255, 140, 0);"
                                 "}");
        ui->standartbtn->setStyleSheet("QPushButton {"
                                 "    font: 700 10pt 'Segoe Script';"
                                 "    background-color: rgb(251, 230, 127);"
                                 "    border-radius: 30px;"
                                 "}"
                                 "QPushButton:hover {"
                                 "    background-color: rgb(251, 180, 82);"
                                 "}"
                                 "QPushButton:pressed {"
                                 "    background-color: rgb(255, 140, 0);"
                                 "}");
    }
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_okbtn_clicked()
{
    close();
}

void SettingsWindow::on_standartbtn_clicked()
{
    QSettings settings(QDir::homePath()+ "/Desktop/mynotesmaker settings.ini", QSettings::IniFormat);
    settings.setValue("GPT version", "gpt-3.5-turbo");
    settings.sync();
    ui->probtn->setStyleSheet("QPushButton {"
                             "    font: 700 10pt 'Segoe Script';"
                             "    background-color: rgb(251, 230, 127);"
                             "    border-radius: 30px;"
                             "}"
                             "QPushButton:hover {"
                             "    background-color: rgb(251, 180, 82);"
                             "}"
                             "QPushButton:pressed {"
                             "    background-color: rgb(255, 140, 0);"
                             "}");
    ui->standartbtn->setStyleSheet("QPushButton {"
                             "    font: 700 10pt 'Segoe Script';"
                             "    background-color: rgb(251, 230, 127);"
                             "    border-radius: 30px;"
                             "    border: 2px solid blue;"
                             "}"
                             "QPushButton:hover {"
                             "    background-color: rgb(251, 180, 82);"
                             "}"
                             "QPushButton:pressed {"
                             "    background-color: rgb(255, 140, 0);"
                             "}");
}

void SettingsWindow::on_probtn_clicked()
{
    QSettings settings(QDir::homePath()+ "/Desktop/mynotesmaker settings.ini", QSettings::IniFormat);
    settings.setValue("GPT version", "gpt-3.5-turbo-16k");
    settings.sync();
    ui->probtn->setStyleSheet("QPushButton {"
                             "    font: 700 10pt 'Segoe Script';"
                             "    background-color: rgb(251, 230, 127);"
                             "    border-radius: 30px;"
                             "    border: 2px solid blue;"
                             "}"
                             "QPushButton:hover {"
                             "    background-color: rgb(251, 180, 82);"
                             "}"
                             "QPushButton:pressed {"
                             "    background-color: rgb(255, 140, 0);"
                             "}");
    ui->standartbtn->setStyleSheet("QPushButton {"
                             "    font: 700 10pt 'Segoe Script';"
                             "    background-color: rgb(251, 230, 127);"
                             "    border-radius: 30px;"
                             "}"
                             "QPushButton:hover {"
                             "    background-color: rgb(251, 180, 82);"
                             "}"
                             "QPushButton:pressed {"
                             "    background-color: rgb(255, 140, 0);"
                             "}");
}


void SettingsWindow::mousePressEvent(QMouseEvent *event){
    cur_pos = event->globalPosition().toPoint();
}

void SettingsWindow::mouseMoveEvent(QMouseEvent *event){
    new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
    move(x()+new_pos.x(), y()+new_pos.y());
    cur_pos = event->globalPosition().toPoint();
}
