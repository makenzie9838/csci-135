/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 3.5

This program asks the users to input 3 numbers and prints whether they
are increasing, decreasing or neither. 
*/

#include <iostream>
using namespace std;

int main() {
    int num1; 
    cout << "Enter a number: ";
    cin >> num1; 

    int num2; 
    cout << "Enter another number: ";
    cin >> num2;

    int num3; 
    cout << "Enter one last number: ";
    cin >> num3;  

    if (num1 < num2 && num2 < num3) {
        cout << "increasing";
    } else if (num1 > num2 && num2 > num3) {
        cout << "decreasing";
    } else {
        cout << "neither";
    }

    return 0;
}