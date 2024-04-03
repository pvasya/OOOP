#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ExportStrategy/exportcontext.h"
#include "ExportStrategy/html.h"
#include "ExportStrategy/pdf.h"
#include "FormattingCommand/backgroundcolor.h"
#include "FormattingCommand/bold.h"
#include "FormattingCommand/color.h"
#include "FormattingCommand/formatter.h"
#include "FormattingCommand/italic.h"
#include "FormattingCommand/underline.h"
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
    MainWindow(QWidget *parent = nullptr);
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

    void find(QString text);
    void replace(QString text, QString replaceText);
    void replaceAll(QString text, QString replaceText);


    void on_exportBtn_clicked();

    void on_htmlRadioBtn_clicked();

    void on_pdfRadioBtn_clicked();


protected:
    void resizeEvent(QResizeEvent *event) override;
    void moveEvent(QMoveEvent *event) override;


private:
    Ui::MainWindow *ui;
    QString curstyle;
    PanelRightSide* panel_right;
    PanelBottomSide* panel_bottom;
    SearchWidget *sr;
    SettingsWidget *settings;
    ParticleLifeWidget* game;
    ExportContext* exporter;
    Html* html;
    Pdf* pdf;
    Bold* b;
    Italic* i;
    Underline* u;
    Color* c;
    BackgroundColor* bc;
    Formatter* formatter;

};
#endif // MAINWINDOW_H
