#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private:
    int x,y;
public:
    Point();
    Point(int,int);
    Point(Point const&);

    ~Point();

    void translater(Point p);
    void translater(int,int);

    int getX() const {return this->x;}
    int getY() const {return this->y;}

    void setX(int x) {this->x = x;}
    void setY(int y) {this->y = y;}


    void operator+=(Point const& p);
};

std::ostream& operator<<(std::ostream& os, const Point& p);



#endif