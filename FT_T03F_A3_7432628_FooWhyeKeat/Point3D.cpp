#include "Point3D.h"

ostream& operator<<(ostream& os, Point3D& p){
    os << "[" << setw(4) << p.getX() << ", " << setw(4) << p.getY() <<", " << setw(4) << p.getZ() << "]" << setw(3) << "" << fixed << setprecision(3) << p.getScalarValue() << endl;
	
    return os;
}

bool operator<(Point3D& pt1, Point3D& pt2){
    //compare x values, return true pt1x < pt2x
    //if pt1x and pt2x are the same, compare pt1y and pt2y.
    //if pt1y and pt2y is the same compare through x first
    if(sortC == "x-ordinate"){
        if((pt1.getX() < pt2.getX())||
        ((pt1.getX() == pt2.getX())&&(pt1.getY()<pt2.getY()))||
        ((pt1.getX() == pt2.getX())&&(pt1.getY() == pt2.getY())&&(pt1.getZ()<pt2.getZ()))){
            return true;
        }
    }
    else if(sortC == "y-ordinate"){
        if((pt1.getY() < pt2.getY())||
        ((pt1.getY() == pt2.getY()) && (pt1.getX() < pt2.getX()))||
        ((pt1.getY() == pt2.getY())&&(pt1.getY() == pt2.getY())&&(pt1.getZ()<pt2.getZ()))){
            return true;
        }
    }
    else if(sortC == "z-ordinate"){
        if((pt1.getZ() < pt2.getZ())||
        ((pt1.getZ() == pt2.getZ()) && (pt1.getX() < pt2.getX()))||
        ((pt1.getZ() == pt2.getZ()) && (pt1.getX() == pt2.getX()) && (pt1.getY()<pt2.getY()))){
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

bool operator>(Point3D& pt1, Point3D& pt2){
    //compare x values, return true pt1x < pt2x
    //if pt1x and pt2x are the same, compare pt1y and pt2y.
    //if pt1y and pt2y is the same compare through x first
    if(sortC == "x-ordinate"){
        if((pt1.getX() > pt2.getX())||
        ((pt1.getX() == pt2.getX())&&(pt1.getY()>pt2.getY()))||
        ((pt1.getX() == pt2.getX())&&(pt1.getY() == pt2.getY())&&(pt1.getZ()>pt2.getZ()))){
            return true;
        }
    }
    else if(sortC == "y-ordinate"){
        if((pt1.getY() > pt2.getY())||
        ((pt1.getY() == pt2.getY()) && (pt1.getX() > pt2.getX()))||
        ((pt1.getY() == pt2.getY())&&(pt1.getY() == pt2.getY())&&(pt1.getZ()>pt2.getZ()))){
            return true;
        }
    }
    else if(sortC == "z-ordinate"){
        if((pt1.getZ() > pt2.getZ())||
        ((pt1.getZ() == pt2.getZ()) && (pt1.getX() > pt2.getX()))||
        ((pt1.getZ() == pt2.getZ()) && (pt1.getX() == pt2.getX()) && (pt1.getY()>pt2.getY()))){
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


Point3D::Point3D():Point2D(){
    z = 0;
    setDistFrOrigin();
}

Point3D::Point3D(int x, int y, int z):Point2D(x,y){
    this->z = z;
    setDistFrOrigin();
}

int Point3D::getZ(){
    return z;
}
void Point3D::setZ(int z){
    this->z = z;
}

//method override
void Point3D::setDistFrOrigin(){
    double length;
    length = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    //protected memeber can be accessed by child
    distFrOrigin = length;
}