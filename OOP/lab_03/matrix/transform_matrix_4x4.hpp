#ifndef TRANSFORM_MATRIX_H
#define TRANSFORM_MATRIX_H

#include <cmath>
#include "matrix/matrix_4x4.hpp"

class MoveMatrix4x4: public Matrix4x4
{
public:
    MoveMatrix4x4(double dx, double dy, double z);
};

class ScaleMatrix4x4: public Matrix4x4
{
public:
    ScaleMatrix4x4(double x, double y, double z);
};

class RotateOxMatrix4x4: public Matrix4x4
{
public:
    RotateOxMatrix4x4(double angle);
};

class RotateOyMatrix4x4: public Matrix4x4
{
public:
    RotateOyMatrix4x4(double angle);
};

class RotateOzMatrix4x4: public Matrix4x4
{
public:
    RotateOzMatrix4x4(double angle);
};

#endif // TRANSFORM_MATRIX_H
