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
string selectDirection(int currentPos, int targetPos)
{
    if ((currentPos-targetPos)>0)
        return "LEFT";
    else
        return "RIGHT";
}
 
int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    
    unordered_map<int,int> elevatorMap;
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        elevatorMap[elevatorFloor]=elevatorPos;
    }

    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        
        if (cloneFloor>=0) {
            if (clonePos!=elevatorMap[cloneFloor]) {
                if (cloneFloor==exitFloor) {
                    if (direction==selectDirection(clonePos,exitPos))
                        cout << "WAIT" << endl;
                    else
                        cout << "BLOCK" << endl;
                    continue;
                }
        
                if (elevatorMap.count(cloneFloor)>0) {
                    if (direction==selectDirection(clonePos,elevatorMap[cloneFloor]))
                       cout << "WAIT" << endl;
                    else
                        cout << "BLOCK" << endl;
                    continue;            
                }
            }
            else
                cout << "WAIT" << endl;
        }
        else
            cout << "WAIT" << endl;
    }
}