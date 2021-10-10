//  Homework 2.1 for Paradigms in C++
//  Tom Budny
//  
//  The home work asks that we take an array of words
//  as arguments passed from command line and sort them
//  using bubble sort.
//  A function strComp will work with references only;
//  that function could not change the words.
//  A function strSwap will work with pointers to make the swap.

#include <iostream>
#include <string>

using namespace std;


//  This signature is straight from HW spec
//  It confused me for a along time
//  Can it / should it be thought of as & prefix operator acting on arguments in function call?
void strSwap(char* &s1, char* &s2) 
{
    char* temp; //  variable to hold string
    temp = s1;
    s1 = s2;
    s2 = temp;
}    


//  Function header from homework specs 
//  Compares two strings, returning
//  -1 when s1 < s2, meaning already in order
//  0 when same
//  1 when s1 > s2 
int strComp(const char* s1, const char* s2)
{
    if (*s1 > *s2)
        return 1;   //  out of order case
    else if (*s1 == *s2)
        return 0;   //  same case
    else
    {
        return -1;  //  in order case
    }
    
}

//  Bubble sort steps through a list in order
//  comparing side by side elements and correcting
//  their order. It stops when it makes a pass
//  with no changes needed. That will mean the list is in order. 
void strBubbleSort(char* arrStr[], int n)
{
    //  strComp must be declared in this scope
    int strComp(const char* s1, const char* s2);

    bool sorted = false;
    while (!sorted)
    {
        bool swap_made = false;
        for (int i = 0; i < n-1; i++)
        {
            //  Compares side by side elements and swaps as needed
            if ( (strComp(arrStr[i], arrStr[i+1]) == 1) )
            {
                strSwap(arrStr[i], arrStr[i+1]);
                //cout << " Swapping at " << i << endl;
                swap_made = true;              
            }
        }
        //  Checks if swap was made this pass for while loop
        sorted = !swap_made;
    }
}


int main(int argc, char *argv[])
{
    //  Prints error message if no arguments passed
    if (argc == 1)
    {   cout << "There's nothing to alphebitize!!" << endl;
        exit(0);
    }
    //  Display the arguments passed to program from caommand line.
    cout << "Your input is:" << endl;

    for (int i=1; i<argc; i++)
    {
        cout << argv[i] << endl;
    }
    cout << endl;

    //  Copy argv to a new array
    int copyLength {argc - 1};
    char *copy[copyLength];
    for (int i=0; i < copyLength; ++i)  //  Using prefix ++ because I just
                                        //  found Stroustrop's 1984, Orwell footnote!
    {
        copy[i] = argv[i+1];
    }

    //  Call function to sort copy of argv
    strBubbleSort(copy, copyLength);

    //  Display sorted copy of array
    cout << "Your output is:" << endl;
    for (int i=0; i < copyLength; i++)
    {
        cout << copy[i] << endl;
    }
    cout << endl;
    
    //  This line helps me to debug and makes me smile because it is
    //  from Mr. Scott in Star Trek III
    //cout << "And if my grandmother had wheels, she'd be a wagon." << endl;
}