#pragma once
#include <QGraphicsScene>
#include <QList>
#include "PolyVertex.h"
#include "PolyEdge.h"
#include "Triangle.h"

class PolyScene : public QGraphicsScene
{
public:
    PolyScene();
    ~PolyScene();

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QList<PolyVertex *> vertexes_;
    QList<PolyEdge *> edges_;
    QList<Triangle *> triangles_;
};

