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
    *this += p;
}

void Point::translater(int x, int y)
{
    this->x += x;
    this->y += y;
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os <<"X : "<<p.getX() <<"\nY : " <<p.getY() << std::endl;
    return os;
}

void Point::operator+=(Point const& p)
{
    this->x += p.x;
    this->y += p.y;
}