#include "upload/model_builder.hpp"

void ModelBuilder::reset(char* name)
{
    model.reset();
    model = std::shared_ptr<Model>(new Model(name));
}

void ModelBuilder::addPoint(Point &point)
{
    model->addPoint(point);
}

void ModelBuilder::addEdge(Edge &edge)
{
    model->addEdge(edge);
}

std::shared_ptr<Model> ModelBuilder::getResult()
{
    return model;
}

