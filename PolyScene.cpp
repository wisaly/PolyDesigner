#include "PolyScene.h"
#include <QGraphicsSceneMouseEvent>
#include "PolyEdge.h"

PolyScene::PolyScene()
{
}


PolyScene::~PolyScene()
{
}

void PolyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem *> mouseItems = items(event->scenePos());
    bool createVertex = true;
    for (QGraphicsItem *item : mouseItems)
    {
        if (qgraphicsitem_cast<PolyVertex*>(item))
        {
            createVertex = false;
            break;
        }
    }
    if (createVertex)
    {
        PolyVertex *vertex = new PolyVertex(event->scenePos());
        vertexes_ << vertex;
        addItem(vertex);

        if (vertexes_.count() < 3)
        {
            return;
        }
        else if (vertexes_.count() == 3)
        {
            PolyEdge *e1 = new PolyEdge(vertexes_[0], vertexes_[1]);
            PolyEdge *e2 = new PolyEdge(vertexes_[0], vertexes_[2]);
            PolyEdge *e3 = new PolyEdge(vertexes_[1], vertexes_[2]);
            edges_ << e1;
            edges_ << e2;
            edges_ << e3;
            addItem(e1);
            addItem(e2);
            addItem(e3);
            Triangle *triangle = new Triangle(vertexes_[0], vertexes_[1], vertexes_[2]);
            triangles_ << triangle;
        }
        else
        {
            bool pointInTriangle = false;
            for (Triangle *t : triangles_)
            {
                if (t->isPointIn(vertex->pos()))
                {
                    PolyEdge *e1 = new PolyEdge(t->vertex(0), vertex);
                    PolyEdge *e2 = new PolyEdge(t->vertex(1), vertex);
                    PolyEdge *e3 = new PolyEdge(t->vertex(2), vertex);
                    edges_ << e1 << e2 << e3;
                    addItem(e1);
                    addItem(e2);
                    addItem(e3);
                    Triangle *t1 = new Triangle(t->vertex(0), t->vertex(1), vertex);
                    Triangle *t2 = new Triangle(t->vertex(0), t->vertex(2), vertex);
                    Triangle *t3 = new Triangle(t->vertex(1), t->vertex(2), vertex);
                    triangles_ << t1 << t2 << t3;
                    triangles_.removeOne(t);
                    delete t;
                    pointInTriangle = true;
                    break;
                }
            }
            if (!pointInTriangle)
            {
                qreal minDistance = qInf();
                PolyEdge *minEdge = nullptr;
                for (PolyEdge *e : edges_)
                {
                    qreal d = e->distanceTo(vertex);
                    if (d < minDistance)
                    {
                        minDistance = d;
                        minEdge = e;
                    }
                }

                Q_ASSERT(minEdge);
                PolyEdge *e1 = new PolyEdge(vertex, minEdge->v1());
                PolyEdge *e2 = new PolyEdge(vertex, minEdge->v2());
                edges_ << e1 << e2;
                addItem(e1);
                addItem(e2);
                Triangle *t = new Triangle(vertex, minEdge->v1(), minEdge->v2());
                triangles_ << t;
            }
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

void PolyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);

    
}

