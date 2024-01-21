/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab3B

This program finds the minimum and maximum storage in East basin in 2018.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one line from the file 

    double min = 1000;
    double max = 0;
    string date;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
    
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignoring the remaining columns 
 
        // for example, to print the date and East basin storage:
        if (eastSt < min) {
            min = eastSt;
        }
        if (eastSt > max) {
            max = eastSt;
        }

    }

    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;
    cout << "MAXimum storage in East basin: " << max << " billion gallons" << endl;

    fin.close();

    return 0;
}