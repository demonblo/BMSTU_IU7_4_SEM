#ifndef EDGE_HPP
#define EDGE_HPP

#include <memory>

class Edge
{
public:
    Edge();
    Edge(const int begin, const int end);
    explicit Edge(const Edge& edge);

    ~Edge();

    Edge& operator =(const Edge& edge);

    int getBegin() const;
    int getEnd() const;

    void setBegin(int begin);
    void setEnd(int end);

private:
    int begin;
    int end;
};

#endif  // EDGE_HPP
