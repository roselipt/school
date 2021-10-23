//  Homework 3.1, Paradigms (or Styles) in C++
//  Tom Budny
//
//  This program creates a vector of 100,000 integers,
//  shuffles it,
//  copies it to another vector,
//  and then a list, set and unordered set.


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <list>
#include <set>
#include <unordered_set>

using namespace std;

//  populate vector with value = subscript
void populate_vector(vector<int>& vec){
    for (int i = 0; i != vec.size(); i++) {
        vec[i] = i;
    }
}

//  Show elements in vector
//  this isn't used in final program but
//  I used it for debugging smaller vectors
void show_vector(const vector<int>& vec) {
    for (int i = 0; i != vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void write_results() {

}

int main () {

    vector<int> victor(100000);
    
    //  show initialized vector
    //for (auto x : victor)
    //    cout << x;

    //  show initialized vector again
    cout << endl;
    // show_vector(victor);

    populate_vector(victor);
    //cout << " Here is after populate_vector:\n";
    //show_vector(victor);


    std::random_device rd;
    std::mt19937 g(rd());
 
    //  t0 saves a start time to calcualte a duration later
    using namespace std::chrono;
    auto t0 = high_resolution_clock::now();
    
    std::shuffle(victor.begin(), victor.end(), g);

    auto t1 = high_resolution_clock::now();
    auto timer = t1 - t0;
    
    cout << "Time to shuffle vector of 100,000 elements is "
         << duration_cast<milliseconds>(timer).count() << " msecs,"
         << endl << "which you didn't ask for but I thought was interesting."
         << endl << endl;


    //  This block copies into new vector
    t0 = high_resolution_clock::now();
    vector<int> new_one;
    for (int i=0; i!=victor.size(); i++){
        new_one.push_back(victor[i]);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    
    cout << "Time to copy vector with push_back is: " 
         << duration_cast<milliseconds>(timer).count() << " msecs."
         << endl;

    //  This block copies into new list
    t0 = high_resolution_clock::now();
    list<int> l;
    for (int i=0; i!=victor.size(); i++){
        l.push_back(victor[i]);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    
    cout << "Time to copy vector into list with push_back is: " 
         << duration_cast<milliseconds>(timer).count() << " msecs."
         << endl;

    //  This block copies into new set
    t0 = high_resolution_clock::now();
    set<int> s;
    for (int i=0; i!=victor.size(); i++){
        s.insert(victor[i]);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    
    cout << "Time to copy vector into set with insert is: " 
         << duration_cast<milliseconds>(timer).count() << " msecs."
         << endl;

    //  This block copies into new unordered set
    t0 = high_resolution_clock::now();
    unordered_set<int> u;
    for (int i=0; i!=victor.size(); i++){
        u.insert(victor[i]);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    
    cout << "Time to copy vector into unordered set with insert is: " 
         << duration_cast<milliseconds>(timer).count() << " msecs."
         << endl;

    //  A blank line between populating the structures and searching them
    cout << endl; 

    //  This block copies into new list from the front
    t0 = high_resolution_clock::now();
    list<int> l2;
    for (int i=0; i!=victor.size(); i++){
        l2.push_front(victor[i]);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    
    cout << "Time to copy vector into list with push_front is: " 
         << duration_cast<milliseconds>(timer).count() << " msecs."
         << endl << endl;


    //  This block does 10K lookup for vector
    t0 = high_resolution_clock::now();
    //unordered_set<int> u;
    //int found = 0;  //Initialized int to hold found value though we don't really need it
    for (int i=0; i!=10000; i++){
        auto found = find(begin(new_one), end(new_one), i);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    
    cout << "Time to lookup 10K in shuffled vector with find is: " 
         << duration_cast<milliseconds>(timer).count() << " in msecs."
         << endl;

    int vector_time = duration_cast<milliseconds>(timer).count();  //  To hold vector time for relative calculations

    //  This block does 10K lookup for list
    t0 = high_resolution_clock::now();
    //unordered_set<int> u;
    //int found = 0;  //Initialized int to hold found value though we don't really need it
    for (int i=0; i!=10000; i++){
        auto found = find(l.begin(), l.end(), i);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    int list_time = duration_cast<milliseconds>(timer).count();
    cout << "Time to lookup 10K in list with find is: " 
         << list_time << " in msecs. ("
         << list_time*100/vector_time << "% of time for vector.)" << endl;


    //  This block does 10K lookup for a set
    t0 = high_resolution_clock::now();
    for (int i=0; i!=10000; i++){
        s.find(i);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    int set_time = duration_cast<milliseconds>(timer).count();
    cout << "Time to lookup 10K in set with find is: " 
         << set_time << " in msecs. ("
         << set_time*100/vector_time << "% of time for vector.)" << endl;

    //  This block does 10K lookup for unordered set
    t0 = high_resolution_clock::now();
    for (int i=0; i!=10000; i++){
        u.find(i);
    }
    t1 = high_resolution_clock::now();
    timer = t1 - t0;
    int uset_time = duration_cast<milliseconds>(timer).count();
    cout << "Time to lookup 10K in unordered set with find is: " 
         << uset_time << " in msecs. ("
         << uset_time*100/vector_time << "% of time for vector.)" << endl;

    cout << "\nahem\n";
}

/*    Code from debugging along the way 
      that I saved because I can't throw anything away.

    //  This loop shows each element along with a separate counter.
    int i = 0;
    for (int x : victor) {

        cout << i << x << " ";
        x = i++;
        
    }
    cout << "\n";

    //  This loop shows the vector is unchanged.
    for (auto x : victor) 
        cout << x;
    
    cout << endl << "victor's size is " << victor.size();
    
    //  Assigns the vector values by counting off
    for (auto x = 0; x != victor.size(); x++){
        victor[x] = x;
    }
    cout << endl;
*/