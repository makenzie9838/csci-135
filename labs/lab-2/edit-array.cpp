/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab2C

This program creates an array of 10 integers, 
and provides the user with an interface to edit any of its elements. 
Specifically, it should work as follows:

1. Create an array myData of 10 integers.
2. Fill all its cells with value 1 (using a for loop).
3. Print all elements of the array on the screen.
4. Ask the user to input the cell index i, and its new value v.
5. If the index i is within the array range (0 ≤ i < 10), 
update the asked cell, myData[i] = v, and go back to the step 3. 
Otherwise, if index i is out of range, the program exits.

*/

#include <iostream>
using namespace std;

int main() {
    int myData[10];

    for (int i = 0; i < 10; i++) {
        myData[i] = 1;
    }

    int index;
    int value;

    do {
        for (int i = 0; i < 10; i++) {
            cout << myData[i] << " ";
        }

        cout << endl << "Input index: ";
        cin >> index;

        cout << "Input value: ";
        cin >> value; 

        if (0 <= index && index < 10) {
            myData[index] = value; 
        }
    } while (0 <= index && index < 10);

    cout << "Index out of range. Exit.";

    return 0; 
}