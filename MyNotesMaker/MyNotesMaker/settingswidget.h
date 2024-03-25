#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>


namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = nullptr);
    ~SettingsWidget();


private slots:


signals:
    void on_aboutbtn_clicked();
    void on_amoled_clicked();
    void on_neon_clicked();
    void on_ubuntu_clicked();
    void on_manjaro_clicked();
    void on_materialdark_clicked();
    void on_elegantdark_clicked();
    void on_console_clicked();
    void on_aqua_clicked();
    void on_mac_clicked();

private:
    Ui::SettingsWidget *ui;
};

#endif // SETTINGSWIDGET_H
