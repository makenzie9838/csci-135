/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab7A

This program reads input from cin and prints out each input line with 
leading spaces removed.
*/

#include <iostream>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line);

int main() {
    string input;

    while (getline(cin, input)) {
        cout << removeLeadingSpaces(input) << endl;
    }

    return 0;
}

string removeLeadingSpaces(string line) {
    string answer;
    bool firstNonSpace = false;

    for (int i = 0; i < line.length(); i++) {
        if (!isspace(line[i])) {
            firstNonSpace = true;
        }

        if (firstNonSpace) {
            answer += line[i];
        }
    }

    return answer;
}