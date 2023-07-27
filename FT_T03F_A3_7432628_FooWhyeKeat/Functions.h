#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <typeinfo>
#include <iomanip>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"

using namespace std;



int mainMenuOptions();
void optionOne();
void optionTwo();
void optionThree();
void optionFour();
void optionFive();
void optionSix();
vector<string> splitString (string str, string delim);

#endif