#include "point/point.hpp"

Point::Point()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(const double x, const double y, const double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(const Point& point)
{
    this->x = point.getX();
    this->y = point.getY();
    this->z = point.getZ();
}

Point::~Point()
{

}

Point& Point::operator =(const Point& point)
{
    this->x = point.getX();
    this->y = point.getY();
    this->z = point.getZ();
    return *this;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::getZ() const
{
    return z;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::setZ(double z)
{
    this->z = z;
}

void Point::transform(const std::shared_ptr<Matrix4x4> mtr)
{
    Vector<double> result(4);
    Vector<double> data={x, y, z, 1.0};
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            result[i] += data[j] * mtr->get_elem(i, j);
        }
    }

    *this = {result[0], result[1], result[2]};
}
