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
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    /*!
     * \brief Закриття програми
     */
    void on_closebtn_clicked();
    /*!
     * \brief Відкриття налаштувань програми
     */
    void on_settingsbtn_clicked();
    /*!
     * \brief Відкриття історії нотатків
     */
    void on_historbtn_clicked();
    /*!
     * \brief Зміна шрифту
     */
    void on_toolsbtn_clicked();
    /*!
     * \brief Відкриття нового вікна програми
     */
    void on_newbtn_clicked();
    /*!
     * \brief Приховати вікно програми
     */
    void on_hidebtn_clicked();
    /*!
     * \brief Закріпити вікно програми
     */
    void on_pinbtn_clicked();
    /*!
     * \brief Зберегти нотатку
     */
    void on_savebtn_clicked();

    /*!
     * \brief Запит до OpenAI, очікується відповідь на запит
     */
    void on_gptbtn_1_clicked();

    /*!
     * \brief Запит до OpenAI,
     * очікується поліпшення тексту введеного нотатка
     */
    void on_gptbtn_2_clicked();

public slots:
    void slot(QString name, QString text, QFont font);

private:
    Ui::MainWindow *ui;

    /*!
     * @brief Запит до OpenAI
     * @param text - текст введений користувачем
     * @param key - OpenAI ключ
     * @code
     * void MainWindow::gpt(QString text, QString key){
            openai::start(key.toStdString());
            std::string req = text.toStdString() + ui->plainTextEdit->toPlainText().toStdString();
            nlohmann::json jsonRequest;
            QSettings settings(QDir::homePath()+ "/Desktop/mynotesmaker settings.ini", QSettings::IniFormat);
            jsonRequest["model"] = settings.value("GPT version", QString("gpt-3.5-turbo")).toString().toStdString();
            jsonRequest["messages"] = {
                {{"role", "user"}, {"content", req}}
            };
            jsonRequest["max_tokens"] = 300;
            jsonRequest["temperature"] = 0;
            auto chat = openai::chat().create(jsonRequest);
            ui->plainTextEdit->setPlainText(QString::fromStdString(chat["choices"][0]["message"]["content"].get<std::string>()));
        }
     * @endcode
     */
    void gpt(QString text, QString key);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QPoint cur_pos;
    QPoint new_pos;
};

#endif // MAINWINDOW_H
