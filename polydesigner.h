#ifndef POLYDESIGNER_H
#define POLYDESIGNER_H

#include <QtWidgets/QMainWindow>
#include "ui_polydesigner.h"
#include "PolyScene.h"

class PolyDesigner : public QMainWindow
{
    Q_OBJECT

public:
    PolyDesigner(QWidget *parent = 0);
    ~PolyDesigner();

private:
    Ui::PolyDesignerClass ui;
    PolyScene scene_;
};

#endif // POLYDESIGNER_H
