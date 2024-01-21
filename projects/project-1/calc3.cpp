/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 Task D

This is an even better calculator program calc3.cpp that can understand 
squared numbers. We are going to use a simplified notation X^ to mean X2. 
For example, 10^ + 7 - 51^ should mean 10^2 + 7 − 51^2.
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

        char previousCh = ch;

        cin >> ch;

        if (ch == '^') {
            int squaredOperand = operand * (operand - 1);
            if (previousCh == '+' || previousCh == ' ') {
                sum += squaredOperand;
            } else if (previousCh == '-') {
                sum -= squaredOperand;
            }
            cin >> ch;
        }
    }

    cout << sum << endl;
    
    return 0;
}
