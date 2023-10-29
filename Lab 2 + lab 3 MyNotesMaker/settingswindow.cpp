#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QFile>

#include <nlohmann/json.hpp>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_okbtn_clicked()
{
    close();
}

