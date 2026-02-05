#include "cercle.h"
#include <cmath>

Cercle::Cercle():Form(),r(1)
{
}

Cercle::Cercle(Point p, int r):Form(p),r(r)
{
}


int Cercle::perimeter()
{
    return (int)(2 * M_PI * r);
}

int Cercle::surface()
{
    return (int)(M_PI * r * r);
}


std::ostream& operator<<(std::ostream& os, const Cercle& c)
{
    os << "Cercle("
       << "centre=" << c.getPoint()
       << ", r=" << c.getR()
       << ")";
    return os;
}
