/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab12C

This program implements the function that appends elements of the second 
vector into the first and empties the second vector.
*/

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta) {
    for (int element : vegeta) {
        goku.push_back(element);
        vegeta.pop_back();
    }
}

int main() {
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.

    return 0;
}