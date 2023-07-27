#pragma
#ifndef CROSS_H
#define CROSS_H

#include "ShapeTwoD.h"
class Cross : public ShapeTwoD
{
    private:
        vector<int> xValues;
        vector<int> yValues;
        double area;
        static const int noOfVertex = 12;
        vector<int> xPerimeter;
        vector<int> yPerimeter;
        vector<int> xArea;
        vector<int> yArea;
    public:
        Cross(string shape, bool containsWarpSpace);
        virtual double computeArea();
        double getArea();
        void readInCoords();
        bool isPointInShape(int x,int y);
        bool isPointOnShape(int x, int y);
        void calculateP();
        void calculateA();
        void getAllCoords();
        void getPCoords();
        void getACoords();
        string toString();
};
#endif