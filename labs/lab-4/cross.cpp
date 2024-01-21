/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab4C

This program asks the user to input the shape size and prints a
diagonal cross of that dimension.
*/

#include <iostream>
using namespace std;

int main() {
    int size; 
    cout << "Input size: ";
    cin >> size;

    cout << "Shape: " << endl;

    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            if (row == column || row + column == size - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}