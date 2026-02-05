#include "carre.h"

// Constructeur par défaut
Carre::Carre()
    : Form(), _c(0)
{
}

// Constructeur avec coin et côté
Carre::Carre(Point p, int c)
    : Form(p), _c(c)
{
}

// Périmètre
int Carre::perimeter()
{
    return 4 * _c;
}

// Surface
int Carre::surface()
{
    return _c * _c;
}

// Affichage
std::ostream& operator<<(std::ostream& os, const Carre& c)
{
    os << "Carre(coin=" << c.getPoint()
       << ", cote=" << c.getC()
       << ")";
    return os;
}

