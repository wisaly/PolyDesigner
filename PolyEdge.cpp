#include "PolyEdge.h"
#include <QPainter>
#include <QVector2D>
#include "PolyVertex.h"

PolyEdge::PolyEdge(PolyVertex *v1, PolyVertex *v2):
v1_(v1), v2_(v2)
{
    v1_->addEdge(this);
    v2_->addEdge(this);
}


PolyEdge::~PolyEdge()
{
}

QRectF PolyEdge::boundingRect() const
{
    qreal l, r, t, b;
    if (v1_->pos().x() < v2_->pos().x())
    {
        l = v1_->pos().x();
        r = v2_->pos().x();
    }
    else
    {
        l = v2_->pos().x();
        r = v1_->pos().x();
    }
    if (v1_->pos().y() < v2_->pos().y())
    {
        t = v1_->pos().y();
        b = v2_->pos().y();
    }
    else
    {
        t = v2_->pos().y();
        b = v1_->pos().y();
    }

    return QRectF(QPointF(l, t), QPointF(r, b));
}

void PolyEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(v1_->pos(), v2_->pos());
}

void PolyEdge::updatePosition()
{
    prepareGeometryChange();
    update();
}

qreal PolyEdge::distanceTo(PolyVertex *p)
{
    QVector2D v(v1_->pos() - v2_->pos());
    return v.distanceToPoint(QVector2D(p->pos()));
}
