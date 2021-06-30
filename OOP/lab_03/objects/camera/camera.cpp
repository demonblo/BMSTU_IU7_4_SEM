#include "camera.hpp"
#include "matrix/transform_matrix_4x4.hpp"


Camera::Camera(char *name)
{
    this->name = name;
    position = Point(0, 0, 300);
    this->x_angle = 0;
    this->y_angle = 0;
    this->z_angle = 0;
}

void Camera::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}







//void Camera::setPosition(const Point &position)
//{
//    this->position = position;
//}

//double Camera::getXAngle() const
//{
//    return x_angle;
//}

//void Camera::setXAngle(double x_angle)
//{
//    this->x_angle = x_angle;
//}

//double Camera::getYAngle() const
//{
//    return y_angle;
//}

//void Camera::setYAngle(double y_angle)
//{
//    this->y_angle = y_angle;
//}

//void Camera::setZAngle(double z_angle)
//{
//    this->z_angle = z_angle;
//}

//double Camera::getZAngle() const
//{
//    return z_angle;
//}

void Camera::transform(const std::shared_ptr<Matrix4x4> mtr)
{
    position.transform(mtr);
}

std::shared_ptr<Matrix4x4> Camera::getTransformMatrix(choice option) const {
    if (option == MOVE) {
        return std::shared_ptr<Matrix4x4>(new MoveMatrix4x4(-position.getX(), -position.getY(), 0));
    }
    else if (option == ROTX) {
        return std::shared_ptr<Matrix4x4>(new RotateOxMatrix4x4(-x_angle));
    }
    else if (option == ROTY) {
        return std::shared_ptr<Matrix4x4>(new RotateOyMatrix4x4(-y_angle));
    }
    else {
        return std::shared_ptr<Matrix4x4>(new RotateOzMatrix4x4(-z_angle));
    }
}


