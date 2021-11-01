/*  HW 2.1

*/

#include <iostream>

using namespace std;

//  The key to understand here that I kept missing is that char* a[] is a pointer to a pointer!
//  
void printArray(int length, char* a[]) {
    for (int i = 0; i < length ; i++) {
        cout << a[i] << "\n";
    }
}

/*void strSwap(char* s1, char* s2) {

}*/

int strLen(const char* s); 
/* returns the length of s (Note: you actually don't need to use this
function in hw2_1, but you will need it in hw2_2)
*/

int strCmp(const char* s1, const char* s2)
/* returns -1 if s1 should appear before s2,
0 if s1 and s2 are exactly the same,
1 if s1 appears after s2. 
All in alphabetic order according to the ASCII table
*/
{
    if (*s1 < *s2) return -1;
    else if (*s1 == *s2) return 0;
    else return 1;
}
void strSwap(char* &s1, char* &s2) {
/* allows two pointers to char* to be swapped, i.e.
afterwards, s1 will point to what s2 was pointing at and vice versa
*/
    char* p; // temporary pointer for swap
    p = s1;
    s1 = s2;
    s2 = p;
}

void strBubbleSort(char* arrStr[], int n);
/* uses bubble sort to put all strings in arrStr
in an alphabetic order. The array has size of n and will be modified as the result of this function
*/

int main(int argc, char *argv[]) {
//  int main(int argc, char **argv) {  /* Alternate form */
    
    char* ptr;
    ptr = argv[0];
    char** pptr;  //  char pointer to pointer
    pptr = argv;
    cout << "Passed as argv: \n" ;
    printArray(argc, argv);
    cout << "And here again using pptr, a pointer to a pointer: \n" ;
    printArray(argc, pptr);

    cout << "And now swapping the second two: \n" ;
    ptr = argv[1];
    argv[1] = argv[2];
    argv[2] = ptr; 
    printArray(argc, argv);

    cout << "And for double plus good measure, once more accessed by pptr, after another swap: \n" ;
    strSwap(argv[3], argv[4]);
    printArray(argc, pptr);

    cout << "And comparing s1 and s2 with strComp yields: " << strCmp(argv[1], argv[2]) 
        << " and the line also show s1 and s2 " << argv[1] << " and " << argv[2] << "\n";
/*  Delete later.
    This was just making sure it worked before I could pass it as reference.
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << "\n";
    }    
*/

}  // close main

/*
This exercise is all about procedural programming (lec3), and specifically the topics of pointers, arrays, and
loops. Write a C++ program that prints out all command line arguments both in their original order and in the
sorted alphabetic order. To demonstrate your grasp of the language's built-in facility, your program should NOT
use any standard library features except for cout from iostream. Specifically you should write your own
versions of the following functions (some of these are named differently from their standard library
counterparts):

int strLen(const char* s); // returns the length of s (Note: you actually don't need to use this
function in hw2_1, but you will need it in hw2_2)

int strCmp(const char* s1, const char* s2); // returns -1 if s1 should appear before s2,
0 if s1 and s2 are exactly the same, 1 if s1 appears after s2. All in alphabetic order according to the ASCII
table

void strSwap(char* &s1, char* &s2); // allows two pointers to char* to be swapped, i.e.
afterwards, s1 will point to what s2 was pointing at and vice versa

void strBubbleSort(char* arrStr[], int n); // uses bubble sort to put all strings in arrStr
in an alphabetic order. The array has size of n and will be modified as the result of this function
Example output
>hw2_1 a quick fox runs quickly over a dog

Your input is:
a
quick
fox
runs
quickly
over
a
dog

Your output is:
a
a
dog
fox
over
quick
quickly
runs

Some Helpful Info
In int main(int argc, char* argv[]){}, the value of argc is 1 plus the actual number of command
line parameters entered after the executable. argv[1] is the first paramter (argv[0] refers to the
executable itself)
Your program should leave argv[] untouched, i.e. do not modify argv[] itself! This means that you need
to allocate memory (using new) to make a copy of argv[], and properly release the memory when you're
done with it.
In the unlikely event that you don't know about bubble sort, please take a look at this wiki article - only
that now we're comparing c-style strings, not integers.
Your program should print an error message and exit if no command line parameters were passed
Please make sure to test with the example shown above

*/