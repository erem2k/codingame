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
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    unordered_map<string,string> mimeMap;
    
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        std::transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        mimeMap[EXT]=MT;
        cerr << EXT << endl;
    }
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        size_t lastIndex = FNAME.find_last_of(".");
        string extension = FNAME.substr(lastIndex+1);
        
        cerr << FNAME << endl;
        
        std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
        
        if (lastIndex==-1) 
            extension="";
            
        if (mimeMap.count(extension)>0)
            cout << mimeMap[extension] << endl;
        else
            cout << "UNKNOWN" << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}