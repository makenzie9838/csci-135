//
//Author: Mackenzie Eng
//Course: CSCI-136
//Instructor: Tong Yi
//Assignment: Quiz 03

//This program has an array of numbers 1 - 10 and prints each number on a
//a seperate line.


#include <iostream>
using namespace std;

int main() {
    int SIZE = 10;
    int nums[SIZE];
    int num = 1;

    for (int i = 0; i < SIZE; i++) {
        nums[i] = num;
        cout << nums[i] << endl;
        num++; 
    }

    return 0; 
}
