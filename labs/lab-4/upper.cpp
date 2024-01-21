/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab4E

This program prints the top-right half of a square, given the side length.
*/

#include <iostream>
using namespace std;

int main() {
    int length; 
    cout << "Input side length: ";
    cin >> length;

    cout << "Shape: " << endl;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = i; j < length; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}