#ifndef BASE_LOADER_H
#define BASE_LOADER_H

#include <string>
#include "point/point.hpp"
#include "edge/edge.hpp"

class BaseLoader
{
public:
    virtual ~BaseLoader() = default;

    virtual void open(char* source_name) = 0;
    virtual void close() = 0;
    virtual int readCountInfo() = 0;
    virtual Edge readEdgeInfo() = 0;
    virtual Point readPoint() = 0;
};

#endif // BASE_LOADER_H
