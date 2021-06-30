#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "objects/invisible_object.h"
#include "point/point.hpp"
#include "matrix/matrix_4x4.hpp"
#include "edge/const.h"

class CameraManager;

class Camera: public InvisibleObject
{
public:                                                                                                                                                                                                               friend CameraManager;
    Camera(char* name);

    std::shared_ptr<Matrix4x4> getTransformMatrix(choice) const;
    void transform(const std::shared_ptr<Matrix4x4> mtr) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    Point position;
    double x_angle;
    double y_angle;
    double z_angle;
};

#endif // CAMERA_HPP
