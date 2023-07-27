#ifndef POINT2D_H
#define POINT2D_H

#include<string>
#include<iostream>
#include<math.h>
#include<iomanip>


using namespace std;

//global variables
extern string filterC;
extern string sortC;
extern string order;


class Point2D{
    friend ostream& operator<<(ostream& os, Point2D& p);
    friend bool operator<(Point2D& pt1, Point2D& pt2);
    friend bool operator>(Point2D& pt1, Point2D& pt2);
    protected:
        int x,y;
        double distFrOrigin;
        void setDistFrOrigin();
    
    public:
        //default constructor
        Point2D();
        Point2D(int x, int y);
        int getX();
        int getY();
        double getScalarValue();

        void setX(int x);
        void setY(int y);
    
};
#endif