/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 01

This program asks the users to input a number and returns the line
"I love C++" that many number of times. 
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter an int: ";
    cin >> num; 

    for (int i = 0; i < num; i++) {
        cout << "I love C++" << endl;
    }

    return 0;
}

