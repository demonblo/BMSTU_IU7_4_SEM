#ifndef QT_GRAPHICS_H
#define QT_GRAPHICS_H

#include <iostream>
#include "draw/base_graphics.h"

class QtGraphics: public BaseGraphics
{
public:
    QtGraphics(){}
    ~QtGraphics() override{}
};

#endif // QT_GRAPHICS_H
