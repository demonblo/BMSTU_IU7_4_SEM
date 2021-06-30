#include "model.hpp"

Model::Model(char *name): Basis(new class Basis)
{
    this->name = name;
}

void Model::addPoint(Point &point)
{
    Basis->addPoint(point);
}

void Model::addEdge(Edge &edge)
{
    Basis->addEdge(edge);
}

void Model::transform(const std::shared_ptr<Matrix4x4> mtr)
{
    Basis->transform(mtr);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}

//std::shared_ptr<Basis> Model::getBasis()
//{
//    return Basis;
//}
