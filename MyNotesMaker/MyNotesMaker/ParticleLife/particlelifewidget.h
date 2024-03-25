#ifndef PARTICLELIFEWIDGET_H
#define PARTICLELIFEWIDGET_H

#include <QWidget>

namespace Ui {
class ParticleLifeWidget;
}

class ParticleLifeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParticleLifeWidget(QWidget *parent = nullptr);
    ~ParticleLifeWidget();

private:
    Ui::ParticleLifeWidget *ui;
};

#endif // PARTICLELIFEWIDGET_H
