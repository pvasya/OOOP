#include "savewindow.h"
#include "ui_savewindow.h"

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

}


void SaveWindow::on_save_clicked()
{
    close();
}



void SaveWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->spinBox->setValue(position);
}



void SaveWindow::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

