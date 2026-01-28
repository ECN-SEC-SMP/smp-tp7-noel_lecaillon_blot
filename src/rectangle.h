#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "form.h"

class Rect : public Form
{
private:
    int l,h;
public:
    Rect();
    Rect(Point p, int l, int h);
    ~Rect() = default;

    int perimeter();
    int surface();

    const int& getL() const { return this->l;}
    const int& getH() const { return this->h;}
};

std::ostream& operator<<(std::ostream& os, const Rect& r);

#endif