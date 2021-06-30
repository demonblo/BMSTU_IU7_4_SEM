#include "matrix/transform_matrix_4x4.hpp"


MoveMatrix4x4::MoveMatrix4x4(double dx, double dy, double dz)
{
    set_elem(0,0,1);
    set_elem(1,1,1);
    set_elem(2,2,1);
    set_elem(3,3,1);
    set_elem(0,3,dx);
    set_elem(1,3,dy);
    set_elem(2,3,dz);
}

ScaleMatrix4x4::ScaleMatrix4x4(double kx, double ky, double kz)
{
    set_elem(0,0,kx);
    set_elem(1,1,ky);
    set_elem(2,2,kz);
    set_elem(3,3,1);
}

RotateOxMatrix4x4::RotateOxMatrix4x4(double angle)
{
    set_elem(0,0,1);
    set_elem(1,1,cos(angle));
    set_elem(1,2,-sin(angle));
    set_elem(2,1,sin(angle));
    set_elem(2,2,cos(angle));
    set_elem(3,3,1);
}

RotateOyMatrix4x4::RotateOyMatrix4x4(double angle)
{
    set_elem(0,0,cos(angle));
    set_elem(1,1,1);
    set_elem(2,0,-sin(angle));
    set_elem(0,2,sin(angle));
    set_elem(2,2,cos(angle));
    set_elem(3,3,1);
}

RotateOzMatrix4x4::RotateOzMatrix4x4(double angle)
{
    set_elem(0,0,cos(angle));
    set_elem(0,1,-sin(angle));
    set_elem(1,0,sin(angle));
    set_elem(1,1,cos(angle));
    set_elem(2,2,1);
    set_elem(3,3,1);
}

