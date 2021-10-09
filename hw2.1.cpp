/*  HW 2.1
*/

#include <iostream>

using namespace std;

int main() {

    int x = 5;
    int y = 10;

    cout << "x is " << x << " so x++ will use and then augment, see " << x++ << " and " << x << "\n";
    cout << "++x will increment and then use, like this " << ++x << " and now x is " << x << "\n";
    x+=y;
    cout << "x+=y likewise will perform its calculation before using to we'll expect 17 : " << x << "\n";
    cout << "The interesting I learned there was that the += operation could not be used inline with cout, \n";
    cout << "but as soon as I placed it on its own line with a semicolon it worked as expected. \n";
    
    cout << "aimghwsbaw.\n";

}