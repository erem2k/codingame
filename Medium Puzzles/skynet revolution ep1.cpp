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
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    
    vector<vector<int>> graphLinks(N); // Vector is square matrix holding all links between nodes
    vector<int> exitNodes;
    
    /*Graph matrix init*/
    for (vector<int>& v : graphLinks)
        v = vector<int> (N,0);
    
    for (int i = 0; i < N; i++)
        graphLinks[i][i] = -1;
    /**/
    
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        
        graphLinks[N1][N2] = 1;
        graphLinks[N2][N1] = 1;
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        exitNodes.push_back(EI);
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        //First pass - check gate's neighbouring nodes for imposter
        cerr << "New iteration" << endl;
        cerr << "First pass:" << endl;
        bool isFound = false;
        for (int i = 0; i < E; i++) {
            cerr << "Gate " << i << " , gate node " << exitNodes[i] << endl;
            for (int j = 0; j < N; j++) {
                cerr << "Checking if node " << j << " is neighbour" << endl;
                if (graphLinks[exitNodes[i]][j] == 1) {
                    cerr << "It is neighbour" << endl;
                    if (j == SI) {
                        cerr << "Found imposter! Severing link" << endl;
                        cout << exitNodes[i] << " " << j << endl;
                        isFound = true;
                        break;
                    }
                }
            }
            if (isFound)
                break;
        }
        if (isFound)
            continue;
        cerr << "First pass complete" << endl;
        //Second pass - if neighboring links are safe, search one level deeper 
        for (int i = 0; i < E; i++) {
            for (int j = 0; j < N; j++) {
                if (graphLinks[exitNodes[i]][j] == 1) { //If node IS neighbor
                    for (int k = 0; k < N; k++) {
                        if (graphLinks[j][k] == 1 && k == SI) {
                            cout << j << " " << k << endl;
                            isFound = true;
                            break;
                        }
                    }
                }
                if (isFound)
                    break;
            }
            if (isFound)
                break;
        }
        cerr << "Second pass complete" << endl;
    }
}