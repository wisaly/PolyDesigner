#include "Triangle.h"
#define CROSS_PRODUCT(v1,v2) (v1.x() * v2.y() - v1.y() * v2.x())

Triangle::Triangle(PolyVertex *v1, PolyVertex *v2, PolyVertex *v3)
{
    vertexes_[0] = v1;
    vertexes_[1] = v2;
    vertexes_[2] = v3;
}


Triangle::~Triangle()
{
}

bool Triangle::isPointIn(QPointF p)
{
    QPointF ab = vertexes_[1]->pos() - vertexes_[0]->pos();
    QPointF ac = vertexes_[2]->pos() - vertexes_[0]->pos();
    QPointF ap = p - vertexes_[0]->pos();

    qreal abc = CROSS_PRODUCT(ab, ac);
    qreal abp = CROSS_PRODUCT(ab, ap);
    qreal apc = CROSS_PRODUCT(ap, ac);
    qreal pbc = abc - abp - apc;
    if (abc < 0)
    {
        abp = -abp;
        apc = -apc;
        pbc = -pbc;
    }
    return abp >= 0 && apc >= 0 && pbc >= 0;
}

PolyVertex * Triangle::vertex(int index)
{
    Q_ASSERT(index >= 0 && index < 3);
    return vertexes_[index];
}
