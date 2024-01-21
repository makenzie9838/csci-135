/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 Task B

This program reads from the cin a sequence of one or more 
non-negative integers written to be added or subtracted. 
Space characters can be anywhere in the input. 
After the input ends (end-of-file is reached), 
the program should compute and print the result of the input summation.
*/

#include <iostream>
using namespace std;

int main() {
    int operand;
    char ch = '+';
    int sum = 0;

    while (cin >> operand) {
        if (ch == '+') {
            sum += operand;
        } else if (ch == '-') {
            sum -= operand;
        }
        cin >> ch;
    }

    cout << sum;

    return 0;
}
