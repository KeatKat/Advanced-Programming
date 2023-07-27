#ifndef LINE3D_H
#define LINE3D_H

#include "Line2D.h"
#include "Point3D.h"
class Line3D:public Line2D{
    friend ostream& operator<<(ostream& os, Line3D& p);
    friend bool operator<(Line3D& pt1, Line3D& pt2);
    friend bool operator>(Line3D& pt1, Line3D& pt2);
    private:
        Point3D pt1,pt2;
    protected:
        void setLength();
    public:
        Line3D();
        Line3D(Point3D pt1, Point3D pt2);

        Point3D getPt1();
        Point3D getPt2();

        void setPt1(Point3D pt1);
        void setPt2(Point3D pt2);
        
};
#endif