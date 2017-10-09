#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <forward_list>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    forward_list<int> horses;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horses.push_front(Pi);
    }
    horses.sort();
    int difference=numeric_limits<int>::max();
    
    for (auto it=horses.begin(); it!=horses.end(); ++it) {
        auto nextIt = it;
        nextIt++;
        if (nextIt!=horses.end())
            if (abs(*nextIt-*it)<difference)
                difference=abs(*nextIt-*it);
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << difference << endl;
}