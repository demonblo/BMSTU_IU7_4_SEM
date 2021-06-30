#ifndef QTGRAPHFACTORY_H
#define QTGRAPHFACTORY_H

#include "draw/abstract_graph_factory.h"
#include "draw/qt_graphics.h"

class QtGraphFactory: public AbstractGraphFactory
{
public:
    virtual std::unique_ptr<BaseGraphics> createGraphics() override
    {
        return std::unique_ptr<BaseGraphics>(new QtGraphics());
    };
};

#endif // QTGRAPHFACTORY_H
