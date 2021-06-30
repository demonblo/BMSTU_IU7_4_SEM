#ifndef TRANSFORMMANAGER_HPP
#define TRANSFORMMANAGER_HPP

#include "managers/manager.h"
#include "objects/object.hpp"
#include "matrix/transform_matrix_4x4.hpp"
#include <cmath>
#include <memory>

class TransformManager: public Manager
{
public:
    void moveObject(std::shared_ptr<Object> obj, int dx, int dy, int dz);
    void scaleObject(std::shared_ptr<Object> obj, double x, double y, double z);
    void rotateObjectOX(std::shared_ptr<Object> obj, double angle);
    void rotateObjectOY(std::shared_ptr<Object> obj, double angle);
    void rotateObjectOZ(std::shared_ptr<Object> obj, double angle);
private:
    double degreesToRadians(double angle);
};

#endif // TRANSFORMMANAGER_HPP
