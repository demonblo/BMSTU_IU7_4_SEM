#ifndef INVISIBLE_OBJECT_H
#define INVISIBLE_OBJECT_H

#include "objects/object.hpp"

class InvisibleObject : public Object
{
public:
    bool is_visible(){return false;}
};

#endif // INVISIBLE_OBJECT_H
