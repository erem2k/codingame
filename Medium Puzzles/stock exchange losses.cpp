#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    cin >> n; cin.ignore();
    
    int currentMax=0, currentLoss=0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        
        if (currentMax < v)
            currentMax = v;
            
        if (v - currentMax < currentLoss)
            currentLoss = v - currentMax;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << currentLoss << endl;
}