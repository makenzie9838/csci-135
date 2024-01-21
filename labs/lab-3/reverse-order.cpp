/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab3D

This program asks the user to input two dates (earlier date then later 
date). The program should report the West basin elevation for 
all days in the interval in the reverse chronological order (from 
the later date to the earlier).
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
    cout << "Enter earlier date: ";
    cin >> start;

    string end;
    cout << "Enter later date: ";
    cin >> end;

    string date;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;

    const int SIZE = 365;
    string allDates [SIZE];
    double allWestEl [SIZE];
    int index = 0;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl && date <= end) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
    
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignoring the remaining columns 
        
        if (date >= start) {
            allDates[index] = date;
            allWestEl[index] = westEl;
            index++;
        }
    }

    for (int i = index - 1; i >= 0; i--) {
        cout << allDates[i] << " " << allWestEl[i] << " ft" << endl;
    }

    fin.close();
    return 0;
}
