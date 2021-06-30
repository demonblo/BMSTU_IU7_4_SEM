#ifndef DRAW_H
#define DRAW_H
#include "QGraphicsView"
#include "scene.h"
#include "points.h"
#include "links.h"

struct draw
{
    QGraphicsView *gV;
    int w;
    int h;
};

struct coord_point
{
    double x;
    double y;
};

coord_point get_dot(point* dots, int n);
coord_point point_transform(coord_point dot, draw arg);
int draw_links(points_data pts, links_data links, draw arg, graphics a);
int draw_line(coord_point p1, coord_point p2, graphics a, draw arg);
int my_addLine(graphics a, double x1, double x2, double y1, double y2);

#endif // DRAW_H
