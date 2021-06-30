#include "object.hpp"

Object::~Object() {}

Object::Object(char* name)
{
    this->name = name;
}

char *Object::getName()
{
    return name;
}

bool Object::isComposite() const
{
    return false;
};

bool Object::add(std::shared_ptr<Object> obj)
{
    return false;
};


bool Object::remove(VectorIterator<Object> &it)
{
    return false;
};
