/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab2B

This program asks the user to input two integers L and U 
(representing the lower and upper limits of the interval), 
and will print out all integers in the range L ≤ i < U separated by spaces. 
The program includes the lower limit, but excludes the upper limit.
*/

#include <iostream>
using namespace std;

int main() {
    int L; 
    cout << "Please enter L: ";
    cin >> L;

    int U; 
    cout << "Please enter U: ";
    cin >> U;

    for (int i = L; i < U; i++) {
        cout << i << " ";
    }
    
    return 0; 
}