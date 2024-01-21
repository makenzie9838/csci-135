/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 5.14

This function, void sort2(int& a, int& b) swaps the values of a and b 
if a is greater than b and otherwise leaves a and b unchanged. For example,
int u = 2;
int v = 3;
int w = 4;
int x = 1;
sort2(u, v); // u is still 2, v is still 3
sort2(w, x); // w is now 1, x is now 4
*/

#include <iostream>
using namespace std;

void sort2(int& a, int& b);

int main() {
    int u = 2; 
    int v = 3;
    int w = 4;
    int x = 1;

    sort2(u, v);
    cout << "u = " << u << ", v = " << v << endl;

    sort2(w, x);
    cout << "w = " << w << ", x = " << x << endl;

    return 0;
}

void sort2(int& a, int&b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}