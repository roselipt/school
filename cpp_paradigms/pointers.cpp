/*  Here's where I'll try to understand pointers and arrays
    with integers instead of the array of strings,
    which is an array of arrays,
    which hw2.1 actually asks for.
*/

#include <iostream>
using namespace std;

int main () {
    int length = 10;
    int a[length];

    // Show intial values in array
    for (int i = 0; i != length; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    //  Set values in array to integer equal to index
    for (int i = 0; i != length; i++) {
        a[i] = i;
    }

    cout << "After assignment: ";
    // Show values in array now
    for (int i = 0; i != length; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    cout << "Phew.\n";
}