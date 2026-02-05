#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "point.h"

class Form 
{
private:
    Point p;
public:
    Form();
    Form(Point);
    
    ~Form()=default;

    const Point& getPoint() const {return this->p;}

    virtual int perimeter();
    virtual int surface();

    void operator+=(Form const& f);

};

std::ostream& operator<<(std::ostream& os, const Form& f);


#endif