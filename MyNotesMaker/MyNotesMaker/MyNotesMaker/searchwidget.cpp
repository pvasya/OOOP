#include "searchwidget.h"
#include "ui_searchwidget.h"

#include "./FormattingCommand/invoker.h"
#include "./FormattingCommand/formatcommandsenum.h"

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

void SearchWidget::on_searchBtn_clicked()
{
    emit find(ui->searchLineEdit->text());
}


void SearchWidget::on_replaceBtn_clicked()
{
    emit replace(ui->searchLineEdit->text(), ui->replaceLineEdit->text());
}


void SearchWidget::on_replaceAllBtn_clicked()
{
    emit replaceAll(ui->searchLineEdit->text(), ui->replaceLineEdit->text());
}


void SearchWidget::on_swapBtn_clicked()
{
    QString temp = ui->searchLineEdit->text();
    ui->searchLineEdit->setText(ui->replaceLineEdit->text());
    ui->replaceLineEdit->setText(temp);
}

void SearchWidget::on_boldBtn_clicked()
{
    Invoker::get().startCommand(Format::Bold);
}


void SearchWidget::on_italicBtn_clicked()
{
    Invoker::get().startCommand(Format::Italic);
}


void SearchWidget::on_underlineBtn_clicked()
{
    Invoker::get().startCommand(Format::Underline);
}


void SearchWidget::on_colorBtn_clicked()
{
    Invoker::get().startCommand(Format::Color);
}


void SearchWidget::on_backgroundColorBtn_clicked()
{
    Invoker::get().startCommand(Format::BackgroundColor);
}

