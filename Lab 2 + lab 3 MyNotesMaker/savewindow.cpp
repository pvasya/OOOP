#include "savewindow.h"
#include "ui_savewindow.h"
#include <QFile>

#include <nlohmann/json.hpp>

SaveWindow::SaveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveWindow)
{
    ui->setupUi(this);
}

SaveWindow::~SaveWindow()
{
    delete ui;
}

void SaveWindow::on_cancel_clicked()
{
    close();
}


void SaveWindow::on_save_clicked()
{

}

