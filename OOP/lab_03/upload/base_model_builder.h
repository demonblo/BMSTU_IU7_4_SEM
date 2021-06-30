#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H

#include <memory>
#include "objects/model/model.hpp"
#include "point/point.hpp"
#include "edge/edge.hpp"

class BaseModelBuilder
{
public:
    virtual void reset(char* name) = 0;
    virtual void addPoint(Point &point) = 0;
    virtual void addEdge(Edge &edge) = 0;
    virtual std::shared_ptr<Model> getResult() = 0;
private:
    std::shared_ptr<Model> model;
};

#endif // BASEMODELBUILDER_H
