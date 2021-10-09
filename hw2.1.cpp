/*  HW 2.1
This exercise is all about procedural programming (lec3), and specifically the topics of pointers, arrays, and
loops. Write a C++ program that prints out all command line arguments both in their original order and in the
sorted alphabetic order. To demonstrate your grasp of the language's built-in facility, your program should NOT
use any standard library features except for cout from iostream. Specifically you should write your own
versions of the following functions (some of these are named differently from their standard library
counterparts):

*/

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    for (int i = 0; i < argc ; i++) {
        cout << argv[i] << "\n";
    }
    cout << "aimghwsbaw.\n";

}