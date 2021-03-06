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
    int n; // the number of temperatures to analyse
    int minT = 5527;
    cin >> n; cin.ignore();
    
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        
        cin >> t; cin.ignore();
        
        if (abs(t) < abs(minT))
            minT = t;
        
        if (abs(t) == abs(minT)) 
            if (t > 0)
                minT = t;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if (n!=0)
        cout << minT << endl;
    else
        cout << 0 << endl;
}