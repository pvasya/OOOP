#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>

namespace Ui {
class SearchWidget;
}

class SearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWidget(QWidget *parent = nullptr);
    ~SearchWidget();

private slots:

    void on_replaceAllBtn_clicked();

    void on_replaceBtn_clicked();

    void on_searchBtn_clicked();

    void on_boldBtn_clicked();

    void on_italicBtn_clicked();

    void on_underlineBtn_clicked();

    void on_colorBtn_clicked();

    void on_backgroundColorBtn_clicked();

    void on_swapBtn_clicked();

signals:
    void find(QString text);
    void replace(QString text, QString replaceText);
    void replaceAll(QString text, QString replaceText);

private:
    Ui::SearchWidget *ui;

};

#endif // SEARCHWIDGET_H
