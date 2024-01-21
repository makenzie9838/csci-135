/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1D

This program asks the user to input the year and the month (1-12) 
and prints the number of days in that month (taking into account leap 
years).
*/

#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    bool leapYear;

    if (year % 4 != 0) {
        leapYear = false;
    } else if (year % 100 != 0) {
        leapYear = true;
    } else if (year % 400 != 0) {
        leapYear = false;
    } else {
        leapYear = true; 
    }

    int month; 
    cout << "Enter month: ";
    cin >> month; 

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
     month == 8 || month == 10 || month == 12) {
        cout << "31 days";
    } else if (month == 2) {
        if (leapYear == true) {
            cout << "29 days";
        } else {
            cout << "28 days";
        }
    } else {
        cout << "30 days";
    }

    return 0;
}