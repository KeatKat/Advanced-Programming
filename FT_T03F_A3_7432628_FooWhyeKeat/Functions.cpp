#include "Functions.h"
vector<Point2D> v2DPoint;
vector<Point3D> v3DPoint;
vector<Line2D> v2DLine;
vector<Line3D> v3DLine;

string filterC = "Point2D";
string sortC = "x-ordinate";
string order = "ASC";

//functions
int mainMenuOptions(){
    cout << endl;
    cout << "Student ID   : 7432628" << endl;
    cout << "Student Name : Foo Whye Keat" << endl;
    cout << "------------------------------" << endl;
    cout << "Welcome to Assignment 3 program!" << endl;
    cout << endl;
    cout << "1)     Read in data" << endl;
    cout << "2)     Specify filtering criteria (current : " << filterC << ")" <<  endl;
    cout << "3)     Specify sorting criteria (current : " << sortC << ")" <<  endl;
    cout << "4)     Specify sorting order (current : " << order << ")" <<  endl;
    cout << "5)     View data" << endl;
    cout << "6)     Store data" << endl;
    cout << "7)     Quit" << endl;
    cout << endl;
    cout << "Please enter your choice: ";
    int menuChoice;
    cin >> menuChoice;
    return menuChoice;
}
void optionOne(){
    cout << endl;
    cout << "Please enter filename : ";

    string fileName;
    cin >> fileName;
    cin.clear();
    ifstream dataIn;
    dataIn.open(fileName);

    vector<string> sortedAndUnique;

    while(dataIn.good()){
        string data;
        getline(dataIn,data);
        if(data == "" || data[0] == '/') continue; //skip comments and empty lines
        sortedAndUnique.push_back(data);
    }

    //get rid of duplicates
    sort(sortedAndUnique.begin(),sortedAndUnique.end());
    auto uniques = unique(sortedAndUnique.begin(),sortedAndUnique.end());
    sortedAndUnique.resize(distance(sortedAndUnique.begin(),uniques));

    string newLine;
    string xCoordinate,yCoordinate,zCoordinate;
    int count =0;
    for(int i=0;i<sortedAndUnique.size();i++){
        newLine = sortedAndUnique.at(i);
        vector<string> splitLine = splitString(newLine,", ");

        if(splitLine.at(0) == "Point2D"){
            //getting x and y value
            xCoordinate = splitLine.at(1);
            yCoordinate = splitLine.at(2);
            
            //remove []
            xCoordinate.erase(0,1);
            yCoordinate.pop_back();

            Point2D p2DObj(stoi(xCoordinate),stoi(yCoordinate));
            v2DPoint.push_back(p2DObj);
            count++;
        }

        if(splitLine.at(0) == "Point3D"){
            xCoordinate = splitLine.at(1);
            yCoordinate = splitLine.at(2);
            zCoordinate = splitLine.at(3);

            //removing brackets
            xCoordinate.erase(0,1);
            zCoordinate.pop_back();

            Point3D p3DObj(stoi(xCoordinate),stoi(yCoordinate),stoi(zCoordinate));
            v3DPoint.push_back(p3DObj);
            count++;
        }

        if(splitLine.at(0) == "Line2D"){
            //create 2 point2d objects then create line2d obj

            xCoordinate = splitLine.at(1);
            yCoordinate = splitLine.at(2);
            xCoordinate.erase(0,1);
            yCoordinate.pop_back();
            Point2D p2DObj1(stoi(xCoordinate),stoi(yCoordinate));

            xCoordinate = splitLine.at(3);
            yCoordinate = splitLine.at(4);
            xCoordinate.erase(0,1);
            yCoordinate.pop_back();
            Point2D p2DObj2(stoi(xCoordinate),stoi(yCoordinate));

            Line2D l2DObj(p2DObj1,p2DObj2);
            v2DLine.push_back(l2DObj);
            count++;
        }

        if(splitLine.at(0) == "Line3D"){
            //create 2 point3D objects then create line3d obj

            xCoordinate = splitLine.at(1);
            yCoordinate = splitLine.at(2);
            zCoordinate = splitLine.at(3);

            xCoordinate.erase(0,1);
            zCoordinate.pop_back();

            Point3D p3DObj1(stoi(xCoordinate),stoi(yCoordinate), stoi(zCoordinate));

            xCoordinate = splitLine.at(4);
            yCoordinate = splitLine.at(5);
            zCoordinate = splitLine.at(6);

            xCoordinate.erase(0,1);
            zCoordinate.pop_back();

            Point3D p3DObj2(stoi(xCoordinate),stoi(yCoordinate), stoi(zCoordinate));

            Line3D l3DObj(p3DObj1,p3DObj2);
            v3DLine.push_back(l3DObj);
            count++;
        }
    }
    cout << endl;
    cout << count << " records read in successfully!" << endl;
    cout << endl;
    cout << "Going back to main menu ... " << endl;
    cout << endl;

   
}
void optionTwo(){
    cout << endl;
    cout << "[ Specifying filtering criteria (current : " << filterC << ")]" << endl;
    cout << endl;
    cout << "\ta)\tPoint2D records" << endl;
    cout << "\tb)\tPoint3D records" << endl;
    cout << "\tc)\tLine2D records" << endl;
    cout << "\td)\tLine3D records" << endl;
    cout << endl;

    cout << "\tPlease enter your criteria (a-d): ";
    char userChoice;
    cin >> userChoice;

    switch (userChoice)
    {
    case 'a':
        filterC = "Point2D";
        sortC = "x-ordinate";
        break;
    case 'b':
        filterC = "Point3D";
        sortC = "x-ordinate";
        break;
    case 'c':
        filterC = "Line2D";
        sortC = "Pt. 1";
        break;
    case 'd':
        filterC = "Line3D";
        sortC = "Pt. 1";
        break;
    }

    cout << "\tFilter criteria successfully set to '" << filterC << "'!" << endl;
}

void optionThree(){
    cout << "[ Specifiying sorting criteria (current : " << sortC << ")]" << endl;
    cout << endl;
    char userChoice;
    if(filterC == "Point2D"){
        cout << "\ta)\tx-ordinate value" << endl;
        cout << "\tb)\ty-ordinate value" << endl;
        cout << "\tc)\tDist. Fr Origin value" << endl;
        cout << endl;
        cout << "\tPlease enter your criteria (a-c): ";
        cin >> userChoice;

        switch(userChoice)
        {
            case 'a':
                sortC = "x-ordinate";
                break;
            case 'b':
                sortC = "y-ordinate";
                break;
            case 'c':
                sortC = "Dist. Fr Origin";
                break;
        }
        cout << "\tSorting criteria successfully set to '" << sortC << "'!" << endl;
    }

    if(filterC == "Point3D"){
        cout << "\ta)\tx-ordinate value" << endl;
        cout << "\tb)\ty-ordinate value" << endl;
        cout << "\tc)\tz-ordinate value" << endl;
        cout << "\td)\tDist. Fr Origin value" << endl;
        cout << endl;
        cout << "\tPlease enter your criteria (a-d): ";
        cin >> userChoice;

        switch(userChoice)
        {
            case 'a':
                sortC = "x-ordinate";
                break;
            case 'b':
                sortC = "y-ordinate";
                break;

            case 'c':
                sortC = "z-ordinate";
                break;
            case 'd':
                sortC = "Dist. Fr Origin";
                break;
        }
        cout << "\tSorting criteria successfully set to '" << sortC << "'!" << endl;
    }

     if(filterC == "Line2D" || filterC == "Line3D"){
        cout << "\ta)\tPt. 1's (x, y) values" << endl;
        cout << "\tb)\tPt. 2's (x, y) values" << endl;
        cout << "\tc)\tLength value" << endl;
        cout << endl;
        cout << "\tPlease enter your criteria (a-c): ";
        cin >> userChoice;

        switch(userChoice)
        {
            case 'a':
                sortC = "Pt. 1";
                break;
            case 'b':
                sortC = "Pt. 2";
                break;
            case 'c':
                sortC = "Length";
                break;
        }
        cout << "\tSorting criteria successfully set to '" << sortC << "'!" << endl;
    }
}

void optionFour(){
    cout << endl;
    cout << "[ Specifying sorting order (current : " << order << ")]";
    cout << endl;
    cout << "\ta)\tASC (Ascending order)" << endl;
    cout << "\tb)\tDSC (Descending order)" << endl;
    cout << endl;
    char userChoice;
    cout << "\tPlease enter your criteria (a-b): ";
    cin >> userChoice;
    switch(userChoice){
        case 'a':
            order = "ASC";
            break;
        case 'b':
            order = "DSC";
            break;
    }
    cout << "\tSorting order successfully set to '" << order << "'!" << endl;
}

void optionFive(){
    cout << endl;
    cout << "[ View data ... ]" << endl;
    cout << "  filtering criteria: " << filterC << endl;
    cout << "  sorting criteria: " << sortC << endl;
    cout << "  sorting order: " << order << endl;
    cout << endl;

    if(filterC == "Point2D"){
        if(order == "ASC"){
            sort(v2DPoint.begin(),v2DPoint.end(),ASC<Point2D>);
        }
        else if(order == "DSC"){
            sort(v2DPoint.begin(),v2DPoint.end(),DSC<Point2D>);
        }
        cout << setw(5) << "X" <<  setw(6) << "Y" << setw(19) << "Dist. Fr Origin" << endl;
        cout << setfill('-') << setw(30) << "-" << endl;
        cout << setfill(' ');

        for(int i=0;i<v2DPoint.size();i++){
        cout << v2DPoint.at(i);
        }
        cout << endl;
        
    }
    else if(filterC == "Point3D"){
        if(order == "ASC"){
            sort(v3DPoint.begin(),v3DPoint.end(),ASC<Point3D>);
        }
        else if(order == "DSC"){
            sort(v3DPoint.begin(),v3DPoint.end(),DSC<Point3D>);
        }

        cout << setw(5) << "X" <<  setw(5) << "Y" << setw(6) << "Z" << setw(19) << "Dist. Fr Origin" << endl;
        cout << setfill('-') << setw(36) << "-" << endl;
        cout << setfill(' ');

        for(int i=0;i<v3DPoint.size();i++){
        cout << v3DPoint.at(i);
        }
        cout << endl;
    }
    else if(filterC == "Line2D"){
        if(order == "ASC"){
            sort(v2DLine.begin(),v2DLine.end(),ASC<Line2D>);
        }
        else if(order == "DSC"){
            sort(v2DLine.begin(),v2DLine.end(),DSC<Line2D>);
        }


        cout << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(4) << "" << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(10) << "Length" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        cout << setfill(' ');

        for(int i=0;i<v2DLine.size();i++){
        cout << v2DLine.at(i);
        }
        cout << endl;
    }
    else if(filterC == "Line3D"){
        if(order == "ASC"){
            sort(v3DLine.begin(),v3DLine.end(),ASC<Line3D>);
        }
        else if(order == "DSC"){
            sort(v3DLine.begin(),v3DLine.end(),DSC<Line3D>);
        }

        cout << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z" << setw(4) << "" << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z" << setw(10) << "Length" << endl;
        cout << setfill('-') << setw(52) << "-" << endl;
        cout << setfill(' ');
        for(int i=0;i<v3DLine.size();i++){
            cout << v3DLine.at(i);
        }
        cout << endl;

    }
    
}

void optionSix(){
    string filename;
    int count = 0;

    cout << endl;
    cout << "Please input file name: ";
    cin >> filename;

    fstream file(filename, ios::out);

    if(filterC == "Point2D"){
        if(order == "ASC"){
            sort(v2DPoint.begin(),v2DPoint.end(),ASC<Point2D>);
        }
        else if(order == "DSC"){
            sort(v2DPoint.begin(),v2DPoint.end(),DSC<Point2D>);
        }
        file << setw(5) << "X" <<  setw(6) << "Y" << setw(19) << "Dist. Fr Origin" << endl;
        file << setfill('-') << setw(30) << "-" << endl;
        file << setfill(' ');

        for(int i=0;i<v2DPoint.size();i++){
            file << v2DPoint.at(i);
            count ++;
        }
        cout << endl;
        
    }
    else if(filterC == "Point3D"){
        if(order == "ASC"){
            sort(v3DPoint.begin(),v3DPoint.end(),ASC<Point3D>);
        }
        else if(order == "DSC"){
            sort(v3DPoint.begin(),v3DPoint.end(),DSC<Point3D>);
        }

        file << setw(5) << "X" <<  setw(5) << "Y" << setw(6) << "Z" << setw(19) << "Dist. Fr Origin" << endl;
        file << setfill('-') << setw(36) << "-" << endl;
        file << setfill(' ');

        for(int i=0;i<v3DPoint.size();i++){
            file << v3DPoint.at(i);
            count++;
        }
        cout << endl;
    }
    else if(filterC == "Line2D"){
        if(order == "ASC"){
            sort(v2DLine.begin(),v2DLine.end(),ASC<Line2D>);
        }
        else if(order == "DSC"){
            sort(v2DLine.begin(),v2DLine.end(),DSC<Line2D>);
        }


        file << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(4) << "" << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(10) << "Length" << endl;
        file << setfill('-') << setw(40) << "-" << endl;
        file << setfill(' ');

        for(int i=0;i<v2DLine.size();i++){
            file << v2DLine.at(i);
            count++;
        }
        cout << endl;
    }
    else if(filterC == "Line3D"){
        if(order == "ASC"){
            sort(v3DLine.begin(),v3DLine.end(),ASC<Line3D>);
        }
        else if(order == "DSC"){
            sort(v3DLine.begin(),v3DLine.end(),DSC<Line3D>);
        }

        file << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z" << setw(4) << "" << setw(5) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z" << setw(10) << "Length" << endl;
        file << setfill('-') << setw(52) << "-" << endl;
        file << setfill(' ');
        for(int i=0;i<v3DLine.size();i++){
            file << v3DLine.at(i);
            count++;
        }
        cout << endl;
    }

    file.close();
    cout << count << " records output successfully!" << endl;
    cout << "Going back to main menu..." << endl;

}

vector<string> splitString (string str, string delim)
{
    vector<string> result;
    size_t pos = 0;
    string token;

    while( (pos = str.find(delim)) != std::string::npos)
    {
        token = str.substr(0,pos);
        result.push_back (token);
        str.erase (0,pos+delim.length());
    }

    if(!str.empty())
        result.push_back(str);
    return(result);

}