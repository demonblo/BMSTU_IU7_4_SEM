#include "transform_manager.hpp"

void TransformManager::moveObject(std::shared_ptr<Object> obj, int dx, int dy, int dz)
{
    std::shared_ptr<Matrix4x4> transform_matrix(new MoveMatrix4x4(dx, dy, dz));
    obj->transform(transform_matrix);
}

void TransformManager::scaleObject(std::shared_ptr<Object> obj, double kx, double ky, double kz)
{
    std::shared_ptr<Matrix4x4> transform_matrix(new ScaleMatrix4x4(kx, ky, kz));
    obj->transform(transform_matrix);
}


void TransformManager::rotateObjectOX(std::shared_ptr<Object> obj, double angle)
{
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix4x4> transform_matrix(new RotateOxMatrix4x4(angle));
    obj->transform(transform_matrix);
}

void TransformManager::rotateObjectOY(std::shared_ptr<Object> obj, double angle)
{
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix4x4> transform_matrix(new RotateOyMatrix4x4(angle));
    obj->transform(transform_matrix);
}

void TransformManager::rotateObjectOZ(std::shared_ptr<Object> obj, double angle)
{
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix4x4> transform_matrix(new RotateOzMatrix4x4(angle));
    obj->transform(transform_matrix);
}

double TransformManager::degreesToRadians(double angle)
{
    return angle / 180. * 3.1415926535;
}
