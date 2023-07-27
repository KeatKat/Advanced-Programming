#pragma
#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeTwoD.h"
class Square : public ShapeTwoD
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
        Square(string shape, bool containsWarpSpace);
        virtual double computeArea();
        double getArea();
        bool isPointInShape(int x,int y);
        bool isPointOnShape(int x,int y);
        void readInCoords();
        void calculateP();
        void calculateA();
        void getAllCoords();
        void getPCoords();
        void getACoords();
        string toString();
};

#endif