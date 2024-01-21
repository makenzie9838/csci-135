/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 6.8

This function checks whether two arrays have the same elements in the 
same order.
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size);

int main() {
    int a[] = {1, 2, 3};
    int a_size = sizeof(a);

    int b[] = {3, 2, 1};
    int b_size = sizeof(b);

    if (equals(a, a_size, b, b_size)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}

bool equals(int a[], int a_size, int b[], int b_size) {
    if (a_size != b_size) {
        return false;
    }

    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}