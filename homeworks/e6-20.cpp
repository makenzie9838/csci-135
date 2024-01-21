/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 6.20

This program merges two sorted vectors, producing a new sorted vector. 
Keep an index into each vector, indicating how much of it has been processed 
already. Each time, append the smallest unprocessed element from either 
vector, then advance the index. 
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b) {
    int i = 0; 
    int j = 0;

    vector<int> result;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }

    return result;
}

int main() {
    vector<int> a = {1, 4, 9, 16};
    vector<int> b = {4, 7, 9, 9, 11};

    vector<int> result = merge_sorted(a, b);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}