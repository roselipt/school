/*  HW 1.2 Paradigms in C++
    Tom Budny

Factor integers from a list.

Given the file input.txt
36
48
13
49
27

The output.txt file should look like the following (note: factor 8 was not typed in for 48 in the previous posting):
36 : 2, 3, 4, 6, 9, 12, 18
48 : 2, 3, 4, 6, 8, 12, 16, 24
13 : None
49 : 7
27 : 3, 9

*/

#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

int main() {
    char letter;
    int num;
    bool none;

    try {
        ifstream inFile("input1.2.txt");
        if (!inFile.good()) throw string("Failure opening input.txt");
        inFile >> num;
        while (!inFile.eof()) {
            cout << num << " : ";
            none = true;
            for (int i = 2; i < num; i++) {
                if (num % i == 0) {
                    cout << i << " ";
                    none = false;
                }
            }
            if (none) cout << "None\n";
            else cout << "\n";
            inFile >> num;
        }
    }
    catch (string message) {
        cout << message << endl;
        exit(1);
    }


    cout << "And if my grandmother had wheels she'd be a wagon" << endl;
    return(0);  
    } // close main