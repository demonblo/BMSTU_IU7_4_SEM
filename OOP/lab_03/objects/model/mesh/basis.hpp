#ifndef BASIS_HPP
#define BASIS_HPP

#include <memory>
#include "exceptions/exceptions.h"
#include "point/point.hpp"
#include "edge/edge.hpp"
#include "vector/vector.h"
#include <ctime>

class Basis
{
public:
    void addPoint(Point &point);
    void addEdge(Edge &edge);
    void transform(const std::shared_ptr<Matrix4x4> mtr);
    Vector<std::pair<Point, Point>> getLines();
private:
    Vector<Point> points;
    Vector<Edge> edges;
};

#endif
