#pragma once
#include <QGraphicsItem>
#include "GraphicsItemTypes.h"

class PolyVertex;
class PolyEdge : public QGraphicsItem
{
public:
    enum { Type = GraphicsItemTypes::EDGE };
    PolyEdge(PolyVertex *v1, PolyVertex *v2);
    ~PolyEdge();

    void updatePosition();
    qreal distanceTo(PolyVertex *p);
    PolyVertex *v1() { return v1_; }
    PolyVertex *v2() { return v2_; }

private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int type() const override { return Type; }

private:
    PolyVertex *v1_;
    PolyVertex *v2_;
};

