#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>

#include "ExportStrategy/html.h"
#include "ExportStrategy/pdf.h"
#include "FormattingCommand/backgroundcolor.h"
#include "FormattingCommand/bold.h"
#include "FormattingCommand/color.h"
#include "FormattingCommand/italic.h"
#include "FormattingCommand/invoker.h"
#include "FormattingCommand/underline.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

    connect(sr, &SearchWidget::find, this, &MainWindow::find);
    connect(sr, &SearchWidget::replace, this, &MainWindow::replace);
    connect(sr, &SearchWidget::replaceAll, this, &MainWindow::replaceAll);

    panel_bottom->setWidgetResizable(true);
    panel_bottom->setWidget(sr);

    exporter = new ExportContext();

    html = new Html();
    pdf = new Pdf();

    exporter->setExport(html);


    // Command Pattern
    formatter = new Formatter(/*this,*/ *ui->textEdit);
    b = new Bold(*formatter);
    i = new Italic(*formatter);
    u = new Underline(*formatter);
    c = new Color(*formatter);
    bc = new BackgroundColor(*formatter);

    Invoker::get().addCommand(b);
    Invoker::get().addCommand(i);
    Invoker::get().addCommand(u);
    Invoker::get().addCommand(c);
    Invoker::get().addCommand(bc);

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
    Style::get().setStyle("Amoled");

}

void MainWindow::on_neon()
{
    Style::get().setStyle("NeonButtons");
}

void MainWindow::on_ubuntu()
{
    Style::get().setStyle("Ubuntu");
}

void MainWindow::find(QString text) {
    QTextCursor currentCursor = ui->textEdit->textCursor();
    QTextCursor cursor(ui->textEdit->document());

    QList<QTextCursor> occurrences;
    cursor = ui->textEdit->document()->find(text);
    while (!cursor.isNull() && !cursor.atEnd()+1) {
        occurrences.append(cursor);
        cursor = ui->textEdit->document()->find(text, cursor);
    }

    if (!occurrences.isEmpty()) {
        bool foundCurrentCursor = false;
        for (const QTextCursor& foundCursor : occurrences) {
            if (foundCursor.position() == currentCursor.position()) {
                foundCurrentCursor = true;
                continue;
            }
            if (foundCurrentCursor) {
                ui->textEdit->setTextCursor(foundCursor);
                return;
            }
        }
        ui->textEdit->setTextCursor(occurrences.first());
    }
}

void MainWindow::replace(QString text, QString replaceText) {
    QTextCursor cursor = ui->textEdit->textCursor();
    QString documentText = ui->textEdit->toPlainText();
    int position = cursor.position()-text.length();

    int index = documentText.indexOf(text, position);

    if (index != -1) {
        cursor.setPosition(index);
        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, text.length());
        cursor.removeSelectedText();
        cursor.insertText(replaceText);
    } else {
        index = documentText.indexOf(text);

        if (index != -1) {
            cursor.setPosition(index);
            cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, text.length());
            cursor.removeSelectedText();
            cursor.insertText(replaceText);
        }
    }
}

void MainWindow::replaceAll(QString text, QString replaceText)
{
    QTextCursor cursor(ui->textEdit->document());

    cursor.movePosition(QTextCursor::Start);

    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = ui->textEdit->document()->find(text, cursor);

        if (!cursor.isNull()) {
            cursor.insertText(replaceText);
        }
    }
}


void MainWindow::on_mac()
{
    Style::get().setStyle("MacOS");
}

void MainWindow::on_materialdark()
{
    Style::get().setStyle("MaterialDark");
}

void MainWindow::on_manjaro()
{
    Style::get().setStyle("ManjaroMix");
}

void MainWindow::on_console()
{
    Style::get().setStyle("ConsoleStyle");
}

void MainWindow::on_aqua()
{
    Style::get().setStyle("Aqua");
}

void MainWindow::on_elegantdark()
{
    Style::get().setStyle("ElegantDark");
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


void MainWindow::on_exportBtn_clicked()
{
    QString file;
    QString str = ui->nameLabel->text() + "_" + ui->dateLabel->text();
    if(ui->htmlRadioBtn->isChecked())
        file = QFileDialog::getSaveFileName(this, "Save as", str, "HTML file (*.html)");
    else if (ui->pdfRadioBtn->isChecked())
        file = QFileDialog::getSaveFileName(this, "Save as", str, "PDF file (*.pdf)");

    if (file.isEmpty())
        return;

    bool is_successful= exporter->executeExport(file, ui->textEdit->toHtml());

    if (is_successful)
        QMessageBox::information(this, "Successful", "File saved successfully.");
    else
        QMessageBox::information(this, "Unsuccessful", "The file could not be saved.");
}


void MainWindow::on_htmlRadioBtn_clicked()
{
    exporter->setExport(html);
}


void MainWindow::on_pdfRadioBtn_clicked()
{
    exporter->setExport(pdf);
}

