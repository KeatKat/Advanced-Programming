#include "ShapeTwoD.h"

//constructor declaration
ShapeTwoD::ShapeTwoD(){

}
ShapeTwoD::ShapeTwoD(string shapeName, bool containsWS)
{
    name = shapeName;
    containsWarpSpace = containsWS;
}
//get methods
string ShapeTwoD::getName()
{
    return name;
}
bool ShapeTwoD::getContainsWarpSpace()
{
    return containsWarpSpace;
}
//set methods
void ShapeTwoD::setName(string name)
{
    this->name = name;
}
void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
    this->containsWarpSpace = containsWarpSpace;
}
//compute
double ShapeTwoD::computeArea(){
    return 0;
}
bool ShapeTwoD::isPointInShape(int x,int y){
    return false;
}
bool ShapeTwoD::isPointOnShape(int x,int y){
    return false;
}
//others
bool ShapeTwoD::getTFvalue(string WSorNS)
{
    if(WSorNS == "WS"){
        return true;
    }
    else {
        return false;
    }
}
string ShapeTwoD::toString()
{
    string WSorNS;
    if(getContainsWarpSpace()){
        WSorNS = "WS";
    }
    else{
        WSorNS = "NS";
    }
    ostringstream oss;
    oss << "Shape Name: " <<  name << "\nSpecial Type: " << WSorNS << endl;
    return oss.str();
}