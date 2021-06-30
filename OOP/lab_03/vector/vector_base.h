#ifndef VECTOR_BASE_H
#define VECTOR_BASE_H

#include <cstdlib>

class VectorBase
{
public:
    virtual void clear() = 0;
    virtual bool is_empty() const = 0;
    virtual size_t get_size() const = 0;
};

#endif // VECTOR_BASE_H
