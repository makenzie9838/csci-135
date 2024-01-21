/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab4B

This program asks the user to input width and height and 
prints a rectangular checkboard of the requested size using asterisks
and spaces (alternating)
*/

#include <iostream>
using namespace std;

int main() {
    int width;
    cout << "Input width: ";
    cin >> width;

    int height;
    cout << "Input height: ";
    cin >> height;

    cout << "Shape: " << endl;

    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            if ((row + column) % 2 == 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}