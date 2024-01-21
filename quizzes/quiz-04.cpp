/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 04

This program opens a file stream to a file called "data.txt", which contains
lines of text with names of colors and their RGB values, like this:
red FF0000
blue 0000FF
yellow FFFF00
etc...
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("data.txt");

    string line;

    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();

    return 0;
}