#include "Circle.h"

Circle :: Circle(string shape, bool containsWarpSpace)
:ShapeTwoD(shape,containsWarpSpace)
{
    readInCoords();
    calculateP();
    calculateA();
}

void Circle::readInCoords() 
{
    cout << "Please enter x-coordinate of center: ";
    cin >> xValue;
    cout << "Please enter y-coordinate of center: ";
    cin >> yValue;
    cout << "Please enter radius (units): ";
    cin >> radius;
}

double Circle::computeArea()
{
    area = M_PI*radius*radius;
    return area;
}

double Circle::getArea()
{
    return area;
}

void Circle::calculateP(){
    //south
    xPerimeter.push_back(xValue);
    yPerimeter.push_back(yValue+radius);

    //north
    xPerimeter.push_back(xValue);
    yPerimeter.push_back(yValue-radius);

    //east
    xPerimeter.push_back(xValue+radius);
    yPerimeter.push_back(yValue);

    //west
    xPerimeter.push_back(xValue-radius);
    yPerimeter.push_back(yValue);


}

void Circle::calculateA(){
    //top left
    int smallX = xValue - radius;
    int smallY = yValue - radius;

    //bottom right
    int bigX = xValue + radius;
    int bigY = yValue + radius;

    for(int i=smallX;i<bigX;i++){
        for(int j=smallY;j<bigY;j++){
            if(i == xValue && j == yValue) continue; //get rid of the centre
            if(i<(xValue+radius) && i>(xValue-radius) && j<(yValue+radius) && j>(yValue-radius)){
                xArea.push_back(i);
                yArea.push_back(j);
            }
        }
    }

}

bool Circle::isPointOnShape(int x,int y){
    for(int i=0;i<xPerimeter.size();i++){
        if(x == xPerimeter.at(i) && y == yPerimeter.at(i)){
            return true;
        }
    }
    return false;
}
bool Circle::isPointInShape(int x,int y){
    for(int i=0;i<xArea.size();i++){
        if(x == xArea.at(i) && y == yArea.at(i)){
            return true;
        }
    }
    return false;
}

void Circle::centreRadius(){
    cout << "(" << xValue << ", " << yValue << ")" << endl;
    cout << "Radius: " << radius << endl;
}
void Circle::getPCoords(){
    if(xPerimeter.size()==0){
        cout << "none!" << endl;
    }
    for(int i=0;i<xPerimeter.size();i++){
        string trailing = ",";
        if(i == xPerimeter.size()-1){
            trailing = "\n";
        }
        cout <<"(" << xPerimeter.at(i) << ", " << yPerimeter.at(i) << ")" << trailing;
    }
}
void Circle::getACoords(){
    if(xArea.size()==0){
        cout << "none!" << endl;
    }
    for(int i=0;i<xArea.size();i++){
        string trailing = ",";
        if(i == xArea.size()-1){
            trailing = "\n";
        }
        cout <<"(" << xArea.at(i) << ", " << yArea.at(i) << ")" << trailing;
    }
}
string Circle::toString()
{
    string WSorNS;
    if(getContainsWarpSpace()){
        WSorNS = "WS";
    }
    else{
        WSorNS = "NS";
    }
    ostringstream oss;
    oss << "Shape Name: " <<  name << "\nSpecial Type: " << WSorNS << "\nArea: " << getArea() <<" units square" << "\nVertices: " << endl;
    return oss.str();
}