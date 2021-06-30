#ifndef VISIBLE_OBJECT_H
#define VISIBLE_OBJECT_H

#include "objects/object.hpp"

class VisibleObject : public Object
{
public:
    bool is_visible(){return true;}
};

#endif // VISIBLE_OBJECT_H
