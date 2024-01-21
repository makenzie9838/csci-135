/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 8.11

This program reads a file, removes any blank lines, and writes the 
non-blank lines back to the same file.
*/

#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    string fileName;
    cout << "Enter a file name: ";
    cin >> fileName;

    ifstream fin(fileName);

    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    ofstream fout("output.txt");

    if (fout.fail()) {
        cerr << "File cannot be opened for writing." << endl;
        exit(1); // exit if failed to open the file
    }

    string line;
    while (getline(fin, line)) {
        if (!line.empty()) {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    // Remove the original file
    remove(fileName.c_str());

    // Rename the temporary file to the original file name
    rename("output.txt", fileName.c_str());

    return 0;
}