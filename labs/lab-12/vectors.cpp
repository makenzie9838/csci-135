/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab12A

This program has a function that returns a vector of n integers that range 
from 0 to n-1. 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n) {
    vector<int> output;

    for (int i = 0; i < n; i++) {
        output.push_back(i);
    }

    return output;
}

int main() {
    vector<int> output = makeVector(5);

    for (int element : output) {
        cout << element;
    }
    
    return 0;
}