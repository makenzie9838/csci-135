/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1A

This program asks the users to input 2 integers and it will print the
smaller of the two.
*/

#include <iostream>
using namespace std;

int main() {
    int one;
    cout << "Enter the first number: ";
    cin >> one;

    int two; 
    cout << "Enter the second number: ";
    cin >> two; 

    if (one > two) {
        cout << "The smaller of the two is " << two << endl; 
    } else if (one < two) {
        cout << "The smaller of the two is " << one << endl;
    } else {
        cout << "The smaller of the two is both" << endl;
    }

    return 0;
}