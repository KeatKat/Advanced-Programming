#include "splitString.h"


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