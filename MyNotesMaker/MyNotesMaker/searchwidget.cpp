#include "searchwidget.h"
#include "ui_searchwidget.h"

#include "./FormattingCommand/invoker.h"

SearchWidget::SearchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchWidget)
{

    ui->setupUi(this);
}

SearchWidget::~SearchWidget()
{
    delete ui;
}


void SearchWidget::on_pushButton_4_clicked()
{
    Invoker& inv = Invoker::getInstance();
    inv.startCommand(0);
}


void SearchWidget::on_pushButton_5_clicked()
{
    Invoker& inv = Invoker::getInstance();
    inv.startCommand(1);
}


void SearchWidget::on_pushButton_6_clicked()
{
    Invoker& inv = Invoker::getInstance();
    inv.startCommand(2);
}


void SearchWidget::on_pushButton_7_clicked()
{
    Invoker& inv = Invoker::getInstance();
    inv.startCommand(3);
}


void SearchWidget::on_pushButton_8_clicked()
{
    Invoker& inv = Invoker::getInstance();
    inv.startCommand(4);
}

