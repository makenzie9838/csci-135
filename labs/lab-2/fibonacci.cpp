/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab2D

This program an array of integers to compute and print all Fibonacci 
numbers from F(0) to F(59).
*/

#include <iostream>
using namespace std;

int main() {
    int fib[60];

    fib[0] = 0;
    fib[1] = 1; 

    for (int i = 0; i < 60; i++) {
        if (i > 1) {
            fib[i] = fib[i - 1] + fib[i - 2];
            /*
            As fib[i] becomes greater than 2 billion, the numbers
            become negative as int is too small to hold the number.
            It would be better if we used long.
            */
            
        }

        cout << fib[i] << endl;
    }

    return 0; 
}