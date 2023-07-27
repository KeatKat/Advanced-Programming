#include "Square.h"

Square::Square(string shape, bool containsWarpSpace)
:ShapeTwoD(shape,containsWarpSpace)
{
    readInCoords();
    calculateP();
    calculateA();
}

void Square::readInCoords()
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

double Square::computeArea()
{
    vector<int> copiedXValues;
    vector<int> copiedYValues;
    copiedXValues = xValues;
    copiedYValues = yValues;

    //return only unique values in the xaxis vector
    sort(copiedXValues.begin(),copiedXValues.end()); // sort in ascending order
    auto uniqueX = unique(copiedXValues.begin(),copiedXValues.end());
    copiedXValues.resize(distance(copiedXValues.begin(), uniqueX));

    //return only unique values in the yaxis vector
    sort(copiedYValues.begin(),copiedYValues.end()); // sort in ascending order
    auto uniqueY = unique(copiedYValues.begin(),copiedYValues.end());
    copiedYValues.resize(distance(copiedYValues.begin(), uniqueY));

    
    double yLength = copiedYValues.at(1) - copiedYValues.at(0);
    double xLength = copiedXValues.at(1) - copiedXValues.at(0);
    area = yLength*xLength;

    return area;
}

double Square::getArea()
{
    return area;
}

void Square::calculateA(){
    //bottom right coordinate
    int BigX = *max_element(xValues.begin(),xValues.end());
    int BigY = *max_element(yValues.begin(),yValues.end());

    //top left coordinate
    int smallX = *min_element(xValues.begin(),xValues.end());
    int smallY = *min_element(yValues.begin(),yValues.end());
    
   
    vector<string> userCoordinates;
    
    //all points along the perimeter including user input
    for(int i=smallX;i<BigX;i++){
        for(int j=smallY;j<BigY;j++){
            otherXInArea.push_back(i);
            otherYInArea.push_back(j);            
        }
    }
    vector<string> perimeterOnly;
    vector<string> everyCoordinate;
    //changing all the individual vectors of integers into a combined (x,y) string coordinate
    //for easier comparison
    string xAndY;
    for(int i=0;i<xValues.size();i++){
        xAndY = to_string(xValues.at(i)) + "," + to_string(yValues.at(i));
        userCoordinates.push_back(xAndY);
    }

    for(int i=0;i<otherXInArea.size();i++){
        xAndY = to_string(otherXInArea.at(i)) + "," + to_string(otherYInArea.at(i));
        everyCoordinate.push_back(xAndY);
    }

    for(int i=0;i<otherXOnPerimeter.size();i++){
        xAndY = to_string(otherXOnPerimeter.at(i)) + "," + to_string(otherYOnPerimeter.at(i));
        perimeterOnly.push_back(xAndY);
    }

    /*since i need to delete and change the size of the vector, i have to iterate through it
    i compare it with the user input elements, if there is a match, i erase the element
    from the coordinate pool*/
    for(auto it = everyCoordinate.begin(); it != everyCoordinate.end();){
        bool found = false;
        for(string i: userCoordinates){
            if (*it == i) {
                found = true;
                break;
            }
        }
        if(found){
            it = everyCoordinate.erase(it);
        } else {
            ++it;
        }
    }
    //removing perimeter from the all coordinates
    for(auto it = everyCoordinate.begin(); it != everyCoordinate.end();){
        bool found = false;
        for(string i: perimeterOnly){
            if (*it == i) {
                found = true;
                break;
            }
        }
        if(found){
            it = everyCoordinate.erase(it);
        } else {
            ++it;
        }
    }
    //clearing the int vector so that i can put the x and y values back inside of it as
    //some functions still require this usage over the string vector
    otherXInArea.clear();
    otherYInArea.clear();

    for(int i=0;i<everyCoordinate.size();i++){
        string oneLine = everyCoordinate.at(i);
        vector<string> twoValues = splitString(oneLine,",");
        otherXInArea.push_back(stoi(twoValues.at(0)));
        otherYInArea.push_back(stoi(twoValues.at(1)));
    }

}

void Square::calculateP(){
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
                        otherXOnPerimeter.push_back(pointXOne + i);
                        otherYOnPerimeter.push_back(pointYOne);
                    }
                }
                if(pointXOne > pointXTwo){
                    for(int i=1;i<=segCheck;i++){
                        otherXOnPerimeter.push_back(pointXOne - i);
                        otherYOnPerimeter.push_back(pointYOne);
                    }
                }
            }
            //yaxis needs to increase/decrease
            if(abs(pointYOne - pointYTwo) != 0){
                if(pointYOne < pointYTwo){
                    for(int i=1;i<=segCheck;i++){
                        otherXOnPerimeter.push_back(pointXOne);
                        otherYOnPerimeter.push_back(pointYOne + i);
                    }
                }
                if(pointYOne > pointYTwo){
                    for(int i=1;i<=segCheck;i++){
                        otherXOnPerimeter.push_back(pointXOne);
                        otherYOnPerimeter.push_back(pointYOne - i);
                    }
                }
            }
        }

    }  

}
void Square::getAllCoords(){
    for(int i=0;i<xValues.size();i++){
        cout << "Point [" << i << "]: (" << xValues.at(i) << ", " << yValues.at(i) << ")" << endl;
    }
}
void Square::getPCoords(){
    if(otherXOnPerimeter.size()==0){
        cout << "none!" << endl;
    }
    for(int i=0;i<otherXOnPerimeter.size();i++){
        string trailing = ",";
        if(i == otherXOnPerimeter.size()-1){
            trailing = "\n";
        }
        cout <<"(" << otherXOnPerimeter.at(i) << ", " << otherYOnPerimeter.at(i) << ")" << trailing;
    }
}
void Square::getACoords(){
    if(otherXInArea.size()==0){
        cout << "none!" << endl;
    }
    for(int i=0;i<otherXInArea.size();i++){
        string trailing = ",";
        if(i == otherXInArea.size()-1){
            trailing = "\n";
        }
        cout <<"(" << otherXInArea.at(i) << ", " << otherYInArea.at(i) << ")" << trailing;
    }
}


bool Square::isPointInShape(int x,int y){
    for(int i=0;i<otherXInArea.size();i++){
        if(x == otherXInArea.at(i) && y == otherYInArea.at(i)){
            return true;
        }
    }
    return false;
}
bool Square::isPointOnShape(int x,int y){
    for(int i=0;i<otherXOnPerimeter.size();i++){
        if(x == otherXOnPerimeter.at(i) && y == otherYOnPerimeter.at(i)){
            return true;
        }
    }
    return false;
}
string Square::toString()
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