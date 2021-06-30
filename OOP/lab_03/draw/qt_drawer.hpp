#ifndef QTDRAWER_HPP
#define QTDRAWER_HPP

#include <QPainter>
#include <cmath>
#include "base_drawer.h"


class QtDrawer: public BaseDrawer
{
public:

    explicit QtDrawer(QPainter *painter);
    void drawLine(const Point &p1, const Point &p2) override;
private:
    QPainter *painter;
};


#endif //QTDRAWER_H
