/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab12D

This program returns a vector of integers whose elements are the 
pairwise sum of the elements from the two vectors passed as arguments. 
If a vector has a smaller size than the other, consider extra entries 
from the shorter vectors as 0.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
    vector<int> output;

    int i = 0; 
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        output.push_back(v1[i] + v2[j]);
        i++;
        j++;
    }

    while (i < v1.size()) {
        output.push_back(v1[i]);
        i++;
    }

    while (j < v2.size()) {
        output.push_back(v2[j]);
        j++;
    }

    return output;
}

int main() {
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    vector<int> output = sumPairWise(v1, v2); // returns [5, 7, 3]

    for (int element : output) {
        cout << element << " ";
    }

    return 0;
}