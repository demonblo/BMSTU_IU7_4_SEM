#ifndef POINT_HPP
#define POINT_HPP

#include <memory>
#include "vector/vector.h"
#include "matrix/matrix_4x4.hpp"

class Point
{
public:
    Point();
    Point(const double x, const double y, const double z);
    explicit Point(const Point& point);

    ~Point();

    Point& operator =(const Point& point);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void transform(const std::shared_ptr<Matrix4x4> mtr);

private:
    double x;
    double y;
    double z;
};

#endif  // POINT_HPP
