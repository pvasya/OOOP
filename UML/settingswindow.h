#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QMouseEvent>
#include <QPoint>

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
    /*!
     * \brief Закриття вікна налаштувань
     */
    void on_okbtn_clicked();
    /*!
     * \brief Вибір ChatGPT 3.5 Turbo
     */
    void on_standartbtn_clicked();
    /*!
     * \brief Вибір ChatGPT 3.5 Turbo 16k
     */
    void on_probtn_clicked();

private:
    Ui::SettingsWindow *ui;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QPoint cur_pos;
    QPoint new_pos;
};

#endif // SETTINGSWINDOW_H
