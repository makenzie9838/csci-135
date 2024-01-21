/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 6.18

This program appends one vector to another.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
    vector<int> result = a;

    for (int i = 0; i < b.size(); i++) {
        result.push_back(b[i]);
    }
    
    return result;
}

int main() {
    //Won't work for some reason
    vector<int> a = {1, 4, 9, 16};
    vector<int> b = {9, 7, 4, 9, 11};

    // int a_arr[] = {1, 4, 9, 16};
    // int b_arr[] = {9, 7, 4, 9, 11};

    // vector<int> a(a_arr, a_arr + sizeof(a_arr) / sizeof(a_arr[0]));
    // vector<int> b(b_arr, b_arr + sizeof(b_arr) / sizeof(b_arr[0]));

    vector<int> result = append(a, b);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}