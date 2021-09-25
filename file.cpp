/*  A program to open a file.
*/

#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

int main() {
    char letter;
    string line;

    try {
        ifstream inFile("input.txt");
        if (!inFile.good()) throw string("Failure opening input.txt");
        inFile >> line;
        cout << line;        
        //cout << "Please type a t." << endl;
        //cin >> letter;
        //if (letter != 't') throw string("That's not a t!");
    }
    catch (string message) {
        cout << message << endl;
        exit(1);
    }

    cout << "You entered " << letter << endl;

    cout << "And if my grandmother had wheels she'd be a wagon" << endl;
    return(0);  
    } // close main