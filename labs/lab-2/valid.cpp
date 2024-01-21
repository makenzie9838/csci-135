/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab2A

This program asks the user to input an integer in the range 0 < n < 100. 
If the number is out of range, the program should keep asking to re-enter 
until a valid number is input. After a valid value is obtained, the value 
squared will be printed.
*/

#include <iostream>
using namespace std;

int main() {
    int num; 
    cout << "Please enter an integer: ";
    cin >> num; 

    while (num <= 0 || num >= 100) {
        cout << "Please re-enter: ";
        cin >> num;
    }

    cout << "Number squared is " << num * num;

    return 0;
}