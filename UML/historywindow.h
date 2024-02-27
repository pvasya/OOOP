#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QDialog>
#include<QListWidget>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class History;
}

class HistoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = nullptr);
    ~HistoryWindow();

private slots:
    /*!
     * \brief Закриття вікна історії нотаток
     */
    void on_okbtn_clicked();
    /*!
     * \brief Видалення вибраного нотатка
     */
    void on_deletebtn_clicked();
    /*!
     * \brief Відкриття вибраного нотатка кнопкою Open
     */
    void on_openbtn_clicked();
    /*!
     * \brief Відкриття вибраного нотатка подвійним натисненням лівої кнопки миші
     */
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::History *ui;
    /*!
     * @brief Відкриття вибраного нотатка
     * @code
     * void HistoryWindow::openNote(QListWidgetItem* selectedItem) {
            if (selectedItem) {
                QString itemName = selectedItem->text();

                nlohmann::json data;
                QString filePath = QDir::homePath() + "/Desktop/mynotesmaker.json";

                if (QFile::exists(filePath)) {
                    QFile existingFile(filePath);
                    if (existingFile.open(QFile::ReadOnly | QFile::Text)) {
                        QTextStream in(&existingFile);
                        QString jsonString = in.readAll();
                        existingFile.close();
                        try {
                            data = nlohmann::json::parse(jsonString.toStdString());
                        } catch (const std::exception& e) {
                            qWarning() << "Error parsing JSON: " << e.what();
                        }
                        for (const auto& item : data) {
                            if (QString::fromStdString(item["name"]) == itemName) {
                                QString name = QString::fromStdString(item["name"]);
                                QString text = QString::fromStdString(item["text"]);
                                QString fontString = QString::fromStdString(item["font"]);
                                QFont font;
                                font.fromString(fontString);
                                emit open(name,text,font);
                                close();
                                break;
                            }
                        }
                    } else {
                        qWarning() << "Error";
                    }
                }
            }
    }
     * @endcode
     */
    void openNote(QListWidgetItem* selectedItem);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QPoint cur_pos;
    QPoint new_pos;

signals:
    void open(QString name, QString text, QFont font);
};

#endif // HISTORYWINDOW_H
