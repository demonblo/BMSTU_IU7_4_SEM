#include "objects/object_composite.hpp"

bool Composite::add(std::shared_ptr<Object> object)
{
    _objects.push_back(object);
    return true;
}

bool Composite::remove(VectorIterator<std::shared_ptr<Object>> &it)
{
    _objects.erase(it);
    return true;
}

//Vector<std::shared_ptr<Object> > Composite::getObjects()
//{
//    return _objects;
//}

bool Composite::isComposite() const
{
    return true;
}

void Composite::transform(const std::shared_ptr<Matrix4x4> matrix)
{
    int n = _objects.get_size();
    for (int i = 0; i < n; i++)
    {
        _objects[i]->transform(matrix);
    }
}

void Composite::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
    int n = _objects.get_size();
    for (int i = 0; i < n; i++)
    {
        _objects[i]->accept(visitor);
    }
}

