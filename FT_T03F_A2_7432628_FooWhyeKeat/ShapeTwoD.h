#pragma
#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <typeinfo>
#include "splitString.h"
using namespace std;
//shapetwoD class
class ShapeTwoD
{
    protected:
        string name;
        bool containsWarpSpace;

    public:
        //constructors
        ShapeTwoD();
        ShapeTwoD(string shapeName, bool containsWS);
        //get methods
        string getName();
        bool getContainsWarpSpace();
        //computing
        virtual double computeArea();
        virtual bool isPointInShape(int x,int y);
        virtual bool isPointOnShape(int x, int y);
        //set methods
        void setName(string name);
        void setContainsWarpSpace(bool containsWarpSpace);
        virtual string toString();
        //others
        static bool getTFvalue(string WSorNS);
        

};

#endif