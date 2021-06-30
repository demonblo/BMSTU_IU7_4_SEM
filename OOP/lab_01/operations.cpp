#include "math.h"
#include "operations.h"
#include "error_codes.h"
#include "figure.h"

int move_point(point& dot, move coeff)
{
    dot.x += coeff.dx;
    dot.y += coeff.dy;
    dot.z += coeff.dz;
    return NONE;
}

int move_points_array(point* pts, int n, move coeff)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
        move_point(pts[i], coeff);

    return err;
}


int scale_point(point& dot, scale coeff)
{
    dot.x *= coeff.kx;
    dot.y *= coeff.ky;
    dot.z *= coeff.kz;
    return NONE;
}

int scale_points_array(point* pts, int n, scale coeff)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
        scale_point(pts[i], coeff);

    return err;
}


double d_cos(double angle)
{
    return cos(angle * 3.1415 / 180);
}

double d_sin(double angle)
{
    return sin(angle * 3.1415 / 180);
}

int  x_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double temp_1, temp_2;

    temp_1 = dot.y * cos_ang + dot.z * sin_ang;
    temp_2 = -dot.y * sin_ang + dot.z * cos_ang;

    dot.y = temp_1;
    dot.z = temp_2;
    return NONE;
}

int y_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double temp_1, temp_2;

    temp_1 = dot.x * cos_ang + dot.z * sin_ang;
    temp_2 = -dot.x * sin_ang + dot.z * cos_ang;

    dot.x = temp_1;
    dot.z = temp_2;
    return NONE;
}

int z_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double temp_1, temp_2;

    temp_1 = dot.x * cos_ang + dot.y * sin_ang;
    temp_2 = -dot.x * sin_ang + dot.y * cos_ang;

    dot.x = temp_1;
    dot.y = temp_2;
    return NONE;
}


int rotate_points_array(point* pts, int n, turn coeff)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
    {
        x_turn_point(pts[i], coeff.ox);
        y_turn_point(pts[i], coeff.oy);
        z_turn_point(pts[i], coeff.oz);
    }

    return err;
}
