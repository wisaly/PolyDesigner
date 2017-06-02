#include "polydesigner.h"

PolyDesigner::PolyDesigner(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.graphicsView->setRenderHints(QPainter::Antialiasing);
    ui.graphicsView->setScene(&scene_);
}

PolyDesigner::~PolyDesigner()
{

}
