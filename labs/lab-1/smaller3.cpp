/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab1B

This program asks the users to input 3 integers and it will print the
smaller of the three.
*/

#include <iostream>
using namespace std;

int main() {
    int one;
    cout << "Enter the first number: ";
    cin >> one;

    int two; 
    cout << "Enter the second number: ";
    cin >> two; 

    int three;
    cout << "Enter the third number: ";
    cin >> three; 

    int smallest;

    if (one >= two) {
        smallest = two;
    } else {
        smallest = one;
    }

    if (smallest > three) {
        smallest = three;
    }

    cout << "The smaller of the three is " << smallest << endl;
    
    return 0;
}