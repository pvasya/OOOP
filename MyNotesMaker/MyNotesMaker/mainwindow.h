#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ExportStrategy/exportcontext.h"
#include "ExportStrategy/html.h"
#include "ExportStrategy/pdf.h"
#include "ParticleLife/particlelifewidget.h"
#include "searchwidget.h"
#include "settingswidget.h"
#include "style.h"


#include "QSidePanel/PanelRightSide.hpp"

#include "QSidePanel/PanelBottomSide.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Style* st, QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_backBtn_clicked();

    void on_closebtn_clicked();

    void on_hidebtn_clicked();

    void on_topbtn_clicked();

    void on_fullbtn_clicked();

    void on_about();

    void on_amoled();
    void on_neon();
    void on_manjaro();
    void on_aqua();
    void on_elegantdark();
    void on_materialdark();
    void on_console();
    void on_mac();
    void on_ubuntu();


    void on_pushButton_4_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();


protected:
    void resizeEvent(QResizeEvent *event) override;
    void moveEvent(QMoveEvent *event) override;


private:
    Ui::MainWindow *ui;
    Style* style;
    QString curstyle;
    PanelRightSide* panel_right;
    PanelBottomSide* panel_bottom;
    SearchWidget *sr;
    SettingsWidget *settings;
    ParticleLifeWidget* game;
    ExportContext* exporter;
    Html* html;
    Pdf* pdf;


public:
    void Bold();
    void Italic();
    void Underline();
    void Color();
    void BackgroundColor();
};
#endif // MAINWINDOW_H
