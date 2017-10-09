#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    
    list<string> grid;
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        grid.push_back(line);
    }
    
    for (list<string>::iterator it=grid.begin(); it != grid.end(); ++it) {
        //String pass
        static int iteration = 0;
        for (int i=0; i < width; i++) {
            
            int rightX = -1, rightY = -1;
            int bottomX = -1, bottomY = -1;
            
            if ((*it)[i] == '0') {

                //Pass to the right of found node
                for (int p=i+1; p < width; p++) {
                    if ((*it)[p] == '0') {
                        rightX = p;
                        rightY = iteration; 
                        break;
                    }
                }
                //Pass to the bottom of found node
                int bottomIteration = iteration;
                list<string>::iterator bottomIt=it;
                bottomIt++;
                bottomIteration++;
                
                cerr << "\nCurrent node: " << iteration << " " << i << endl;
                
                while (bottomIt!=grid.end()) {
                    cerr << (*bottomIt)[i];
                    if ((*bottomIt)[i] == '0') {
                        bottomX = i;
                        bottomY = bottomIteration;
                        cerr << "\nBottom node: " << bottomX << " " << bottomY << endl;
                        break;
                    }
                    bottomIteration++;
                    bottomIt++;
                }
                cout << i << " " << iteration << " " << rightX << " " << rightY << " " << bottomX << " " << bottomY << endl;
            }
            //If node to the right was found, assign it's X-1 coordinate to i 
            if (rightX > 0)
                i = rightX - 1;
        }
        iteration++;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
}