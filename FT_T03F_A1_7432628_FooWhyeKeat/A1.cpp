#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

//prototype
int mainMenuOptions();
void readIn(string**& weatherGrid,string**& cloudGrid,string**& pressureGrid,string**& cloudGridLMH, string**& pressureGridLMH,string**& cloudAbsoValue, string**& pressureAbsoValue,int& xmin,int& xmax, int& ymin, int& ymax,vector<string>& cityNames,string& cityFile);
vector<string> splitString(string str, string delim);
void buildCityMap(int& xmin,int& xmax, int& ymin, int& ymax, string**& weatherGrid, string cityLoc,string**& cloudGrid,string**& pressureGrid,string clouds, string pressure,string**& cloudGridLMH,string**& pressureGridLMH,string**& cloudAbsoValue,string**& pressureAbsoValue,vector<string>& cityNames);
void displayCityMap(int xmin, int xmax, int ymin, int ymax,string** weatherGrid);
void addCityLocs(string**& weatherGrid,string cityLocs,int xmin,int xmax,int ymin,int ymax,vector<string>& cityNames);
void buildCloudMap(string**& cloudGrid,string**& cloudGridLMH,string**& cloudAbsoValue,string cloudFile,int ymin,int ymax);
void buildPressureMap(string**& pressureGrid,string**& pressureGridLMH,string**& pressureAbsoValue,string pressure,int ymin,int ymax);
void summaryReport(int xmin,int xmax,int ymin, int ymax,vector<string> cityNames,string** weatherGrid, string** cloudAbsoValue, string** pressureAbsoValue, string cityFile);

int main() {
    string** weatherGrid;
    string** cloudGrid;
    string** pressureGrid;
    string** cloudGridLMH;
    string** pressureGridLMH;
    string** cloudAbsoValue;
    string** pressureAbsoValue;
    string cityFile;
    vector<string> cityNames;
    int xmin,xmax,ymin,ymax;
   

    while(true){
        int choice = mainMenuOptions();

        switch(choice) {
        case 1: readIn(weatherGrid,cloudGrid,pressureGrid,cloudGridLMH,pressureGridLMH,cloudAbsoValue, pressureAbsoValue,xmin,xmax,ymin,ymax,cityNames,cityFile);
                break;

        case 2: displayCityMap(xmin,xmax,ymin,ymax,weatherGrid);
                break;
        case 3: displayCityMap(xmin,xmax,ymin,ymax,cloudGrid);
                break;
        case 4: displayCityMap(xmin,xmax,ymin,ymax,cloudGridLMH);
                break;
        case 5: displayCityMap(xmin,xmax,ymin,ymax,pressureGrid);
                break;
        case 6: displayCityMap(xmin,xmax,ymin,ymax,pressureGridLMH);
                break;
        case 7: summaryReport(xmin,xmax,ymin,ymax,cityNames,weatherGrid,cloudAbsoValue,pressureAbsoValue,cityFile);
                                                  
    }
        if(choice == 8){
            break;
        }
    }
    for(int i=0;i<xmin+4;i++) {
        delete[] weatherGrid[i];
    }
    delete[]weatherGrid;

    for(int i=0;i<xmin+4;i++) {
        delete[] cloudGrid[i];
    }
    delete[]cloudGrid;

    for(int i=0;i<xmin+4;i++) {
        delete[] pressureGrid[i];
    }
    delete[]pressureGrid;

    for(int i=0;i<xmin+4;i++) {
        delete[] cloudGridLMH[i];
    }
    delete[]cloudGridLMH;

    for(int i=0;i<xmin+4;i++) {
        delete[] pressureGridLMH[i];
    }
    delete[]pressureGridLMH;

    for(int i=0;i<xmin+4;i++) {
        delete[] cloudAbsoValue[i];
    }
    delete[]cloudAbsoValue;

    for(int i=0;i<xmin+4;i++) {
        delete[] pressureAbsoValue[i];
    }
    delete[]pressureAbsoValue;
    return 0;
    

}

int mainMenuOptions() {
    cout << "Student ID   : 7432628" << endl;
    cout << "Student Name : Foo Whye Keat" << endl;
    cout << "------------------------------" << endl;
    cout << "Welcome to Weather Information Processing System!" << endl;   
    cout << endl;

    cout << "1)\tRead in and process a configuration file" << endl;
    cout << "2)\tDisplay city map" << endl;
    cout << "3)\tDisplay cloud coverage map (cloudiness index)" << endl;
    cout << "4)\tDisplay cloud coverage map (LMH symbols)" << endl;
    cout << "5)\tDisplay atmospheric pressure map (pressure index)" << endl;
    cout << "6)\tDisplay atmospheric pressure map (LMH symbols)" << endl;
    cout << "7)\tShow weather forecast summary report" << endl;
    cout << "8)\tQuit" << endl;
    cout << endl;

    cout << "PLease enter your choice : ";
    int menuChoice;
    cin >> menuChoice;

    return menuChoice;   
}


void readIn(string**& weatherGrid,string**& cloudGrid,string**& pressureGrid,string**& cloudGridLMH, string**& pressureGridLMH,string**& cloudAbsoValue, string**& pressureAbsoValue,int& xmin,int& xmax, int& ymin, int& ymax,vector<string>& cityNames,string& cityFile) {
    cout << endl;
    cout << "[ Read in and process a configuration file ]" << endl;
    cout << "PLease enter config filename : ";

    string fileName;
    cin >> fileName;
    cin.clear();
    ifstream dataIn;
    dataIn.open(fileName);

    vector <string> files;
    vector <int> ranges;

    while(dataIn.good()) {
        string data;
        getline (dataIn,data);
        if(data == "" || data[0] == '/') continue;

        files.push_back(data);
    
    }
    
    string gridx,gridy,cityLoc,clouds,pressure;
    gridx = files.at(0);
    gridy = files.at(1);
    cityLoc = files.at(2);
    clouds = files.at(3);
    pressure = files.at(4);

    cityFile = cityLoc;

    /*Extracting the numbers from gridX and gridY*/
    vector<string> gridxSplit = splitString(gridx,"=");
    vector<string> gridxRange = splitString(gridxSplit.at(1),"-");
    xmin = stoi(gridxRange.at(0));
    xmax = stoi(gridxRange.at(1));

    vector<string> gridySplit = splitString(gridy,"=");
    vector<string> gridyRange = splitString(gridySplit.at(1),"-");
    ymin = stoi(gridyRange.at(0));
    ymax = stoi(gridyRange.at(1));

    buildCityMap(xmin,xmax,ymin,ymax,weatherGrid,cityLoc,cloudGrid,pressureGrid,clouds,pressure,cloudGridLMH,pressureGridLMH,cloudAbsoValue,pressureAbsoValue,cityNames);
    cout << endl;
    cout << "Reading in " << gridx << " ... done!" << endl;
    cout << "Reading in " << gridy << " ... done!" << endl;
    cout << endl;
    cout << "Storing data from input file :" << endl;
    cout << cityLoc << " ... done!" << endl;
    cout << clouds << " ... done!" << endl;
    cout << pressure << " ... done!" << endl;
    cout << endl;
    cout << "All records successfully stored. Going back to main menu ..." << endl;
    dataIn.close();

   


}

void buildCityMap(int& xmin,int& xmax, int& ymin, int& ymax, string**& weatherGrid, string cityLoc,string**& cloudGrid,string**& pressureGrid,string clouds, string pressure,string**& cloudGridLMH,string**& pressureGridLMH,string**& cloudAbsoValue,string**& pressureAbsoValue,vector<string>& cityNames) {
    int xSize = xmax +4;
    int ySize = ymax +4;

    weatherGrid = new string*[ySize];
    for(int i=0;i<ySize;i++) {
        weatherGrid[i] = new string[xSize];
    }
    cloudGrid = new string*[ySize];
    for(int i=0;i<ySize;i++) {
        cloudGrid[i] = new string[xSize];
    }
    cloudGridLMH = new string*[ySize];
    for(int i=0;i<ySize;i++) {
        cloudGridLMH[i] = new string[xSize];
    }
    pressureGrid = new string*[ySize];
    for(int i=0;i<ySize;i++) {
        pressureGrid[i] = new string[xSize];
    }
    pressureGridLMH = new string*[ySize];
    for(int i=0;i<ySize;i++) {
        pressureGridLMH[i] = new string[xSize];
    }
    cloudAbsoValue = new string*[ySize];
    for(int i=0;i<ySize;i++) {
        cloudAbsoValue[i] = new string[xSize];
    }
    pressureAbsoValue = new string*[ySize];
    for(int i=0;i<ySize;i++) {
        pressureAbsoValue[i] = new string[xSize];
    }

    //numbers appear from row 1 (min+1) to row 9 (size-2)
    //yaxis numbers
    int county = ymax;
   for (int i = 0; i <= ymax-ymin; i++) {
        weatherGrid[i+1][0] = to_string(county);
        cloudGrid[i+1][0] = to_string(county);
        pressureGrid[i+1][0] = to_string(county);
        cloudGridLMH[i+1][0] = to_string(county);
        pressureGridLMH[i+1][0] = to_string(county);
        cloudAbsoValue[i+1][0] = to_string(county);
        pressureAbsoValue[i+1][0] = to_string(county);
        county--;
   }
    //numbers appear from col3(xmin+2) to col 11(size-1)
    //xaxis numbers
    int countx = xmin;
     for (int i =0; i <= xmax-xmin; i++){
        weatherGrid[ySize-1][i+2] = to_string(countx);
        cloudGrid[ySize-1][i+2] = to_string(countx);
        cloudGridLMH[ySize-1][i+2] = to_string(countx);
        pressureGrid[ySize-1][i+2] = to_string(countx);
        pressureGridLMH[ySize-1][i+2] = to_string(countx);
        pressureAbsoValue[ySize-1][i+2] = to_string(countx);
        cloudAbsoValue[ySize-1][i+2] = to_string(countx);
        countx++;
   }
    //yaxis hex col1
    //hex starts from row 0(min) to row 10 (size-1)
    for (int i =1; i <= xSize-1; i++){
        weatherGrid[ySize-2][i] = "#";
        cloudGrid[ySize-2][i] = "#";
        cloudGridLMH[ySize-2][i] = "#";
        pressureGrid[ySize-2][i] = "#";
        pressureGridLMH[ySize-2][i] = "#";
        cloudAbsoValue[ySize-2][i] = "#";
        pressureAbsoValue[ySize-2][i] = "#";
   }
    //xaxis column hex
   for (int i =0; i <= xSize-2; i++){
        weatherGrid[0][i+1] = "#";
        cloudGrid[0][i+1] = "#";
        cloudGridLMH[0][i+1] = "#";
        pressureGrid[0][i+1] = "#";
        pressureGridLMH[0][i+1] = "#";
        cloudAbsoValue[0][i+1] = "#";
        pressureAbsoValue[0][i+1] = "#";
   }
   for (int i =0; i < ySize-2; i++){
        weatherGrid[i+1][1] = "#";
        cloudGrid[i+1][1] = "#";
        cloudGridLMH[i+1][1] = "#";
        pressureGrid[i+1][1] = "#";
        pressureGridLMH[i+1][1] = "#";
        cloudAbsoValue[i+1][1] = "#";
        pressureAbsoValue[i+1][1] = "#";
   }
   for (int i =0; i < ySize-2; i++){
        weatherGrid[i+1][xSize-1] = "#";
        cloudGrid[i+1][xSize-1] = "#";
        cloudGridLMH[i+1][xSize-1] = "#";
        pressureGrid[i+1][xSize-1] = "#";
        pressureGridLMH[i+1][xSize-1] = "#";
        cloudAbsoValue[i+1][xSize-1] = "#";
        pressureAbsoValue[i+1][xSize-1] = "#";
   }
    
    for(int i=0;i<ySize;i++){
        for(int j=0;j<xSize;j++) {
            if(weatherGrid[i][j] == "")
                weatherGrid[i][j] = " ";
            
        }
    }

    buildCloudMap(cloudGrid,cloudGridLMH,cloudAbsoValue,clouds,ymin,ymax);//pass over the skeleton
    buildPressureMap(pressureGrid,pressureGridLMH,pressureAbsoValue,pressure,ymin,ymax);
    addCityLocs(weatherGrid,cityLoc,xmin,xmax,ymin,ymax,cityNames);

}

void addCityLocs(string**& weatherGrid,string cityLocs,int xmin,int xmax,int ymin,int ymax,vector<string>& cityNames) 
{
    ifstream cityIn;
    cityIn.open(cityLocs);

    while(!cityIn.eof()){
        vector<string> cityLines;
        vector<string> coordinates;
        string position;
        getline(cityIn,position);
        if (position == "") continue;
        cityLines = splitString(position,"-");//split into 3
        coordinates = splitString(cityLines.at(0),",");//split first value into x and y coordinates
        string xCoord;
        string yCoord;
        string cityName = cityLines.at(1);
        cityNames.push_back(cityName);

        int truexSize = (xmax - xmin) +3;
        int trueySize = (ymax - ymin) +3;
        
        //getting rid of brackets and other chars 
        string xMess = coordinates.at(0);
        xMess.erase(remove(xMess.begin(),xMess.end(),'['));
        string yMess = coordinates.at(1);
        yMess.erase(remove(yMess.begin(),yMess.end(),']'));

        xCoord = xMess;
        yCoord = yMess;



       
        int truexCoord = stoi(xCoord) +2;
        int trueyCoord = trueySize - (stoi(yCoord) +2);
        //offset the x and y coords by 2 and then mark the location
       
        weatherGrid[trueyCoord][truexCoord] = cityName;
        
    }
    cityIn.close();
   
   
}

void buildCloudMap(string**& cloudGrid,string**& cloudGridLMH,string**& cloudAbsoValue,string cloudFile,int ymin,int ymax){
    ifstream cloudsIn;
    cloudsIn.open(cloudFile);

    while(cloudsIn.good()){
        vector<string> cloudLines;
        vector<string> coordinates;
        string position;
        getline(cloudsIn,position);
        if(position == "") continue;
        cloudLines = splitString(position,"-");//split into 2
        coordinates = splitString(cloudLines.at(0),",");//split first value into x and y coordinates
        string xCoord;
        string yCoord;
        //getting rid of brackets and unwanted chars
        //getting rid of brackets and other chars 
        string xMess = coordinates.at(0);
        xMess.erase(remove(xMess.begin(),xMess.end(),'['));
        string yMess = coordinates.at(1);
        yMess.erase(remove(yMess.begin(),yMess.end(),']'));

        xCoord = xMess;
        yCoord = yMess;
        int trueySize = (ymax - ymin) +3;
        int truexCoord = stoi(xCoord) +2;
        int trueyCoord = trueySize - (stoi(yCoord) +2);
        string cloudIndex;
        string coverValue = cloudLines.at(1);
        cloudAbsoValue[trueyCoord][truexCoord] = coverValue;
        if(coverValue.size() == 1){
            cloudIndex = '0';
        }
        else{
            cloudIndex = coverValue[0];
            
        }
        cloudGrid[trueyCoord][truexCoord] = cloudIndex;

        int cloudCover = stoi(coverValue);
        string cloudSymbol;
        if(cloudCover < 35){
            cloudSymbol = 'L';
        }
        else if (cloudCover <65)
        {
            cloudSymbol = 'M';
        }
        else{
            cloudSymbol = 'H';
        }
        
        cloudGridLMH[trueyCoord][truexCoord] = cloudSymbol;
        
    }
    cloudsIn.close();
}

void buildPressureMap(string**& pressureGrid,string**& pressureGridLMH,string**& pressureAbsoValue,string pressureFile,int ymin,int ymax){
    ifstream pressureIn;
    pressureIn.open(pressureFile);

    while(pressureIn.good()){
        vector<string> pressureLines;
        vector<string> coordinates;
        string position;
        getline(pressureIn,position);
        if(position == "") continue;
        pressureLines = splitString(position,"-");//split into 2
        coordinates = splitString(pressureLines.at(0),",");//split first value into x and y coordinates
        string xCoord;
        string yCoord;
        //getting rid of brackets and unwanted chars
        //getting rid of brackets and other chars 
        string xMess = coordinates.at(0);
        xMess.erase(remove(xMess.begin(),xMess.end(),'['));
        string yMess = coordinates.at(1);
        yMess.erase(remove(yMess.begin(),yMess.end(),']'));

        xCoord = xMess;
        yCoord = yMess;
        int trueySize = (ymax - ymin) +3;
        int truexCoord = stoi(xCoord) +2;
        int trueyCoord = trueySize - (stoi(yCoord) +2);
        string pressureIndex;
        string pressureValue = pressureLines.at(1);
        pressureAbsoValue[trueyCoord][truexCoord] = pressureValue;
        if(pressureValue.size() == 1){
            pressureIndex = '0';
        }
        else{
            pressureIndex = pressureValue[0];
            
        }
        pressureGrid[trueyCoord][truexCoord] = pressureIndex;

        int pressureCover = stoi(pressureValue);
        string pressureSymbol;
        if(pressureCover < 35){
            pressureSymbol = 'L';
        }
        else if (pressureCover <65)
        {
            pressureSymbol = 'M';
        }
        else{
            pressureSymbol = 'H';
        }
        
        pressureGridLMH[trueyCoord][truexCoord] = pressureSymbol;
        
    }
    pressureIn.close();
}

void summaryReport(int xmin,int xmax,int ymin, int ymax,vector<string> cityNames,string** weatherGrid, string** cloudAbsoValue, string** pressureAbsoValue, string cityFile){

    //get unique values from the vector of citynames
    //sort the values first because the unique function can only sort through consecutive same values
    cout << endl;
    ifstream cityIn;
    cityIn.open(cityFile);
    vector<string> cityNameSplit;
    vector<string> cityNameId;
    int xSize = xmax +4;
    int ySize = ymax +4;

    while(cityIn.good()){
        string line;
        string nameId;
        getline(cityIn,line);
        if(line == "")continue;
        cityNameSplit = splitString(line,"-");
        nameId = cityNameSplit.at(1) + "-" + cityNameSplit.at(2);
        cityNameId.push_back(nameId);
    }
    cityIn.close();
    //unique can only differentiate consecutive values so we sort first before calling 
    //the unique function
    sort(cityNameId.begin(),cityNameId.end());
    auto uniqueNames = unique(cityNameId.begin(),cityNameId.end());
    cityNameId.resize(distance(cityNameId.begin(), uniqueNames));

    //summary report start
    cout << "Weather Forecast Summary Report" << endl;
    cout << "-------------------------------" << endl;

    
    float avgPressure,avgClouds,avgPTotal,avgCTotal;
    for(int i=0; i<cityNameId.size();i++){
        avgPressure = 0;
        avgClouds = 0;
        avgPTotal = 0;
        avgCTotal = 0;
        vector<string> splitNameId;
        splitNameId = splitString(cityNameId.at(i),"-");
        string nameOfCity = splitNameId.at(1);
        string IDofCity = splitNameId.at(0);
        //calculating avg cloud pressure
        for(int i=0;i<ySize-1;i++){
            for(int j=1;j<xSize;j++) {
                if(weatherGrid[i][j] == IDofCity){
                    //offset the x and y coords by 2 and then mark the location
                    if(weatherGrid[i+1][j+1]==" "){
                        weatherGrid[i+1][j+1]="o";
                    }
                    if(weatherGrid[i][j+1]==" "){
                        weatherGrid[i][j+1]="o";
                    }
                    if(weatherGrid[i-1][j+1]==" "){
                        weatherGrid[i-1][j+1]="o";
                    }
                    if(weatherGrid[i-1][j]==" "){
                        weatherGrid[i-1][j]="o";
                    }
                    if(weatherGrid[i+1][j]==" "){
                        weatherGrid[i+1][j]="o";
                    }
                    if(weatherGrid[i-1][j-1]==" "){
                        weatherGrid[i-1][j-1]="o";
                    }
                    if(weatherGrid[i][j-1]==" "){
                        weatherGrid[i][j-1]="o";
                    }
                    if(weatherGrid[i+1][j-1]==" "){
                        weatherGrid[i+1][j-1]="o";
                    }
                } 
            }
        }   
        float count = 0.0;
        for(int i=0;i<ySize-1;i++){
            for(int j=1;j<xSize;j++) {
                if(weatherGrid[i][j] == IDofCity || weatherGrid[i][j] == "o"){
                    
                    avgClouds = stof(cloudAbsoValue[i][j]);
                    avgCTotal += avgClouds;

                    avgPressure = stof(pressureAbsoValue[i][j]);
                    avgPTotal += avgPressure;
                    count++;
                }
            }
        }
        avgCTotal = avgCTotal/count;
        avgPTotal = avgPTotal/count;

        string cloudSymbol;
        if(avgCTotal < 35.0){
            cloudSymbol = 'L';
        }
        else if (avgCTotal < 65.0){
            cloudSymbol = 'M';
        }
        else{
            cloudSymbol = 'H';
        }

        string pressureSymbol;
        if(avgPTotal < 35.0){
            pressureSymbol = 'L';
        }
        else if (avgPTotal < 65.0){
            pressureSymbol = 'M';
        }
        else{
            pressureSymbol = 'H';
        }

        float rainProb;
        string rainSymbol;
        if(pressureSymbol == "L" && cloudSymbol == "H"){
            rainProb = 90.0;
            rainSymbol = "~~~~\n~~~~~\n\\\\\\\\\\";
        }
        else if(pressureSymbol == "L" && cloudSymbol == "M"){
            rainProb = 80.0;
            rainSymbol = "~~~~\n~~~~~\n \\\\\\\\";
        }
        else if(pressureSymbol == "L" && cloudSymbol == "L"){
            rainProb = 70.0;
            rainSymbol = "~~~~\n~~~~~\n  \\\\\\";
        }
        else if(pressureSymbol == "M" && cloudSymbol == "H"){
            rainProb = 60.0;
            rainSymbol = "~~~~\n~~~~~\n   \\\\";
        }
        else if(pressureSymbol == "M" && cloudSymbol == "M"){
            rainProb = 50.0;
            rainSymbol = "~~~~\n~~~~~\n    \\";
        }
        else if(pressureSymbol == "M" && cloudSymbol == "L"){
            rainProb = 40.0;
            rainSymbol = "~~~~\n~~~~~";
        }
        else if(pressureSymbol == "H" && cloudSymbol == "H"){
            rainProb = 30.0;
            rainSymbol = "~~~\n~~~~";
        }
        else if(pressureSymbol == "H" && cloudSymbol == "M"){
            rainProb = 20.0;
            rainSymbol = "~~\n~~~";
        }
        else if(pressureSymbol == "H" && cloudSymbol == "L"){
            rainProb = 10.0;
            rainSymbol = "~\n~~";
        }
        cout << "City Name : " << nameOfCity << endl;
        cout << "City ID   : " << IDofCity << endl;
        cout << "Ave. Cloud Cover (ACC) : " << ceil(avgCTotal*100.0)/100.0 << " (" << cloudSymbol << ")" << endl;
        cout << "Ave. Pressure    (AP)  : " << ceil(avgPTotal*100.0)/100.0 << " (" << pressureSymbol << ")" << endl;
        cout << "Probability of Rain (%) : " << ceil(rainProb*100.0)/100.0 << endl;
        cout << rainSymbol<<endl;;

        //clear the perimeter
        for(int i=0;i<ySize-1;i++){
                for(int j=1;j<xSize;j++) {
                    if(weatherGrid[i][j] == "o"){
                        weatherGrid[i][j] = " ";
                    }
                }
            }
    }
    cout << endl;
    char back;
    while(cin.get(back)){
        cout<<"Press <enter> to return to main menu" << endl;
        cin.ignore();
        if(back == '\n')
            break;
    }
    
}

void displayCityMap(int xmin, int xmax, int ymin, int ymax,string** weatherGrid){
    int xSize = xmax +4;
    int ySize = ymax +4;
    for(int i=0;i<ySize;i++){
        for(int j=0;j<xSize;j++) {
            if(weatherGrid[i][j] == "")
                weatherGrid[i][j] = " ";
            string trailing;
            if (j == (xSize-1)) {
                trailing = "\n";
            }
            else {
                trailing = "  ";
            }
            cout << weatherGrid[i][j] << trailing;
        }
    }
    cout << endl;
    char back;
    while(cin.get(back)){
        cout<<"Press <enter> to return to main menu" << endl;
        cin.ignore();
        if(back == '\n')
            break;
    }
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