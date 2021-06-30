#ifndef RENDERMANAGER_HPP
#define RENDERMANAGER_HPP

#include "managers/manager.h"
#include "draw/base_drawer.h"
#include "objects/model/model.hpp"
#include "objects/camera/camera.hpp"
#include "point/point.hpp"
#include "matrix/transform_matrix_4x4.hpp"
#include "exceptions/exceptions.h"
#include "visitor/visitor.h"
#include <ctime>
#include <cmath>
#include <memory>
#include "vector/vector.h"

class RenderManager: public Manager, public Visitor
{
public:
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);
    void setCamera(std::shared_ptr<Camera> camera);
    void visit(Model &model) override;
    void visit(Camera &model) override;
    void visit(Composite &model) override;

private:
    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<Camera> camera;
    void proectPoint(Point &point);
};

#endif // RENDERMANAGER_HPP
