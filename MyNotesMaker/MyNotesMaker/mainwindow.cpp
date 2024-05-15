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

    settings_app = new QSettings("MyNotesMaker", "MyNotesMaker", this);

    loadSettings();

    actOpen = new QAction("Open", this);
    actDelete = new QAction("Delete", this);

    connect(actOpen, &QAction::triggered, this, &MainWindow::OpenNote);
    connect(actDelete, &QAction::triggered, this, &MainWindow::DeleteNote);
    connect(ui->noteListWidget->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::updateContextMenu);


    ui->noteListWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->noteListWidget->addActions({ actOpen, actDelete });

    proxynotemanager = new ProxyNoteManager();

    proxynotemanager->load();
}

MainWindow::~MainWindow()
{
    proxynotemanager->save();
    saveSettings();

    delete game;
    delete sr;
    delete settings;
    delete panel_right;
    delete panel_bottom;
    delete proxynotemanager;
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

void MainWindow::updateContextMenu() {
    QList<QListWidgetItem*> selectedItems = ui->noteListWidget->selectedItems();
    if (selectedItems.size() > 1) {
        actOpen->setVisible(false);
        actDelete->setVisible(true);
    } else {
        actOpen->setVisible(true);
        actDelete->setVisible(true);
    }
}

void MainWindow::on_about()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_amoled()
{
    Style::get().setStyleName("Amoled");

}

void MainWindow::on_neon()
{
    Style::get().setStyleName("NeonButtons");
}

void MainWindow::on_ubuntu()
{
    Style::get().setStyleName("Ubuntu");
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
    Style::get().setStyleName("MacOS");
}

void MainWindow::on_materialdark()
{
    Style::get().setStyleName("MaterialDark");
}

void MainWindow::on_manjaro()
{
    Style::get().setStyleName("ManjaroMix");
}

void MainWindow::on_console()
{
    Style::get().setStyleName("ConsoleStyle");
}

void MainWindow::on_aqua()
{
    Style::get().setStyleName("Aqua");
}

void MainWindow::on_elegantdark()
{
    Style::get().setStyleName("ElegantDark");
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F && event->modifiers() == Qt::AltModifier) {
        if (isFullScreen()) {
            showNormal();
        } else {
            showFullScreen();
        }
        event->accept();
    } else {
        QMainWindow::keyPressEvent(event);
    }
}


void MainWindow::on_exportBtn_clicked()
{
    if (ui->nameLabel->text()=="") {
        QMessageBox::information(this, "Information", "Open a note");
        return;
    }
    QString file;
    QString str = (ui->nameLabel->text() + "_" + ui->dateLabel->text()).replace(":", "-");;
    if(ui->htmlRadioBtn->isChecked())
        file = QFileDialog::getSaveFileName(this, "Save as", str, "HTML file (*.html)");
    else if (ui->pdfRadioBtn->isChecked())
        file = QFileDialog::getSaveFileName(this, "Save as", str, "PDF file (*.pdf)");

    if (file.isEmpty())
        return;


    Note noteData = proxynotemanager->getNote(ui->nameLabel->text());
    QString noteText = noteData.getText();


    bool is_successful= exporter->executeExport(file, noteText);

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

void MainWindow::saveSettings()
{
    settings_app->setValue("style", Style::get().getStyleName());
    settings_app->setValue("geometry", geometry());
}

void MainWindow::loadSettings()
{
    Style::get().setStyleName(settings_app->value("style","Aqua").toString());
    setGeometry(settings_app->value("geometry",QRect(500,500,280,300)).toRect());
}


void MainWindow::on_noteListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString title = item->text();
    Note note = proxynotemanager->getNote(title);

    ui->textEdit->setHtml(note.getText());
    ui->nameLabel->setText(title);
    ui->dateLabel->setText(note.getDateTime());
    ui->dateLabel->setToolTip(note.getDateTime());

    ui->tabWidget->setCurrentIndex(0);
}



void MainWindow::on_saveNoteBtn_clicked()
{
    QString title = ui->titleLineEdit->text().trimmed().simplified();
    QString text = ui->textEdit->toHtml();

    if (!title.isEmpty()) {

        if (!proxynotemanager->isExist(title)) {
            QString currentDateTime = QDateTime::currentDateTime().toString(Qt::ISODate);
            proxynotemanager->saveNote(title, text, currentDateTime);
            ui->nameLabel->setText(title);
            ui->dateLabel->setText(currentDateTime);
            ui->dateLabel->setToolTip(currentDateTime);
            QMessageBox::information(this, "Success", "The note saved.");
            ui->titleLineEdit->clear();

            QListWidgetItem *item = new QListWidgetItem(title);
            item->setData(Qt::UserRole, text);

            ui->noteListWidget->insertItem(0, item);

            QString date = QDateTime::currentDateTime().toString(Qt::ISODate);
            item->setToolTip(date);

        } else {
            QMessageBox::warning(this, "Note Exists", "A note with this title already exists!");
        }
    } else {
        QMessageBox::warning(this, "Empty Title", "The title cannot be empty!");
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 3){
        int proxyNoteCount = proxynotemanager->getLength();
        int listWidgetCount = ui->noteListWidget->count();

        if (proxyNoteCount > listWidgetCount) {
            for (int i = listWidgetCount; i < proxyNoteCount; ++i) {
                Note noteData = proxynotemanager->getNote(i);

                QListWidgetItem *item = new QListWidgetItem(noteData.getTitle());
                item->setData(Qt::UserRole, noteData.getDateTime());
                ui->noteListWidget->addItem(item);

                item->setToolTip(noteData.getDateTime());
            }
        }
    }
}

void MainWindow::on_saveChangesBtn_clicked()
{
    QString title = ui->nameLabel->text();
    QString text = ui->textEdit->toHtml();
    if(proxynotemanager->isExist(title)){
        proxynotemanager->changeNote(title, text);
        QMessageBox::information(this, "Success", "Changes saved.");
    }
}

void MainWindow::OpenNote()
{
    QListWidgetItem* item = ui->noteListWidget->currentItem();
    if (!item) {
        return;
    }

    QString title = item->text();
    Note note = proxynotemanager->getNote(title);

    ui->textEdit->setHtml(note.getText());
    ui->nameLabel->setText(title);
    ui->dateLabel->setText(note.getDateTime());
    ui->dateLabel->setToolTip(note.getDateTime());

    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::DeleteNote()
{
    QList<QListWidgetItem*> selectedItems = ui->noteListWidget->selectedItems();
    int selectedCount = selectedItems.size();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Note", QString("Are you sure you want to delete %1 selected note(s)?").arg(selectedCount), QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    for (QListWidgetItem* selectedItem : selectedItems) {
        QString title = selectedItem->text();
        proxynotemanager->deleteNote(title);
        int row = ui->noteListWidget->row(selectedItem);
        delete ui->noteListWidget->takeItem(row);
    }

    ui->textEdit->clear();
    ui->nameLabel->clear();
    ui->dateLabel->setText("Unsaved");
}
