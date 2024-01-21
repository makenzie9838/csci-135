/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 05

This program outputs a 5 wide, 6 tall plus grid to the console.
*/

#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 6; i++) {
        for (int i = 0; i < 5; i++) {
            cout << '+';
        }

        cout << endl;
    }

    return 0;
}