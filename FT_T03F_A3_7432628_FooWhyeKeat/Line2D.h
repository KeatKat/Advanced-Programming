#ifndef LINE2D_H
#define LINE2D_H

#include "Point2D.h"
class Line2D{
    friend ostream& operator<<(ostream& os, Line2D& p);
    friend bool operator<(Line2D& pt1, Line2D& pt2);
    friend bool operator>(Line2D& pt1, Line2D& pt2);
    private:
        Point2D pt1, pt2;
    protected:
        double length;
        void setLength();
    public:
        Line2D();
        Line2D(Point2D pt1, Point2D pt2);
        Point2D getPt1();
        Point2D getPt2();
        double getScalarValue();

        void setPt1(Point2D pt1);
        void setPt2(Point2D pt2);        
        
};

#endif