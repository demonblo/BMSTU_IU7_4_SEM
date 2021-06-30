#include "managers/camera_manager.hpp"

void CameraManager::rotateX(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->x_angle;
    camera->x_angle = (angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::rotateY(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->y_angle;
    camera->y_angle = (angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::rotateZ(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->z_angle;
    camera->z_angle = (angle / 180.0 * M_PI + cur_angle);
}
