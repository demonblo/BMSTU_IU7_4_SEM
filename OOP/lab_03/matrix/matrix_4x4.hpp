#ifndef MATRIX4X4_HPP
#define MATRIX4X4_HPP

#include <memory>
#include "exceptions/exceptions.h"
#include <ctime>

class Matrix4x4
{
public:
    Matrix4x4();

    ~Matrix4x4();

    void null_matrix();
    void set_elem(int i, int j, const double& value);
    double& get_elem(int i, int j);


private:
    void allocate_matrix();
    double* data;
};


#endif  // MATRIX4X4_HPP
