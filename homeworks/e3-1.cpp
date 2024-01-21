/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 3.1

This program asks the users to input an integer and it prints whether
it is negative, positive, or zero.
*/

#include <iostream>
using namespace std;

int main() {
    int num; 
    cout << "Input an integer: ";
    cin >> num;

    if (num > 0) {
        cout << "This integer is positive!";
    } else if (num < 0) {
        cout << "This integer is negative!";
    } else {
        cout << "This integer is zero!";
    }

    return 0;
}