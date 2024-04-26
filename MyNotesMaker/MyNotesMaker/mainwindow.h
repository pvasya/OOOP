/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * Програма MyNotesMaker - це зручний інструмент для створення, збереження та управління нотатками. Завдяки простому та інтуїтивно зрозумілому інтерфейсу користувача, MyNotesMaker дозволяє легко створювати нові нотатки, редагувати вже існуючі та швидко знаходити потрібну інформацію.
*\section a_sec Основні можливості програми включають:
*\subsection b_sec Створення та редагування нотаток:
Користувачі можуть створювати нові нотатки, додавати текст, форматувати його, вибирати шрифти.
*\subsection c_sec Збереження нотаток:
Усі створені нотатки зберігаються в спеціальному файлі у форматі JSON, що дозволяє зберігати інформацію у структурованому вигляді та легко обмінюватися нею.
*\subsection d_sec Управління нотатками:
Користувачі можуть швидко переглядати список створених нотаток, вибирати нотатки для відкриття та видаляти непотрібні записи.
*\subsection e_sec Налаштування програми:
Програма має набір налаштувань, що дозволяє змінювати розмір та стиль шрифту.
*\subsection f_sec Збереження нотаток:
MyNotesMaker - це ідеальний інструмент для тих, хто шукає простий, ефективний та зручний спосіб створювати та організовувати свої нотатки.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QSettings>
#include <QListWidgetItem>
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
#include "note.h"
#include "proxynotemanager.h"


#include "QSidePanel/PanelRightSide.hpp"

#include "QSidePanel/PanelBottomSide.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/*!
     * \brief Головне вікно
     */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void OpenNote();
    void DeleteNote();

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

    void saveSettings();
    void loadSettings();

    void on_noteListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_saveNoteBtn_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_saveChangesBtn_clicked();


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
    QAction* actOpen;
    QAction* actDelete;
    QSettings* settings_app;
    ProxyNoteManager* proxynotemanager;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
