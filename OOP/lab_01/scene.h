#ifndef SCENE_H
#define SCENE_H

#include "QGraphicsView"

struct graphics
{
    QGraphicsScene *scene;
    QPen pen;
};

int init_scene(graphics &a, QGraphicsView *gV);
int del(graphics &a);
int set_scene(QGraphicsView *gV, graphics &a);


#endif // SCENE_H
