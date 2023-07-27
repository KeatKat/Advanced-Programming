#include "Line2D.h"

ostream& operator<<(ostream& os, Line2D& p){
    Point2D point1 = p.getPt1();
    Point2D point2 = p.getPt2();

    os << "[" << setw(4) << point1.getX() << ", " << setw(4) << point1.getY() << "]"
        << setw(3) << "" << "[" << setw(4) << point2.getX() << ", " << setw(4) << point2.getY() << "]"  << setw(3) << ""
        << fixed << setprecision(3) << p.getScalarValue()
        << endl;

	return os;
}

bool operator < (Line2D& line1, Line2D& line2){
    //sort by points
    if(sortC == "Pt. 1"){
        if((line1.getPt1().getX() < line2.getPt1().getX()) ||
           ((line1.getPt1().getX() == line2.getPt1().getX()) && 
           (line1.getPt1().getY() < line2.getPt1().getY()))){
                return true;
           }
    }
    else if(sortC == "Pt. 2"){
        if((line1.getPt2().getX() < line2.getPt2().getX()) ||
            ((line1.getPt2().getX() == line2.getPt2().getX()) &&
            (line1.getPt2().getY() < line2.getPt2().getY()))){
                return true;
            }
    }
    else if(sortC == "Length"){
        if(line1.getScalarValue() < line2.getScalarValue()){
            return true;
        }
    }
    return false;
}

bool operator > (Line2D& line1, Line2D& line2){
    //sort by points
    if(sortC == "Pt. 1"){
        if((line1.getPt1().getX() > line2.getPt1().getX()) ||
           ((line1.getPt1().getX() == line2.getPt1().getX()) && 
           ((line1.getPt1().getY() > line2.getPt1().getY())))){
            return true;
           }
    }
    else if(sortC == "Pt. 2"){
        if((line1.getPt2().getX() > line2.getPt2().getX()) ||
            ((line1.getPt2().getX() == line2.getPt2().getX()) &&
            (line1.getPt2().getY() < line2.getPt2().getY()))){
                return true;
            }
    }
    else if(sortC == "Length"){
        if(line1.getScalarValue() > line2.getScalarValue()){
            return true;
        }
    }
    return false;
}
Line2D::Line2D(){}
Line2D::Line2D(Point2D pt1, Point2D pt2){
    this->pt1 = pt1;
    this->pt2 = pt2;
    setLength();
}
Point2D Line2D::getPt1(){
    return pt1;
}
Point2D Line2D::getPt2(){
    return pt2;
}
void Line2D::setPt1(Point2D pt1){
    this->pt1 = pt1;
}
void Line2D::setPt2(Point2D pt2){
    this->pt2 = pt2;
}
void Line2D::setLength(){
    int x1 = pt1.getX();
    int y1 = pt1.getY();
    int x2 = pt2.getX();
    int y2 = pt2.getY();

    //doesnt matter if x1-x2 or x2-x1 as the number is squared
    length = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}
double Line2D::getScalarValue(){
    return length;
}