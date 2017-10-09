#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "math.h"

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

//Convenience class 
struct Defib {
    Defib(vector<string> initVector) 
    {
        id_ = atoi(initVector.at(0).c_str());
        name_ = initVector.at(1);
        address_ = initVector.at(2);
        phone_ = initVector.at(3);
        
        for (int i=4; i<6; i++) {
            size_t found = initVector.at(i).find_first_of(',');
            if (found != string::npos)
                initVector[i].replace(found,1,".");
        }
        
        double degLon = strtod(initVector.at(4).c_str(),nullptr);
        double degLat = strtod(initVector.at(5).c_str(),nullptr);
        
        radLon_ = degLon * (M_PI/180);
        radLat_ = degLat * (M_PI/180);
    }
    
    int id_;
    string name_;
    string address_;
    string phone_;
    double radLon_;
    double radLat_;
};

vector<string> splitString(string s, char c)
{
    vector<string> resultVector;
    size_t startIndex=0, endIndex;
     
    while (startIndex!=string::npos || startIndex<s.size()) {
        endIndex=s.find_first_of(c,startIndex);
        
        if (endIndex!=string::npos)
            resultVector.push_back(s.substr(startIndex,endIndex-startIndex));
        else
        {
            resultVector.push_back(s.substr(startIndex));
            break;
        }
            
        startIndex=endIndex+1;
    }
    
    return resultVector;
}

string replaceChar(string s, char target, string replacement, size_t index=0)
{
    size_t found = s.find_first_of(target);
    
    if (found != string::npos)
        s.replace(found,1,replacement);
        
    return s;
}

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    
    double radLON, radLAT;
    
    radLON=strtod(replaceChar(LON,',',".").c_str(),nullptr);
    radLAT=strtod(replaceChar(LAT,',',".").c_str(),nullptr);
    
    radLON*= (M_PI/180);
    radLAT*= (M_PI/180);
     
    int N;
    cin >> N; cin.ignore();   
    
    double minDistance=numeric_limits<double>::max();
    string closestDefibName="";
    
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
              
        Defib d(splitString(DEFIB, ';'));
                       
        double distance=sqrt(pow((d.radLon_ - radLON),2) + pow((d.radLat_ - radLAT),2));
        
        /*cerr << "Iteration "<< i << endl;
        cerr << "Entry name "<< d.name_ << endl;        
        cerr << "Distance "<< distance << endl;

        cerr << "Last minimal distance "<< minDistance << endl;
        */
        if(fabs(distance)<fabs(minDistance)) {
            minDistance = distance;
            closestDefibName = d.name_;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << closestDefibName << endl;
}