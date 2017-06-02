#pragma once
#include <QGraphicsItem>
#include "GraphicsItemTypes.h"

class PolyEdge;
class PolyVertex : public QGraphicsItem
{
public:
    enum {Type = GraphicsItemTypes::VERTEX};
    PolyVertex(QPointF pos);
    ~PolyVertex();
    void addEdge(PolyEdge *edge);

private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    int type() const override { return Type; }

    const int radius_ = 5;

private:
    QList<PolyEdge *> edges_;
};

