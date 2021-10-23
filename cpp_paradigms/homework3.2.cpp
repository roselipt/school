//  Homework 3.2 for Paradigms in C++
//  Tom Budny
//  This program reads phone numbers from a file, 
//  puts them in a map, and then uses library functions 
//  to answer five queries about the numbers.

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    map<int, string> map1;
    int id;
    string phone, id_string;

    //  This is still the basic try/catch for file reading from class notes
    //  This isn't what you meant by "don't copy code" is it?
    // ALONG WITH THIS SAME COMMENT I"M AFRAID TO TAKE OUT!
    try {
        ifstream inFile("phoneno.txt");
        if (!inFile.good())
            throw string("Failure opening input_hw3.txt");
        ofstream outFile("output_hw3.txt");
        if (!outFile)
            throw string("Failure opening output.txt");
        
        string line;
        getline(inFile, line);

        while (!inFile.eof()) {
            
            //outFile << line << endl;
            
            //  Parse line for id and phone
            id_string = line.substr(0,5);
            id = stoi(id_string);//cout << id << endl;
            phone = line.substr(7);

            //  Put single entry in the map
            map1[id] = phone;

            //  Read next line from file
            getline(inFile, line);

        } // Close while


        //  Print map size to file
        outFile << endl <<  "Size of map: " << map1.size() << endl;


        //  Count 347 numbers
        int counter = 0;
        for (auto& p : map1){
            string area_code = p.second.substr(0,3);
            //cout << area_code << " ";
            if (area_code == "347") ++counter;
        }
        outFile << "Count of phone# with area code 347: " << counter << endl;


        //  Search for particular phone number, 212 536 6331
        //  and make a list of all the ids associated with it
        counter = 0;
        list<int> matches;
        for (auto& p : map1){
            string target_number = "212-536-6331";
            if (p.second == target_number)  {
                matches.push_back(p.first);  
                ++counter;
            }
        }
        outFile << "The (ID)s with the given phone #: "; 
        for (auto x : matches) outFile << x << "  ";
        outFile << endl;


        //  Create a vector of all 212 numbers from map
        vector<string> v212;
        for (auto& p : map1) {
            string area_code = p.second.substr(0,3);
            //cout << area_code << " ";
            if (area_code == "212")
                v212.push_back(p.second);
        }
        outFile << "Size of the vector with all (212) numbers: " << v212.size() << endl;
        

        //  Create a copy of 212 vector eliminating duplicates
        sort(v212.begin(), v212.end());
        auto last = unique(v212.begin(), v212.end());
        v212.erase(last, v212.end());
        //vector<string> unique212;
        //for (string& s : v212)
          //  if (s != --s)
            //    unique212.push_back(s);
        outFile << "Size of the vector with unique (212) numbers: " << v212.size();
        
        
        inFile.close();
        outFile.close();
        cout << "And if my grandmother had wheels she'd be a wagon." << endl;
        return 0;

    } catch(string message) {
        cerr << message << endl;
        exit(1);
    }
        
        
} // Close main



