/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab6A

This program asks the user to input a line of text (which may possibly 
include spaces). The program should report all characters from the input 
line together with their ASCII codes.
*/

#include <iostream>
using namespace std;

int main() {
    string input; 
    cout << "Input: ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        cout << input[i] << " " <<  int(input[i]) << endl;
    }

    return 0;
}