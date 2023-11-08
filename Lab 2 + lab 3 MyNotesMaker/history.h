#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>

namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();

private slots:
    void on_okbtn_clicked();

    void on_deletebtn_clicked();

    void on_openbtn_clicked();

private:
    Ui::History *ui;

signals:
    void open(QString name, QString text, QFont font);
};

#endif // HISTORY_H
