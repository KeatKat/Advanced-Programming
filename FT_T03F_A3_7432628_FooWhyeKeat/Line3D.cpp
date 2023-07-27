#include "Line3D.h"

ostream& operator<<(ostream& os, Line3D& p){
    Point3D point1 = p.getPt1();
    Point3D point2 = p.getPt2();

    os << "[" << setw(4) << point1.getX() << ", " << setw(4) << point1.getY() << ", " << setw(4) << point1.getZ() << "]" << setw(3) << "" << "[" << setw(4) << point2.getX() << ", " << setw(4) << point2.getY() << ", " << setw(4) << point2.getZ() << "]"  << setw(3) << ""
    << fixed << setprecision(3) << p.getScalarValue() << endl;

	return os;
}

bool operator<(Line3D& pt1, Line3D& pt2){
    if(sortC == "Pt. 1"){
        if(pt1.getPt1().getX() < pt2.getPt1().getX() ||
        pt1.getPt1().getX() == pt2.getPt1().getX() && pt1.getPt1().getY() < pt2.getPt1().getY() ||
        pt1.getPt1().getX() == pt2.getPt1().getX() && pt1.getPt1().getY() == pt2.getPt1().getY() && pt1.getPt1().getZ() < pt2.getPt1().getZ()) {
            return true;
        }
    }
    else if(sortC == "Pt. 2"){
        if(pt1.getPt2().getX() < pt2.getPt2().getX() ||
        pt1.getPt2().getX() == pt2.getPt2().getX() && pt1.getPt2().getY() < pt2.getPt2().getY() ||
        pt1.getPt2().getX() == pt2.getPt2().getX() && pt1.getPt2().getY() == pt2.getPt2().getY() && pt1.getPt2().getZ() < pt2.getPt2().getZ()) {
            return true;
        }
    }
    else if(sortC == "Length"){
        if(pt1.getScalarValue() < pt2.getScalarValue()){
            return true;
        }
    }
    return false;
}

bool operator>(Line3D& pt1, Line3D& pt2){
    if(sortC == "Pt. 1"){
        if(pt1.getPt1().getX() > pt2.getPt1().getX() ||
        pt1.getPt1().getX() == pt2.getPt1().getX() && pt1.getPt1().getY() > pt2.getPt1().getY() ||
        pt1.getPt1().getX() == pt2.getPt1().getX() && pt1.getPt1().getY() == pt2.getPt1().getY() && pt1.getPt1().getZ() > pt2.getPt1().getZ()) {
            return true;
        }
    }
    else if(sortC == "Pt. 2"){
        if(pt1.getPt2().getX() > pt2.getPt2().getX() ||
        pt1.getPt2().getX() == pt2.getPt2().getX() && pt1.getPt2().getY() > pt2.getPt2().getY() ||
        pt1.getPt2().getX() == pt2.getPt2().getX() && pt1.getPt2().getY() == pt2.getPt2().getY() && pt1.getPt2().getZ() > pt2.getPt2().getZ()) {
            return true;
        }
    }
    else if(sortC == "Length"){
        if(pt1.getScalarValue() > pt2.getScalarValue()){
            return true;
        }
    }
    return false;
}

Line3D::Line3D(){}

Line3D::Line3D(Point3D pt1, Point3D pt2){
    this-> pt1 = pt1;
    this-> pt2 = pt2;
    setLength();
}

Point3D Line3D::getPt1(){
    return pt1;
}
Point3D Line3D::getPt2(){
    return pt2;
}

void Line3D::setPt1(Point3D pt1){
    this->pt1 = pt1;
}
void Line3D::setPt2(Point3D pt2){
    this->pt2 = pt2;
}
void Line3D::setLength(){
    int x1 = pt1.getX();
    int y1 = pt1.getY();
    int z1 = pt1.getZ();

    int x2 = pt2.getX();
    int y2 = pt2.getY();
    int z2 = pt2.getZ();

    length = sqrt(pow((x1-x2),2) + pow((y1-y2),2) + pow((z1-z2),2));
}