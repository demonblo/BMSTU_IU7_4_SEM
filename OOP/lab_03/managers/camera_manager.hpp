#ifndef CAMERA_MANAGER_HPP
#define CAMERA_MANAGER_HPP

#include "managers/manager.h"
#include "objects/camera/camera.hpp"
#include <math.h>


class CameraManager: public Manager
{
public:
    void rotateX(std::shared_ptr<Camera> camera, double angle);
    void rotateY(std::shared_ptr<Camera> camera, double angle);
    void rotateZ(std::shared_ptr<Camera> camera, double angle);
};


#endif // CAMERA_MANAGER_HPP
