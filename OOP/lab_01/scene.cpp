#include "scene.h"
#include "error_codes.h"
#include "figure.h"

int init_scene(graphics &a, QGraphicsView *gV)
{
    a.scene = new QGraphicsScene(gV);
    if (!a.scene)
        return PTR_ALL_ERR;

    a.pen = QPen(Qt::white);

    return 0;
}

int del(graphics &a)
{
    delete a.scene;
    return NONE;
}

int set_scene(QGraphicsView *gV, graphics &a)
{
    QGraphicsScene *prev = gV->scene();
    delete prev;
    gV->setScene(a.scene);
    return NONE;
}

