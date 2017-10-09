#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

template<typename Out>

void split(const std::string &s, char delim, Out result)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
//It's not really beautiful, but it works
bool isEnterable (int roomType, string toFromCurrent)
{
    switch(roomType) {
        case 0:
            return false;
        case 1:
            if (toFromCurrent == "B" || toFromCurrent == "L" || toFromCurrent == "R")
                return true;
            else
                return false;
        case 2:
            if (toFromCurrent == "L" || toFromCurrent == "R")
                return true;
            else
                return false;
        case 3:
            if (toFromCurrent == "B")
                return true;
            else
                return false;
        case 4:
            if (toFromCurrent == "B" || toFromCurrent == "L")
                return true;
            else
                return false;
        case 5:
            if (toFromCurrent == "B" || toFromCurrent == "R")
                return true;
            else
                return false;
        case 6:
            if (toFromCurrent == "L" || toFromCurrent == "R")
                return true;
            else
                return false;
        case 7:
            if (toFromCurrent == "L" || toFromCurrent == "B")
                return true;
            else
                return false;
        case 8:
            if (toFromCurrent == "L" || toFromCurrent == "R")
                return true;
            else
                return false;
        case 9:
            if (toFromCurrent == "B" || toFromCurrent == "R")
                return true;
            else
                return false;
        case 10:
        case 11:
            if (toFromCurrent == "B")
                return true;
            else
                return false;            
        case 12:
            if (toFromCurrent == "L")
                return true;
            else
                return false;            
        case 13:
            if (toFromCurrent == "R")
                return true;
            else
                return false;            
        default:
            return false;
        }
}

bool isExitable (int roomType, string to, string from)
{
        switch(roomType) {
        case 0:
            return false;
        case 1:
            if ((to == "B") && (from == "TOP" || from == "LEFT" || from == "RIGHT"))
                return true;
            else
                return false;
        case 2:
            if ((to == "L" && from == "RIGHT") || (to == "R" && from == "LEFT"))
                return true;
            else
                return false;
        case 3:
            if (to == "B" && from  == "TOP")
                return true;
            else
                return false;
        case 4:
            if ((to == "B" && from == "RIGHT" ) || (to == "L" && from == "TOP"))
                return true;
            else
                return false;
        case 5:
            if ((to == "B" && from == "LEFT") || (to == "R" && from == "TOP"))
                return true;
            else
                return false;
        case 6:
            if ((to == "L" && from == "RIGHT" ) || (to == "R" && from == "LEFT"))
                return true;
            else
                return false;
        case 7:
            if ((to == "B") && (from == "RIGHT" || from == "TOP"))
                return true;
            else
                return false;
        case 8:
            if ((to == "B") && (from == "LEFT" || from == "RIGHT"))
                return true;
            else
                return false;
        case 9:
            if ((to == "B") && (from == "LEFT" || from == "TOP"))
                return true;
            else
                return false;
        case 10:
            if (to == "L" && from == "TOP")
                return true;
            else
                return false;         
        case 11:
            if (to == "R" && from == "TOP")
                return true;
            else
                return false;            
        case 12:
            if (to == "B" && from == "RIGHT")
                return true;
            else
                return false;            
        case 13:
            if (to == "B" && from == "LEFT")
                return true;
            else
                return false;            
        default:
            return false;
        }
}

int main()
{
    int W; // number of columns.
    int H; // number of rows.
    
    cin >> W >> H; cin.ignore();
    vector<vector<int>> rooms;
    
    for (int i = 0; i < H; i++) {
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        vector<int> currentRow;
        
        getline(cin, LINE);
        
        for (string& s : split(LINE,' '))
            currentRow.push_back(atoi(s.c_str()));
            
        rooms.push_back(currentRow);
    }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();
    
    
    // game loop
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        
        cerr << "New iteration" << endl;
        cerr << "Size of rooms: " << rooms.size() << endl;
        cerr << "Current room type: " << rooms[YI][XI] << endl;
        cerr << "POS: " << POS << endl;
        //Check left cell
        if ((XI - 1 >= 0) && (POS != "LEFT") && (isExitable(rooms[YI][XI], "L", POS))) {
            cerr << "Left check entered" << endl;
            cerr << "Room type: " << rooms[YI][XI-1] << endl;            
            if (isEnterable(rooms[YI][XI-1],"L")) {
                cout << XI-1 << " " << YI << endl;
                cerr << "Character goes to left cell" << endl;
                continue;
            }
        }
        cerr << "Left cell checked" << endl;
        //Check bottom cell
        if ((YI + 1 < rooms.size()) && (isExitable(rooms[YI][XI], "B", POS))) {
            cerr << "Bottom check entered" << endl;
            cerr << "Room type: " << rooms[YI+1][XI] << endl;
            if (isEnterable(rooms[YI+1][XI],"B")) {
                cout << XI << " " << YI+1 << endl;
                cerr << "Character goes to bottom cell" << endl;
                continue;
            }
        }
        cerr << "Bottom cell checked" << endl;
        //Check right cell
        if ((XI + 1 < rooms.at(YI).size()) && (POS != "RIGHT") && (isExitable(rooms[YI][XI], "R", POS))) {
            cerr << "Right check entered" << endl;
            cerr << "Room type: " << rooms[YI][XI+1] << endl;             
            if (isEnterable(rooms[YI][XI+1],"R")) {
                cout << XI+1 << " " << YI << endl;
                cerr << "Character goes to right cell" << endl;
                continue;
            }
        }            
        cerr << "Right cell checked" << endl;
    }
}
