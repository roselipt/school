/*  Homework 2.2 for Paradigms in C++

*/

#include<iostream>

using namespace std;

enum class Gender {male, female};

int main () {

    string playerOne;
    Gender sex;
    playerOne = "Player One ";
    sex = Gender::female;
    int age = 47;

    cout << playerOne << "\n";
    cout << "age: " << age << "\n";
    //  Following enum will produces errors. Must come back to overload << operator for Gender
    //cout << "sex: " << sex "\n";
    cout << "Here tis.\n";
}