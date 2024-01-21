/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 06

This program contains the function int max3(int a, int b, int c).
*/

#include <iostream>
using namespace std;

int max3(int a, int b, int c);

int main() {
    cout << max3(1, 2, 3) << endl;

    cout << max3(-22, 18, 9) << endl;

    return 0;
}

int max3(int a, int b, int c) {
    int max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    return max;
}