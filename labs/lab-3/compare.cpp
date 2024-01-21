/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab3C

This program asks the user to input two dates (the beginning and the 
end of the interval). The program should check each day in the interval 
and report which basin had higher elevation on that day by printing “East” 
or “West”, or print “Equal” if both basins are at the same level.
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

    string start;
    cout << "Enter starting date: ";
    cin >> start;

    string end;
    cout << "Enter ending date: ";
    cin >> end;

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
        
        if (date >= start && date <= end) {
            if (eastEl > westEl) {
                cout << date << " East" << endl;
            } else if (eastEl < westEl) {
                cout << date << " West" << endl;
            } else {
                cout << date << " Equal" << endl; 
            }
        }
    }

    fin.close();

    return 0;
}
