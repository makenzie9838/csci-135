/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1C

This program asks the users to input a year and it will output whether 
the year is a common year or leap year.
*/

#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    if (year % 4 != 0) {
        cout << "Common year";
    } else if (year % 100 != 0) {
        cout << "Leap year";
    } else if (year % 400 != 0) {
        cout << "Common year";
    } else {
        cout << "Leap year";
    }

    return 0;
}