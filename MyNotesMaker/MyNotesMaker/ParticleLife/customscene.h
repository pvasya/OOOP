#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CustomScene(QObject *parent = 0);
    ~CustomScene();

signals:
    void signalTargetCoordinate(QPointF point);
    void press();
    void release();

public slots:

private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    // QGraphicsScene interface
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMSCENE_H
