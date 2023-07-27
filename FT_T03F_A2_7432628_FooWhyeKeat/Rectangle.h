#pragma
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeTwoD.h"
class Rectangle : public ShapeTwoD
{
    private:
        vector<int> xValues;
        vector<int> yValues;
        double area;
        static const int noOfVertex = 4;
        
        vector<int> otherXOnPerimeter;
        vector<int> otherYOnPerimeter;
        vector<int> otherXInArea;
        vector<int> otherYInArea;
        
    public:
        Rectangle(string shape, bool containsWarpSpace);
        bool isPointInShape(int x,int y);
        bool isPointOnShape(int x,int y);
        double computeArea();
        double getArea();
        void readInCoords();
        void calculateA();
        void calculateP();
        string toString();
        void getAllCoords();
        void getPCoords();
        void getACoords();

};

#endif