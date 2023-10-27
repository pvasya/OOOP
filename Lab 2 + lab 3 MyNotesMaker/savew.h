#ifndef SAVEW_H
#define SAVEW_H

#include <QDialog>

namespace Ui {
class SaveW;
}

class SaveW : public QDialog
{
    Q_OBJECT

public:
    explicit SaveW(QWidget *parent = nullptr);
    ~SaveW();

private slots:
    void on_okbtn_clicked();

    void on_okbtn_2_clicked();

private:
    Ui::SaveW *ui;
};

#endif // SAVEW_H
