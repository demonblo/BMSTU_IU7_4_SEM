#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>
#include <string>
#include "matrix/matrix_4x4.hpp"
#include "visitor/visitor.h"
#include "vector/vector_iterator.hpp"

class Object
{
public:

    Object() = default;
    Object(char *name);
    virtual ~Object() = 0;

    virtual bool isComposite() const;
    virtual bool add(std::shared_ptr<Object> obj);
    virtual bool remove(VectorIterator<Object> &it);
    virtual void transform(const std::shared_ptr<Matrix4x4>) = 0;
    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
    typedef VectorIterator<std::shared_ptr<Object>> ObjIter;
    virtual ObjIter begin() { return ObjIter(); }
    virtual ObjIter end() { return ObjIter(); }

    char *getName();

protected:
    char *name;
};


#endif // OBJECT_HPP
