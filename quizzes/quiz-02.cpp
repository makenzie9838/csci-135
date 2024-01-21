/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 02

This program asks the users to input 2 numbers and returns the larger of
the two numbers.
*/

#include <iostream>
using namespace std;

int main() {
    int num1; 
    cout << "Enter the first number: ";
    cin >> num1; 

    int num2; 
    cout << "Enter the second number: ";
    cin >> num2;

    int larger;

    if (num2 > num1) {
        larger = num2;
    } else if (num1 > num2) {
        larger = num1; 
    }

    cout << "The larger of the two is " << larger;

    return 0;
}