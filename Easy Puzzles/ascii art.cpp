#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    
    string keyString="ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    vector<char> keys;
    
    for (int i=0; i < keyString.size(); i++)
        keys.push_back(keyString[i]);
    
    unordered_map<char,vector<string>> charArt;
    
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        
        size_t copyOffset=0;
        for (int j = 0; j < keys.size(); j++) {
            if (i==0) {
                vector<string> v;
                v.push_back(ROW.substr(copyOffset,L));
                charArt[keys.at(j)]=v;
            }
            else
                charArt[keys.at(j)].push_back(ROW.substr(copyOffset,L));
            copyOffset+=L;
        }
    }
    
    for (int i = 0; i < H; i++) {
        string rowString = "";
        for (int j = 0; j<T.size(); j++) {
            char k;
            if (charArt.count(toupper(T[j]))>0) 
                k = toupper(T[j]);
            else
                k = '?';
            
            rowString += charArt[k][i];
        }
        cout << rowString << endl;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}