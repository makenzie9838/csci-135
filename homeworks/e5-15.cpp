/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 5.15

This function sort3(int& a, int& b, int& c) that swaps its 
three arguments to arrange them in sorted order. For example,
int v = 3;
int w = 4;
int x = 1;
sort3(v, w, x); // v is now 1, w is now 3, x is now 4
*/

#include <iostream>
using namespace std;

void sort3(int& a, int& b, int& c);

int main() {
    int v = 3;
    int w = 4;
    int x = 1;

    sort3(v, w, x);
    cout << "v = " << v << ", w = " << w << ", x = " << x << endl;

    return 0;
}

void sort3(int& a, int&b, int& c) {
    int min; 
    int middle;
    int max;

    if (a > b) {
        min = b;
    } else {
        min = a;
    }

    if (min > c) {
        min = c;
    }

    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    if (max < c) {
        max = c;
    }

    if (a != min && a != max) {
        middle = a;
    } else if (b != min && b != max) {
        middle = b;
    } else {
        middle = c;
    }

    a = min;
    b = middle;
    c = max;
}