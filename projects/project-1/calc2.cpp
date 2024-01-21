/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 Task C

This program is a better version of the calculator, calc2.cpp, 
that can evaluate multiple arithmetic expressions. Let’s use the 
semicolon symbol that must be used at the end of each expression 
in the input.
*/

#include <iostream>
using namespace std;

int main() {
    int operand;
    char ch = '+';
    int sum = 0;

    while (cin >> operand) {
        if (ch == ';') {
            cout << sum << endl;
            sum = operand;
             ch = '+';
        } else if (ch == '+') {
            sum += operand;
        } else if (ch == '-') {
            sum -= operand;
        }
        cin >> ch;
    }

    cout << sum << endl;
    
    return 0;
}
