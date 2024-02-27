#include "historywindow.h"
#include "ui_history.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFont>

#include <nlohmann/json.hpp>
#include<QListWidget>

HistoryWindow::HistoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);

    QString filePath = QDir::homePath() + "/Desktop/mynotesmaker.json";
    nlohmann::json data;
    QFile existingFile(filePath);
    if (existingFile.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&existingFile);
        QString jsonString = in.readAll();
        existingFile.close();
        try {
            data = nlohmann::json::parse(jsonString.toStdString());
        } catch (const std::exception& e) {
            qWarning() << "Error parsing JSON: " << e.what();
            return;
        }
    }
    else {
        qWarning() << "Error reading the existing file.";
    }
    for (const auto& item : data) {
        if (item.contains("name")) {
            QString name = QString::fromStdString(item["name"]);
            QListWidgetItem* listItem = new QListWidgetItem(name);
            ui->listWidget->addItem(listItem);
        }
    }
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void HistoryWindow::on_okbtn_clicked()
{
    close();
}

void HistoryWindow::on_deletebtn_clicked() {
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if (selectedItem) {
        QString itemName = selectedItem->text();
        QMessageBox msgBox;

        msgBox.setText("Are you sure you want to delete the note?");
        msgBox.setGeometry(this->x(), this->y() + 50, 300, 480);
        msgBox.setStyleSheet("background-color: rgb(253, 223, 70);");
        msgBox.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
            delete selectedItem;
            QString filePath = QDir::homePath() + "/Desktop/mynotesmaker.json";
            nlohmann::json data;

            if (QFile::exists(filePath)) {
                QFile file(filePath);
                if (file.open(QFile::ReadOnly | QFile::Text)) {
                    QTextStream in(&file);
                    QString jsonString = in.readAll();
                    file.close();
                    try {
                        data = nlohmann::json::parse(jsonString.toStdString());
                    } catch (const std::exception& e) {
                        qWarning() << "Error parsing JSON: " << e.what();
                        return;
                    }

                    for (auto it = data.begin(); it != data.end(); ++it) {
                        if (QString::fromStdString(it.value()["name"]) == itemName) {
                            data.erase(it);
                            break;
                        }
                    }
                } else {
                    qWarning() << "Error";
                }
            }
            QFile file(filePath);
            if (file.open(QFile::WriteOnly | QFile::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(data.dump());
                file.close();
            } else {
                qWarning() << "ERROR saving JSON";
            }
        }
    }
}

void HistoryWindow::openNote(QListWidgetItem* selectedItem) {
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

void HistoryWindow::mousePressEvent(QMouseEvent *event){
    cur_pos = event->globalPosition().toPoint();
}

void HistoryWindow::mouseMoveEvent(QMouseEvent *event){
    new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
    move(x()+new_pos.x(), y()+new_pos.y());
    cur_pos = event->globalPosition().toPoint();
}

void HistoryWindow::on_openbtn_clicked() {
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    openNote(selectedItem);
}

void HistoryWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QListWidgetItem* selectedItem = item;
    openNote(selectedItem);
}

