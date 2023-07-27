#include "Point2D.h"

//operator overload for insertion operator
ostream& operator<<(ostream& os, Point2D& p){
    os << "[" << setw(4) << p.getX() << ", " << setw(4) << p.getY() << "]"
           << setw(3) << "" << fixed << setprecision(3) << p.getScalarValue()
           << endl;
	return os;
}
bool operator<(Point2D& pt1, Point2D& pt2){
    //compare x values, return true pt1x < pt2x
    //if pt1x and pt2x are the same, compare pt1y and pt2y.
    if(sortC == "x-ordinate"){
        if((pt1.getX() < pt2.getX())||((pt1.getX() == pt2.getX())&&(pt1.getY()<pt2.getY()))){
            return true;
        }
    }
    else if(sortC == "y-ordinate"){
        if((pt1.getY() < pt2.getY()) || ((pt1.getY() == pt2.getY()) && (pt1.getX() < pt2.getX()))){
            return true;
        }
    }
    else if(sortC == "Dist. Fr Origin"){
        if(pt1.getScalarValue() < pt2.getScalarValue()){
            return true;
        }
    }

    return false;
}
bool operator>(Point2D& pt1, Point2D& pt2){
    //compare x values, return true pt1x < pt2x
    //if pt1x and pt2x are the same, compare pt1y and pt2y.
    if(sortC == "x-ordinate"){
        if((pt1.getX() > pt2.getX())||((pt1.getX() == pt2.getX())&&(pt1.getY()>pt2.getY()))){
            return true;
        }
    }
    else if(sortC == "y-ordinate"){
        if((pt1.getY() > pt2.getY()) || ((pt1.getY() == pt2.getY()) && (pt1.getX() > pt2.getX()))){
            return true;
        }
    }
    else if(sortC == "Dist. Fr Origin"){
        if(pt1.getScalarValue() > pt2.getScalarValue()){
            return true;
        }
    }

    return false;
}
//default constructor
Point2D::Point2D(){
    x = 0;
    y = 0;
    setDistFrOrigin();
}
//user defined constructor
Point2D::Point2D(int x, int y){
    this->x = x;
    this->y = y;
    setDistFrOrigin();
}
//get methods
int Point2D::getX(){
    return x;
}

int Point2D::getY(){
    return y;
}
//set methods
void Point2D::setX(int x){
    this->x = x;
}

void Point2D::setY(int y){
    this->y = y;
}
void Point2D::setDistFrOrigin(){
    double length;
    length = sqrt(pow(x,2)+pow(y,2));
    distFrOrigin = length;
}
double Point2D::getScalarValue(){
    return distFrOrigin;
}