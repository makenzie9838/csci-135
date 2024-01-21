/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 07

This program contains a function that removes all e's from the original 
string without creating a new string.
*/

#include <iostream>
using namespace std;

void remove_e(string & sentence) {
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == 'e') {
            for (int j = i; j < sentence.length(); j++) {
                sentence[j] = sentence[j + 1];
            }

            sentence.pop_back();
        }
    }
}

int main() {
    string original = "Hello from everyone here.";

    cout << "Original String: " << original << endl;

    remove_e(original);

    cout << "Modified String: " << original << endl;

    return 0;
}