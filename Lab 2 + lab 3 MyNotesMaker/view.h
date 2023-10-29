#ifndef VIEW_H
#define VIEW_H

#include <QDialog>

namespace Ui {
class View;
}

class View : public QDialog
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

private slots:
    void on_cancel_clicked();

private:
    Ui::View *ui;
};

#endif // VIEW_H
