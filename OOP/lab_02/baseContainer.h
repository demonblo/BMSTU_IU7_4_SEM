#ifndef UNTITLED72_BASECONTAINER_H
#define UNTITLED72_BASECONTAINER_H

#include "iostream"

class baseContainer {
public:
    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;
    virtual size_t size() const = 0;
    virtual ~baseContainer() = default;
};

#endif //UNTITLED72_BASECONTAINER_H
