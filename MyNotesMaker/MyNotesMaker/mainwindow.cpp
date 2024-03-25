#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>

#include "ExportStrategy/html.h"
#include "ExportStrategy/pdf.h"
#include "QSidePanel/PanelRightSide.hpp"

#include "QSidePanel/PanelBottomSide.hpp"

#include <QTextEdit>
#include <QLabel>

#include <QScroller>
#include <QString>
#include <QColorDialog>

#include "style.h"

#include "searchwidget.h"
#include "settingswidget.h"
#include "./ParticleLife/particlelifewidget.h"


#include <QFileDialog>
#include <QTextCursor>
#include <QMessageBox>

//#include "./FormattingCommand/invoker.h"
//#include "./FormattingCommand/bold.h"

MainWindow::MainWindow(Style* st, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , style(st)
{
    ui->setupUi(this);

    game = new ParticleLifeWidget();

    ui->game->setWidgetResizable(true);

    ui->game->setWidget(game);

    // Right panel
    panel_right = new PanelRightSide(ui->main_2);

    panel_right->setOpenEasingCurve (QEasingCurve::Type::OutExpo);
    panel_right->setCloseEasingCurve(QEasingCurve::Type::InExpo);
    panel_right->setPanelSize(200);
    panel_right->init();

    settings = new SettingsWidget();

    panel_right->setWidgetResizable(true);
    panel_right->setWidget(settings);

    connect(settings, &SettingsWidget::on_aboutbtn_clicked, this, &MainWindow::on_about);


    connect(settings, &SettingsWidget::on_amoled_clicked, this, &MainWindow::on_amoled);
    connect(settings, &SettingsWidget::on_neon_clicked, this, &MainWindow::on_neon);
    connect(settings, &SettingsWidget::on_aqua_clicked, this, &MainWindow::on_aqua);
    connect(settings, &SettingsWidget::on_mac_clicked, this, &MainWindow::on_mac);
    connect(settings, &SettingsWidget::on_ubuntu_clicked, this, &MainWindow::on_ubuntu);
    connect(settings, &SettingsWidget::on_console_clicked, this, &MainWindow::on_console);
    connect(settings, &SettingsWidget::on_manjaro_clicked, this, &MainWindow::on_manjaro);
    connect(settings, &SettingsWidget::on_materialdark_clicked, this, &MainWindow::on_materialdark);
    connect(settings, &SettingsWidget::on_elegantdark_clicked, this, &MainWindow::on_elegantdark);


    // Bottom panel
    panel_bottom = new PanelBottomSide(ui->tab);
    panel_bottom->setPanelSize(180);
    panel_bottom->init();

    sr = new SearchWidget();

    panel_bottom->setWidgetResizable(true);
    panel_bottom->setWidget(sr);

    exporter = new ExportContext();

    html = new Html();
    pdf = new Pdf();

    exporter->setExport(html);

}

MainWindow::~MainWindow()
{
    delete game;
    delete sr;
    delete settings;
    delete panel_right;
    delete panel_bottom;
    delete exporter;
    delete pdf;
    delete html;
    delete ui;
}

void MainWindow::on_backBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_closebtn_clicked()
{
    close();
}



void MainWindow::on_hidebtn_clicked()
{
    showMinimized();
}


void MainWindow::on_topbtn_clicked()
{
    if (windowFlags() & Qt::WindowStaysOnTopHint) {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
        ui->topbtn->setIcon(QIcon(":/img/img/location_on_FILL0_wght400_GRAD0_opsz24.svg"));
    }
    else {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
        ui->topbtn->setIcon(QIcon(":/img/img/pin_drop_FILL0_wght400_GRAD0_opsz24.svg"));
    }
    show();
}


void MainWindow::on_fullbtn_clicked()
{
    if (windowState() & Qt::WindowMaximized) {
        ui->topbtn->setDisabled(false);
        showNormal();
        ui->fullbtn->setIcon(QIcon(":/img/img/fullscreen_FILL0_wght400_GRAD0_opsz24.svg"));
    } else {
        showMaximized();
        ui->topbtn->setDisabled(true);
        ui->fullbtn->setIcon(QIcon(":/img/img/fullscreen_exit_FILL0_wght400_GRAD0_opsz24.svg"));
    }

}

void MainWindow::on_about()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_amoled()
{
    style->setStyle("Amoled");
}

void MainWindow::on_neon()
{
    style->setStyle("NeonButtons");
}

void MainWindow::on_ubuntu()
{
    style->setStyle("Ubuntu");
}

void MainWindow::on_mac()
{
    style->setStyle("MacOS");
}

void MainWindow::on_materialdark()
{
    style->setStyle("MaterialDark");
}

void MainWindow::on_manjaro()
{
    style->setStyle("ManjaroMix");
}

void MainWindow::on_console()
{
    style->setStyle("ConsoleStyle");
}

void MainWindow::on_aqua()
{
    style->setStyle("Aqua");
}

void MainWindow::on_elegantdark()
{
    style->setStyle("ElegantDark");
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->topbtn->setDisabled(false);
    ui->fullbtn->setIcon(QIcon(":/img/img/fullscreen_FILL0_wght400_GRAD0_opsz24.svg"));
}

void MainWindow::moveEvent(QMoveEvent *event)
{
    ui->topbtn->setDisabled(false);
    ui->fullbtn->setIcon(QIcon(":/img/img/fullscreen_FILL0_wght400_GRAD0_opsz24.svg"));
}

void MainWindow::Bold() {
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();

    format = cursor.charFormat();

    if (format.fontWeight() != QFont::Bold) {
        format.setFontWeight(QFont::Bold);
    } else {
        format.setFontWeight(QFont::Normal);
    }
    cursor.mergeCharFormat(format);
}

void MainWindow::Italic() {
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();

    format = cursor.charFormat();

    if (!format.fontItalic()) {
        format.setFontItalic(true);
    } else {
        format.setFontItalic(false);
    }
    cursor.mergeCharFormat(format);
}

void MainWindow::Underline() {
    QTextCharFormat format;
    QTextCursor cursor = ui->textEdit->textCursor();

    format = cursor.charFormat();

    if (!format.fontUnderline()) {
        format.setFontUnderline(true);
    } else {
        format.setFontUnderline(false);
    }
    cursor.mergeCharFormat(format);
}

void MainWindow::Color() {
    QColorDialog dialog(this);
    dialog.setCurrentColor(ui->textEdit->textColor());
    QColor color = dialog.getColor();

    if (color.isValid()) {
        QTextCharFormat format;
        QTextCursor cursor = ui->textEdit->textCursor();
        format = cursor.charFormat();
        format.setForeground(color);
        cursor.mergeCharFormat(format);
    }
}

void MainWindow::BackgroundColor() {
    QColorDialog dialog(this);
    dialog.setCurrentColor(ui->textEdit->textBackgroundColor());
    QColor color = dialog.getColor();

    if (color.isValid()) {
        QTextCharFormat format;
        QTextCursor cursor = ui->textEdit->textCursor();
        format = cursor.charFormat();
        format.setBackground(color);
        cursor.mergeCharFormat(format);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString file;
    QString str = ui->label_13->text() + "_" + ui->label_14->text();
    if(ui->radioButton_3->isChecked())
        file = QFileDialog::getSaveFileName(this, "Зберегти як", str, "HTML файл (*.html)");
    else
        file = QFileDialog::getSaveFileName(this, "Зберегти як", str, "PDF файл (*.pdf)");

    if (file.isEmpty())
        return;

    bool flag = true;
    exporter->executeExport(flag, file, ui->textEdit->toHtml());
    if (flag)
        QMessageBox::information(this, "Успішно", "Файл успішно збережено.");
    else
        QMessageBox::information(this, "Помилка", "Файл не вдалося зберегти.");
}


void MainWindow::on_radioButton_3_clicked()
{
    exporter->setExport(html);
}


void MainWindow::on_radioButton_4_clicked()
{
    exporter->setExport(pdf);
}
