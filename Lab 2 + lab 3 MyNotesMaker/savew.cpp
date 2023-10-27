#include "savew.h"
#include "ui_savew.h"

SaveW::SaveW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveW)
{
    ui->setupUi(this);
}

SaveW::~SaveW()
{
    delete ui;
}

void SaveW::on_okbtn_clicked()
{
    close();
}


void SaveW::on_okbtn_2_clicked()
{
    close();
}

