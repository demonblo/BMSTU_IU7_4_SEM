#ifndef BASE_DRAWER_H
#define BASE_DRAWER_H

#include "point/point.hpp"
#include "abstract_graph_factory.h"

class BaseDrawer
{
private:
    std::shared_ptr<AbstractGraphFactory> factory;
public:
    virtual ~BaseDrawer() = default;
    virtual void drawLine(const Point &p1, const Point &p2) = 0;
    void setFactory(std::shared_ptr<AbstractGraphFactory> _factory)
    {
        factory = _factory;
    }
};

#endif  // BASE_DRAWER_H
