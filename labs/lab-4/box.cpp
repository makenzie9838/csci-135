/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab4A

This program asks the user to input width and height and 
prints a solid rectangular box of the requested size using asterisks.
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

    while (height > 0) {
        for (int i = 0; i < width; i++) {
            cout << "*";
        }
        cout << endl;
        height--;
    }

    return 0;
}