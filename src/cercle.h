#ifndef CERCLE_H
#define CERCLE_H

#include "form.h"
#include <iostream>

class Cercle : public Form
{
private:
    int r;
public:
    Cercle();
    Cercle(Point p, int r);
    
    ~Cercle()=default;

    int perimeter();
    int surface();

    const int& getR() const {return this->r;}

};

std::ostream& operator<<(std::ostream& os, const Cercle& c);
#endif