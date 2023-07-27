#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"
class Point3D:public Point2D{
    friend ostream& operator<<(ostream& os, Point3D& p);
    friend bool operator<(Point3D& pt1, Point3D& pt2);
    friend bool operator>(Point3D& pt1, Point3D& pt2);
    protected:
        int z;
        void setDistFrOrigin();
    public:
        Point3D();
        Point3D(int x, int y, int z);
        int getZ();
        void setZ(int z);
};

#endif