#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    string codedMessage="";

    bool isCbSequence = false, isSbSequence = false;

    for (int i=0; i<MESSAGE.size(); i++) {
        bitset<8> bset(MESSAGE.c_str()[i]);

        for(int j=6; j>=0; j--) {
            if (bset[j]) {
                if (isSbSequence)
                    codedMessage+='0';
                else {
                    if (isCbSequence)
                        codedMessage+=' ';

                    codedMessage+="0 ";
                    isCbSequence=false;
                    isSbSequence=true;
                    codedMessage+='0';
                }
            }
            else {
                if (isCbSequence)
                    codedMessage+='0';
                else {
                    if (isSbSequence)
                        codedMessage+=' ';

                    codedMessage+="00 ";
                    isCbSequence=true;
                    isSbSequence=false;
                    codedMessage+='0';
                }
            }
        }

    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cout << codedMessage << endl;
}