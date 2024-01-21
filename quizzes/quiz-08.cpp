/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 08

This program returns the difference of unbalanced open and closed
blocks of brackets in the input.
*/

#include <iostream>
using namespace std;

int unbalanced_brackets(string input) {
    int open = 0;
    int close = 0;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '{') {
            open += 1;
        } else if (input[i] == '}') {
            close += 1;
        }
    }

    return open - close;
}

int main() {
    cout << unbalanced_brackets("{{}}") << endl;

    cout << unbalanced_brackets("{{}") << endl;

    cout << unbalanced_brackets("{}}}}") << endl;

    return 0;
}