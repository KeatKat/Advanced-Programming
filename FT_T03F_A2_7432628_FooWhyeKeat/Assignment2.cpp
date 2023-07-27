#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <typeinfo>

#include "ShapeTwoD.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Cross.h"

using namespace std;

//functions
//------------------------------------------------------------------------------
int mainMenuOptions(){
    cout << "Student ID   : 7432628" << endl;
    cout << "Student Name : Foo Whye Keat" << endl;
    cout << "------------------------------" << endl;
    cout << "Welcome to Assignment 2 program!" << endl;
    cout << endl;
    cout << "1)     Input sensor data" << endl;
    cout << "2)     Compute area (for all records)" << endl;
    cout << "3)     Print shapes report" << endl;
    cout << "4)     Sort shape data" <<endl;
    cout << endl;
    cout << "Please enter your choice: ";
    int menuChoice;
    cin >> menuChoice;
    return menuChoice;

}

void optionOne(vector<Rectangle>& rectangleObjs,vector<Circle>& circleObjs,vector<Square>& squareObjs, vector<Cross>& crossObjs){
    //user interface
    string shape,WSorNS;
    bool containsWS;
    cout << endl;
    cout << "[ Input sensor data ]" << endl;
    cout << "Name of shape: ";
    cin >> shape;
    cout << "Normal space (NS) or Warp space (WS): ";
    cin >> WSorNS;
    containsWS = ShapeTwoD::getTFvalue(WSorNS);

    cout << endl;
    //building object according to the user input then storing object into the vector of objects
    if(shape == "Rectangle" || shape == "rectangle"){
        Rectangle recObj(shape,containsWS);
        rectangleObjs.push_back(recObj);
    }
    if(shape == "Circle" || shape == "circle"){
        Circle circleObj(shape,containsWS);
        circleObjs.push_back(circleObj);
    }
    if(shape == "Square" || shape == "square"){
        Square squareObj(shape,containsWS);
        squareObjs.push_back(squareObj);
    }
    if(shape == "Cross" || shape == "cross"){
        Cross crossObj(shape,containsWS);
        crossObjs.push_back(crossObj);
    }
}

void optionTwo(vector<Rectangle>& rectangleObjs,vector<Circle>& circleObjs,vector<Square>& squareObjs, vector<Cross>& crossObjs){
    cout << endl;
    int count = 0;
    for(int i=0;i<rectangleObjs.size();i++){
        rectangleObjs.at(i).computeArea();
        count++;
    }

    for(int i=0;i<circleObjs.size();i++){
        circleObjs.at(i).computeArea();
        count++;
    }

    for(int i=0;i<squareObjs.size();i++){
        squareObjs.at(i).computeArea();
        count++;
    }

    for(int i=0;i<crossObjs.size();i++){
        crossObjs.at(i).computeArea();
        count++;
    }

    cout << "Computation completed! ( " << count << " records were updated )" << endl;
    cout << endl;
}

void optionThree(vector<Rectangle>& rectangleObjs,vector<Circle>& circleObjs,vector<Square>& squareObjs, vector<Cross>& crossObjs){
    int count = 0;
    for(int i=0;i<rectangleObjs.size();i++){
        cout << endl;
        cout << "Shape[" << count << "]" << endl;
        count ++;
        cout << rectangleObjs.at(i).toString();
        rectangleObjs.at(i).getAllCoords();
        cout << endl;
        cout << "Points on perimeter: ";
        rectangleObjs.at(i).getPCoords();
        cout << endl;
        cout << "Points within shape: ";
        rectangleObjs.at(i).getACoords();
    }
    for(int i=0;i<squareObjs.size();i++){
        cout << endl;
        cout << "Shape[" << count << "]" << endl;
        cout << squareObjs.at(i).toString();
        squareObjs.at(i).getAllCoords();
        cout << endl;
        cout << "Points on perimeter: ";
        squareObjs.at(i).getPCoords();
        cout << "Points within shape: ";
        squareObjs.at(i).getACoords();
        count ++;
    }
    for(int i=0;i<crossObjs.size();i++){
        cout << endl;
        cout << "Shape[" << count << "]" << endl;
        cout << crossObjs.at(i).toString();
        crossObjs.at(i).getAllCoords();
        cout << endl;
        cout << "Points on perimeter: ";
        crossObjs.at(i).getPCoords();
        cout << "Points within shape: ";
        crossObjs.at(i).getACoords();
        count ++;
    }
    for(int i=0;i<circleObjs.size();i++){
        cout << endl;
        cout << "Shape[" << count << "]" << endl;
        cout << circleObjs.at(i).toString();
        circleObjs.at(i).centreRadius();
        cout << "Points on perimeter: ";
        circleObjs.at(i).getPCoords();
        cout << "Points within shape: ";
        circleObjs.at(i).getACoords();
        count ++;
    }
}

void optionFour(vector<Rectangle>& rectangleObjs,vector<Circle>& circleObjs,vector<Square>& squareObjs, vector<Cross>& crossObjs) {
    cout << "   a)     Sort by Area (ascending)" << endl;
    cout << "   b)     Sort by Area (descending)" << endl;
    cout << "   c)     Sort by special type and area" << endl;
    cout << endl;
    char userinput;
    cout << "Please select sort option ('q' to go main menu): ";
    cin >> userinput;
    vector<double> allAreas;
    int count = 0;
    vector<Rectangle> recOrdered;
    vector<Circle> circleOrdered;
    vector<Square> squareOrdered;
    vector<Cross> crossOrdered;
    //get and compare areas
    for(int i=0;i<rectangleObjs.size();i++){
        allAreas.push_back(rectangleObjs.at(i).getArea()); 
    }
    for(int i=0;i<circleObjs.size();i++){
        allAreas.push_back(circleObjs.at(i).getArea()); 
    }
    for(int i=0;i<squareObjs.size();i++){
        allAreas.push_back(squareObjs.at(i).getArea()); 
    }
    for(int i=0;i<crossObjs.size();i++){
        allAreas.push_back(crossObjs.at(i).getArea()); 
    }
    switch (userinput)
    {
        case 'a':
            cout << "Sort by area (Smallest to largest)" << endl;
            sort(allAreas.begin(),allAreas.end());
            for(int i=0;i<allAreas.size();i++){
                for(int j=0;j<rectangleObjs.size();j++){
                    if(rectangleObjs.at(j).getArea() == allAreas.at(i)){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << rectangleObjs.at(j).toString();
                        rectangleObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        rectangleObjs.at(j).getPCoords();
                        cout << endl;
                        cout << "Points within shape: ";
                        rectangleObjs.at(j).getACoords();
                        count ++;
                        recOrdered.push_back(rectangleObjs.at(j));
                    }
                }
                for(int j=0;j<squareObjs.size();j++){
                    if(squareObjs.at(j).getArea() == allAreas.at(i)){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << squareObjs.at(j).toString();
                        squareObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        squareObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        squareObjs.at(j).getACoords();
                        count ++;
                        squareOrdered.push_back(squareObjs.at(j));
                    }
                }
                for(int j=0;j<crossObjs.size();j++){
                    if(crossObjs.at(j).getArea() == allAreas.at(i)){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << crossObjs.at(j).toString();
                        crossObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        crossObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        crossObjs.at(j).getACoords();
                        count ++;
                        crossOrdered.push_back(crossObjs.at(j));
                    }
                }
                for(int j=0;j<circleObjs.size();j++){
                    if(circleObjs.at(j).getArea() == allAreas.at(i)){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << circleObjs.at(j).toString();
                        circleObjs.at(j).centreRadius();
                        cout << "Points on perimeter: ";
                        circleObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        circleObjs.at(j).getACoords();
                        count ++;
                        circleOrdered.push_back(circleObjs.at(j));
                    }
                }
            }
        break;

        case 'b':
            cout << "Sort by area (Largest to smallest)" << endl;
            count = 0;
            sort(allAreas.begin(),allAreas.end(),greater<double>());
            cout << "sizesizesize " << allAreas.size() << endl;
            for(int i=0;i<allAreas.size();i++) {
                    for(int j=0;j<rectangleObjs.size();j++){
                        if(rectangleObjs.at(j).getArea() == allAreas.at(i)){
                            cout << endl;
                            cout << "Shape[" << count << "]" << endl;
                            count ++;
                            cout << rectangleObjs.at(j).toString();
                            rectangleObjs.at(j).getAllCoords();
                            cout << endl;
                            cout << "Points on perimeter: ";
                            rectangleObjs.at(j).getPCoords();
                            cout << endl;
                            cout << "Points within shape: ";
                            rectangleObjs.at(j).getACoords();
                        }
                    }
                    for(int j=0;j<squareObjs.size();j++){
                        if(squareObjs.at(j).getArea() == allAreas.at(i)){
                            cout << endl;
                            cout << "Shape[" << count << "]" << endl;
                            cout << squareObjs.at(j).toString();
                            squareObjs.at(j).getAllCoords();
                            cout << endl;
                            cout << "Points on perimeter: ";
                            squareObjs.at(j).getPCoords();
                            cout << "Points within shape: ";
                            squareObjs.at(j).getACoords();
                            count ++;
                        }
                    }
                    for(int j=0;j<crossObjs.size();j++){
                        if(crossObjs.at(j).getArea() == allAreas.at(i)){
                            cout << endl;
                            cout << "Shape[" << count << "]" << endl;
                            cout << crossObjs.at(j).toString();
                            crossObjs.at(j).getAllCoords();
                            cout << endl;
                            cout << "Points on perimeter: ";
                            crossObjs.at(j).getPCoords();
                            cout << "Points within shape: ";
                            crossObjs.at(j).getACoords();
                            count ++;
                        }
                    }
                    for(int j=0;j<circleObjs.size();j++){
                        if(circleObjs.at(j).getArea() == allAreas.at(i)){
                            cout << endl;
                            cout << "Shape[" << count << "]" << endl;
                            cout << circleObjs.at(j).toString();
                            circleObjs.at(j).centreRadius();
                            cout << "Points on perimeter: ";
                            circleObjs.at(j).getPCoords();
                            cout << "Points within shape: ";
                            circleObjs.at(j).getACoords();
                            count ++;
                        }
                    }                  
            }
        break;

        case 'c':
            sort(allAreas.begin(),allAreas.end());
            for(int i=0;i<allAreas.size();i++){
                for(int j=0;j<rectangleObjs.size();j++){
                    if(rectangleObjs.at(j).getArea() == allAreas.at(i)){
                        recOrdered.push_back(rectangleObjs.at(j));
                    }
                }
                for(int j=0;j<squareObjs.size();j++){
                    if(squareObjs.at(j).getArea() == allAreas.at(i)){
                        squareOrdered.push_back(squareObjs.at(j));
                    }
                }
                for(int j=0;j<crossObjs.size();j++){
                    if(crossObjs.at(j).getArea() == allAreas.at(i)){
                        crossOrdered.push_back(crossObjs.at(j));
                    }
                }
                for(int j=0;j<circleObjs.size();j++){
                    if(circleObjs.at(j).getArea() == allAreas.at(i)){
                        circleOrdered.push_back(circleObjs.at(j));
                    }
                }
            }
            for(int i=0;i<allAreas.size();i++){
                for(int j=0;j<rectangleObjs.size();j++){
                    if(rectangleObjs.at(j).getArea() == allAreas.at(i) && rectangleObjs.at(j).getContainsWarpSpace() == false){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << rectangleObjs.at(j).toString();
                        rectangleObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        rectangleObjs.at(j).getPCoords();
                        cout << endl;
                        cout << "Points within shape: ";
                        rectangleObjs.at(j).getACoords();
                        count ++;
                    }
                }
                for(int j=0;j<squareObjs.size();j++){
                    if(squareObjs.at(j).getArea() == allAreas.at(i) && squareObjs.at(j).getContainsWarpSpace() == false){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << squareObjs.at(j).toString();
                        squareObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        squareObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        squareObjs.at(j).getACoords();
                        count ++;
                    }
                }
                for(int j=0;j<crossObjs.size();j++){
                    if(crossObjs.at(j).getArea() == allAreas.at(i) && crossObjs.at(j).getContainsWarpSpace() == false){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << crossObjs.at(j).toString();
                        crossObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        crossObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        crossObjs.at(j).getACoords();
                        count ++;
                    }
                }
                for(int j=0;j<circleObjs.size();j++){
                    if(circleObjs.at(j).getArea() == allAreas.at(i) && circleObjs.at(j).getContainsWarpSpace() == false){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << circleObjs.at(j).toString();
                        circleObjs.at(j).centreRadius();
                        cout << "Points on perimeter: ";
                        circleObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        circleObjs.at(j).getACoords();
                        count ++;
                    }
                }
            }
            for(int i=0;i<allAreas.size();i++){
                for(int j=0;j<rectangleObjs.size();j++){
                    if(rectangleObjs.at(j).getArea() == allAreas.at(i) && rectangleObjs.at(j).getContainsWarpSpace() == true){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << rectangleObjs.at(j).toString();
                        rectangleObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        rectangleObjs.at(j).getPCoords();
                        cout << endl;
                        cout << "Points within shape: ";
                        rectangleObjs.at(j).getACoords();
                        count ++;
                    }
                }
                for(int j=0;j<squareObjs.size();j++){
                    if(squareObjs.at(j).getArea() == allAreas.at(i) && squareObjs.at(j).getContainsWarpSpace() == true){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << squareObjs.at(j).toString();
                        squareObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        squareObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        squareObjs.at(j).getACoords();
                        count ++;
                    }
                }
                for(int j=0;j<crossObjs.size();j++){
                    if(crossObjs.at(j).getArea() == allAreas.at(i) && crossObjs.at(j).getContainsWarpSpace() == true){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << crossObjs.at(j).toString();
                        crossObjs.at(j).getAllCoords();
                        cout << endl;
                        cout << "Points on perimeter: ";
                        crossObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        crossObjs.at(j).getACoords();
                        count ++;
                    }
                }
                for(int j=0;j<circleObjs.size();j++){
                    if(circleObjs.at(j).getArea() == allAreas.at(i) && circleObjs.at(j).getContainsWarpSpace() == true){
                        cout << endl;
                        cout << "Shape[" << count << "]" << endl;
                        cout << circleObjs.at(j).toString();
                        circleObjs.at(j).centreRadius();
                        cout << "Points on perimeter: ";
                        circleObjs.at(j).getPCoords();
                        cout << "Points within shape: ";
                        circleObjs.at(j).getACoords();
                        count ++;
                    }
                }
            }
        break;


    
    }
    
}
//------------------------------------------------------------------------------
int main(){
    vector<Rectangle> rectangleObjs;
    vector<Square> squareObjs;
    vector<Circle> circleObjs;
    vector<Cross> crossObjs;
    while(true){
        int choice = mainMenuOptions();

        switch (choice)
        {
        case 1:
            optionOne(rectangleObjs,circleObjs,squareObjs,crossObjs);
            break;
        case 2:
            optionTwo(rectangleObjs,circleObjs,squareObjs,crossObjs);
            break;
        case 3:
            optionThree(rectangleObjs,circleObjs,squareObjs,crossObjs);
            break;
        case 4:
            optionFour(rectangleObjs,circleObjs,squareObjs,crossObjs);
            break;
        }
     
    }
}