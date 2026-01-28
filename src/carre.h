#ifndef CARRE_H
#define CARRE_H

#include "form.h"
#include <iostream>

class Carre : public Form
{
private:
    int _c;
public:
    Carre();
    Carre(Point p, int _c);
    ~Carre()=default;

    int perimeter();
    int surface();

    const int& getC() const { return this->_c;}
};

std::ostream& operator<<(std::ostream& os, const Carre& c);
#endif