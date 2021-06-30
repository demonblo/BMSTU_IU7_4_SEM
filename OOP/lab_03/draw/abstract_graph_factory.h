#ifndef ABSTRACT_GRAPH_FACTORY_H
#define ABSTRACT_GRAPH_FACTORY_H

#include <memory>
#include "draw/base_graphics.h"

class AbstractGraphFactory
{
public:
    virtual std::unique_ptr<BaseGraphics> createGraphics() = 0;
};

#endif // ABSTRACT_GRAPH_FACTORY_H
