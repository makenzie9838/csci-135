/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab7B

This program reads the input line by line, it should also count the 
number of open and closed { } in it, and keep track of how many blocks 
is currently open at the beginning of each line.
*/

#include <iostream>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line);
int countChar(string line, char c);

int main() {
    string input;
    int open = 0;
    int close = 0;

    while (getline(cin, input)) {
        string removedLeadingSpaces = removeLeadingSpaces(input);

        int tabs = open - close;

        if (removedLeadingSpaces[0] == '}') {
            tabs--;
        }
        
        for (int i = 0; i < tabs; i++) {
            cout << '\t';
        }

        cout << removedLeadingSpaces << endl;

        open += countChar(removedLeadingSpaces, '{');
        close += countChar(removedLeadingSpaces, '}');
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

int countChar(string line, char c) {
    int answer = 0; 
    
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == c) {
            answer++;
        }
    }

    return answer;
}