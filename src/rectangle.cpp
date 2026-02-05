#include "rectangle.h"

Rect::Rect()
    : Form(), l(0), h(0)
{
}

Rect::Rect(Point p, int l, int h)
    : Form(p), l(l), h(h)
{
}

int Rect::perimeter()
{
    return 2 * (l + h);
}

int Rect::surface()
{
    return l * h;
}

std::ostream& operator<<(std::ostream& os, const Rect& r)
{
    os << "Rectangle(coin=" << r.getPoint()
       << ", l=" << r.getL()
       << ", h=" << r.getH()
       << ")";
    return os;
}
