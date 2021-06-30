#include "edge/edge.hpp"

Edge::Edge()
{
    this->begin = 0;
    this->end = 0;
}

Edge::Edge(const int begin, const int end)
{
    this->begin = begin;
    this->end = end;
}

Edge::Edge(const Edge& edge)
{
    this->begin = edge.getBegin();
    this->end = edge.getEnd();
}

Edge::~Edge()
{

}

Edge& Edge::operator =(const Edge& edge)
{
    this->begin = edge.getBegin();
    this->end = edge.getEnd();
    return *this;
}

int Edge::getBegin() const
{
    return begin;
}

int Edge::getEnd() const
{
    return end;
}

void Edge::setBegin(int begin)
{
    this->begin = begin;
}

void Edge::setEnd(int end)
{
    this->end = end;
}
