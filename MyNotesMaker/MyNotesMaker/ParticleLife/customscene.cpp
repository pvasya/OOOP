#include "customscene.h"

CustomScene::CustomScene(QObject *parent) :
    QGraphicsScene()
{
    Q_UNUSED(parent);
}

CustomScene::~CustomScene()
{

}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalTargetCoordinate(event->scenePos());
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit press();
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit release();
}
