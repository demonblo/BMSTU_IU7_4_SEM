#ifndef MODEL_HPP
#define MODEL_HPP

#include "objects/visible_object.h"
#include "point/point.hpp"
#include "edge/edge.hpp"
#include "matrix/matrix_4x4.hpp"
#include <vector>
#include "mesh/basis.hpp"

                                                                                                                                                                               class RenderManager;
class Model: public VisibleObject
{
public:                                                                                                                                                                                           friend RenderManager;
    Model(char *name);

    void addPoint(Point &point);
    void addEdge(Edge &edge);

    void transform(const std::shared_ptr<Matrix4x4> mtr) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    std::shared_ptr<Basis> Basis;
};


#endif // MODEL_HPP
