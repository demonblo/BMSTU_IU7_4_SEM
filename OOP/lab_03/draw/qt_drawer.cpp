#include "draw/qt_drawer.hpp"

QtDrawer::QtDrawer(QPainter *painter): painter(painter) {}

void QtDrawer::drawLine(const Point &p1, const Point &p2)
{
    auto w = painter->window().width() / 2;
    auto h = painter->window().height() / 2;
    painter->drawLine(w + std::round(p1.getX()), h - std::round(p1.getY()), w + std::round(p2.getX()), h - std::round(p2.getY()));
}
