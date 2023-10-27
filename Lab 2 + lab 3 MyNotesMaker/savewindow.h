#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QDialog>

namespace Ui {
class SaveWindow;
}

class SaveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SaveWindow(QWidget *parent = nullptr);
    ~SaveWindow();

private slots:
    void on_cancel_clicked();

    void on_save_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::SaveWindow *ui;
};

#endif // SAVEWINDOW_H
