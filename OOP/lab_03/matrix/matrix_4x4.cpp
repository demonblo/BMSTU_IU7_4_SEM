#include "matrix/matrix_4x4.hpp"

Matrix4x4::Matrix4x4()
{
    this->allocate_matrix();
    this->null_matrix();
}

Matrix4x4::~Matrix4x4()
{
    delete[]data;
}

double& Matrix4x4::get_elem(int i, int j)
{
    return data[i * 4 + j];
}

void Matrix4x4::null_matrix()
{
    for (int i = 0; i<16; i++)
        data[i] = 0;
}

void Matrix4x4::set_elem(int i, int j, const double& value)
{
    data[i * 4 + j] = value;
}

void Matrix4x4::allocate_matrix()
{
    time_t t_time = time(NULL);
    data = new double[16];
    if (data == nullptr)
        throw ErrorAllocMemmory(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
}
