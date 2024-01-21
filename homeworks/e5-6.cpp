/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 5.6

This function, string middle(string str)
that returns a string containing the middle character in 
str if the length of str is odd, or the two middle characters 
if the length is even. 
For example, middle("middle") returns "dd".
*/

#include <iostream>
using namespace std;

string middle(string str);

int main() {
    cout << middle("middle") << endl;

    return 0;
}

string middle(string str) {
    int length = str.length();
    int middle;

    string answer;

    if (length % 2 != 0) {
        middle = length / 2;
        answer += str[middle];
    } else {
        middle = length / 2 - 1;
        answer += str[middle];
        answer += str[middle + 1];
    }

    return answer;
}