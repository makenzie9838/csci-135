/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 7.1

This program has a function, sort2, that receives two pointers and 
sorts the values to which they point. If you call sort2(&x, &y)
then x <= y after the call.
*/

#include <iostream>
using namespace std;

void sort2(double* p, double* q);

int main() {
    double num1 = 15.22;
    double num2 = 10.33;

    cout << num1 << " " << num2 << endl;

    sort2(&num1, &num2);

    cout << num1 << " " << num2 << endl;
    
    return 0;
}

void sort2(double* p, double* q) {
    if (*p > *q) {
        double temp = *p;
        *p = *q;
        *q = temp;
    }
}