/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab3A

This program asks the user to input a string representing the date 
(in MM/DD/YYYY format), and prints out the East basin storage on that day.
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

    string userDate;
    cout << "Enter date: ";
    cin >> userDate;

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
        if (date == userDate) {
            getline(fin, date);
            cout << "East basin storage: " << eastSt << " billion gallons" << endl;
        }
    }

    fin.close();

    return 0;
}