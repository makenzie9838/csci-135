/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 Task A

This program reads a sequence of integers from cin, and reports their sum.
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    int sum; 

    while (cin >> num) {
        sum += num;
    }

    cout << sum;

    return 0;
}