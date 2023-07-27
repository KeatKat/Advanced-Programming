#pragma
#ifndef CIRCLE_H
#define CRICLE_H

#include "ShapeTwoD.h"
class Circle : public ShapeTwoD
{
    private:
        int xValue;
        int yValue;
        int radius;
        double area;
        vector<int> xPerimeter;
        vector<int> yPerimeter;
        vector<int> xArea;
        vector<int> yArea;
    public:
        Circle(string shape, bool containsWarpSpace);
        double computeArea();
        double getArea();
        bool isPointInShape(int x,int y);
        bool isPointOnShape(int x,int y);
        void calculateP();
        void calculateA();
        void readInCoords();
        void centreRadius();
        void getPCoords();
        void getACoords();
        string toString();
};

#endif