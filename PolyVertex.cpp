#include "PolyVertex.h"
#include <QPainter>
#include "PolyEdge.h"

PolyVertex::PolyVertex(QPointF pos)
{
    setPos(pos);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}


PolyVertex::~PolyVertex()
{
}

QRectF PolyVertex::boundingRect() const
{
    return QRectF(-radius_, -radius_, radius_ * 2, radius_ * 2);
}

void PolyVertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(QPointF(0, 0), radius_, radius_);
}

void PolyVertex::addEdge(PolyEdge *edge)
{
    edges_ << edge;
}

QVariant PolyVertex::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange)
    {
        for (PolyEdge *e : edges_)
            e->updatePosition();
    }
    return value;
}
