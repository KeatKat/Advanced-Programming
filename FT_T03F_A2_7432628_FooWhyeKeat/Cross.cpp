#include "Cross.h"

Cross::Cross(string shape,bool containsWarpSpace)
:ShapeTwoD(shape,containsWarpSpace)
{
    readInCoords();
    calculateP();
    calculateA();
}

void Cross::readInCoords()
{
    int xvalue,yvalue;
    for(int i=0;i<noOfVertex;i++){
        cout << "Please enter x-coordinate of p" << i+1 << ". :";
        cin >> xvalue;
        cout << "Please enter y-coordinate of p" << i+1 << ". :";
        cin >> yvalue;

        xValues.push_back(xvalue);
        yValues.push_back(yvalue);
        cout << endl;
    }
}

double Cross::computeArea()
{
    //using gauss's area formula to calculate area of polygon
    vector<int> copiedXValues = xValues;
    vector<int> copiedYValues = yValues;
    
    //adding the original point to the end of the vector
    copiedXValues.push_back(copiedXValues.at(0));
    copiedYValues.push_back(copiedYValues.at(0));
    int xplusy2=0;
    int yplusx2=0;

    for(int i=0;i<noOfVertex;i++){
        //alternately adding x1 to y2 ....
        xplusy2 += (copiedXValues.at(i)* copiedYValues.at(i+1));
        //alternately adding y1 to x2 ....
        yplusx2 += (copiedYValues.at(i)*copiedXValues.at(i+1));
    }
    area = abs((xplusy2-yplusx2)/2);

    return area;
    
}

double Cross::getArea()
{
    return area;
}
 
void Cross::calculateP(){
    int size = xValues.size();
    int pointXOne,pointYOne,pointXTwo,pointYTwo;
    for(int i=0;i<size;i++){
        pointXOne = xValues.at(i);
        pointYOne = yValues.at(i);

        //allow it to loop back to element 0 and not crash the programme
        pointXTwo = xValues.at((i+1)%size);
        pointYTwo = yValues.at((i+1)%size);

        int segCheck = (abs(pointXOne - pointXTwo) + abs(pointYOne - pointYTwo)) - 1;
        //if not = 0 then the perimeter has a gap between;
        if(segCheck != 0){
            //xaxis needs to increase/decrease
            if(abs(pointXOne - pointXTwo)!= 0){

                if(pointXOne < pointXTwo){
                    for(int i=1;i<=segCheck;i++){
                        xPerimeter.push_back(pointXOne + i);
                        yPerimeter.push_back(pointYOne);
                    }
                }
                if(pointXOne > pointXTwo){
                    for(int i=1;i<=segCheck;i++){
                        xPerimeter.push_back(pointXOne - i);
                        yPerimeter.push_back(pointYOne);
                    }
                }
            }
            //yaxis needs to increase/decrease
            if(abs(pointYOne - pointYTwo) != 0){
                if(pointYOne < pointYTwo){
                    for(int i=1;i<=segCheck;i++){
                        xPerimeter.push_back(pointXOne);
                        yPerimeter.push_back(pointYOne + i);
                    }
                }
                if(pointYOne > pointYTwo){
                    for(int i=1;i<=segCheck;i++){
                        xPerimeter.push_back(pointXOne);
                        yPerimeter.push_back(pointYOne - i);
                    }
                }
            }
        }

    }  
}

void Cross::calculateA(){
    vector<string> combineXYUser;
    vector<string> combineXY;
    string xAndY;
    //converting to string coordinate for comparison
    for(int i=0;i<xPerimeter.size();i++){
        xAndY = to_string(xPerimeter.at(i)) + "," + to_string(yPerimeter.at(i));
        combineXY.push_back(xAndY);
    }
    for(int i=0;i<xValues.size();i++){
        xAndY = to_string(xValues.at(i)) + "," + to_string(yValues.at(i));
        combineXYUser.push_back(xAndY);
    }
    
    //combining perimeter and 12 vertex that user input
    combineXY.insert(combineXY.end(),combineXYUser.begin(),combineXYUser.end());
    //sort according to ascending order so i get to test for straight lines
    sort(combineXY.begin(),combineXY.end());

    vector<int> xAreaSorted;
    vector<int> yAreaSorted;

    for(int i=0;i<combineXY.size();i++){
        vector<string> oneLine = splitString(combineXY.at(i),",");
        xAreaSorted.push_back(stoi(oneLine.at(0)));
        yAreaSorted.push_back(stoi(oneLine.at(1)));
    }
    //get unique x axis points where i need the vertical lines
    auto uniqueX = unique(xAreaSorted.begin(),xAreaSorted.end());
    xAreaSorted.resize(distance(xAreaSorted.begin(), uniqueX));
    int size = yAreaSorted.size();
    int pointYOne,pointYTwo;

    for(int i=0;i<xAreaSorted.size();i++){
        for(int j=0;j<combineXY.size();j++) {
            vector<string> oneLine = splitString(combineXY.at(j),",");
            if(xAreaSorted.at(i) == stoi(oneLine.at(0))){
                pointYOne = yAreaSorted.at(j);
                //allow it to loop back to element 0 and not crash the programme
                pointYTwo = yAreaSorted.at((j+1)%size);
                int parityCheck = pointYOne - pointYTwo;
                int segCheck = (abs(pointYOne - pointYTwo)) - 1;
                //cout << parityCheck << endl;
                if(segCheck != 0 && parityCheck <0){
                    for(int x=1;x<=segCheck;x++){
                        xArea.push_back(xAreaSorted.at(i));
                        yArea.push_back(pointYOne + x);
                    }
                }
            }
        }
        
    }

    for(int i=0;i<xArea.size();i++){
        cout << xArea.at(i) << "," << yArea.at(i) << endl;
    }
}

bool Cross::isPointInShape(int x, int y){
    for(int i=0;i<xArea.size();i++){
        if(x == xArea.at(i) && y == yArea.at(i)){
            return true;
        }
    }
    return false;
}

bool Cross::isPointOnShape(int x,int y){
    for(int i=0;i<xPerimeter.size();i++){
        if(x == xPerimeter.at(i) && y == yPerimeter.at(i)){
            return true;
        }
    }
    return false;
}
void Cross::getAllCoords(){
    for(int i=0;i<xValues.size();i++){
        cout << "Point [" << i << "]: (" << xValues.at(i) << ", " << yValues.at(i) << ")" << endl;
    }
}
void Cross::getPCoords(){
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
void Cross::getACoords(){
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
string Cross::toString()
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