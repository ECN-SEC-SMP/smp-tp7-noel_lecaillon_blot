#ifndef POINT_H
#define POINT_H

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

    int getX(){return this->x;}
    int getY(){return this->y;}

    void setX(int x) {this->x = x;}
    void setY(int y) {this->y = y;}

};





#endif