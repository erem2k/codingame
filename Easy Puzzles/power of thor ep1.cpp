#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
    
    int currentX = initialTX;
    int currentY = initialTY;
    
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();
        
        int distanceX = lightX-currentX;
        int distanceY = lightY-currentY;
        
        cerr << distanceX << endl;
        cerr << distanceY << endl;
        
        if (distanceX==0 && distanceY!=0) {
            (distanceY>0) ? (cout << "S" << endl,  currentY++): 
            (cout << "N" << endl, currentY--);
        }

        
        if (distanceX!=0 && distanceY==0) {
            (distanceX>0) ? (cout << "E" << endl, currentX++): 
            (cout << "W" << endl, currentX--);
        }
            
        
        if (distanceX>0 && distanceY!=0)  {
            currentX++;
            (distanceY>0) ? (cout << "SE" << endl, currentY++) : 
            (cout << "NE" << endl, currentY--);
        }
        
        if (distanceX<0 && distanceY!=0) {
            currentX--;
            (distanceY>0) ? (cout << "SW" << endl, currentY++) : 
            (cout << "NW" << endl, currentY--);
        }
    }
}