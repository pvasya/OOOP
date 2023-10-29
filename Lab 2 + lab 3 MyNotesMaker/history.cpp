#include "history.h"
#include "ui_history.h"
#include <QFile>

#include <nlohmann/json.hpp>

History::History(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::on_okbtn_clicked()
{
    close();
}

