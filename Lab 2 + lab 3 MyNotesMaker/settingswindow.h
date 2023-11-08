#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

private slots:
    void on_okbtn_clicked();

    void on_ukbtn_clicked();

    void on_enbtn_clicked();

private:
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
