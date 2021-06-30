#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "points.h"

struct move
{
    int dx;
    int dy;
    int dz;
};

struct scale
{
    double kx;
    double ky;
    double kz;
};

struct turn
{
    double ox;
    double oy;
    double oz;
};

int move_point(point& dot, move coeff);
int move_points_array(point* pts, int n, move coeff);

int scale_point(point& dot, scale coeff);
int scale_points_array(point* pts, int n, scale coeff);

double d_cos(double angle);
double d_sin(double angle);

int x_turn_point(point& dot, double angle);
int y_turn_point(point& dot, double angle);
int z_turn_point(point& dot, double angle);
int rotate_points_array(point* pts, int n, turn coeff);

#endif // OPERATIONS_H
