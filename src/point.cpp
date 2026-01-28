#include "point.h"

Point::Point():x(1),y(1){}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(Point const & p)
{
    this->x = p.x;
    this->y = p.y;
}

void Point::translater(Point p)
{
    this->x = p.x;
    this->y = p.y;
}

void Point::translater(int x, int y)
{
    this->x = x;
    this->y = y;
}
