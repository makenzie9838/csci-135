/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab12B

This program returns a vector with only the positive integers in the same 
order.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v) {
    vector<int> output;

    for (int element : v) {
        if (element > 0) {
            output.push_back(element);
        }
    }

    return output;
}

int main() {
    vector<int> v{1,2,-1,3,4,-1,6};

    vector<int> output = goodVibes(v); // returns [1,2,3,4,6]

    for (int element : output) {
        cout << element << " ";
    }

    return 0;
}