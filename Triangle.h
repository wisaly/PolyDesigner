#pragma once
#include <QGraphicsItem>
#include "PolyVertex.h"

class Triangle// : public QGraphicsItem
{
public:
    Triangle(PolyVertex *v1, PolyVertex *v2, PolyVertex *v3);
    ~Triangle();

    bool isPointIn(QPointF p);
    PolyVertex *vertex(int index);

private:
    PolyVertex *vertexes_[3];
};

