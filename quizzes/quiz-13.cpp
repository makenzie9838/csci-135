/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 13

This program contains the function makeVector.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n) {
    vector<int> output;

    if (n == 0) {
        return output;
    }
    
    while (n >= 0) {
        output.push_back(n);
        n--;
    }

    return output;
}

int main() {
    vector<int> three = makeVector(3);

    for (int i = 0; i < three.size(); i++) {
        cout << three[i] << endl;
    }
}