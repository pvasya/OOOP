#include "particlelifewidget.h"
#include "ui_particlelifewidget.h"

ParticleLifeWidget::ParticleLifeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ParticleLifeWidget)
{
    ui->setupUi(this);
}

ParticleLifeWidget::~ParticleLifeWidget()
{
    delete ui;
}
