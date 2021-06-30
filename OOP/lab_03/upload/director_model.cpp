#include "upload/director_model.hpp"

std::shared_ptr<Model> DirectorModel::build_model(Vector<Point> &points, Vector<Edge> &edges)
{
    int count = points.get_size();
    for (int i = 0; i < count; i++)
        builder->addPoint(points[i]);

    count = edges.get_size();
    for (int i = 0; i < count; i++)
        builder->addEdge(edges[i]);

    return builder->getResult();
}

void DirectorModel::setBuilder(std::shared_ptr<BaseModelBuilder> builder)
{
    this->builder= builder;
};
