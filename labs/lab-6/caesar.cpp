/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab6B

This program has functions that implement the Caesar cipher encryption.
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift);
string encryptCaesar(string plaintext, int rshift);

int main() {
    string plainText;
    cout << "Enter plaintext: ";
    getline(cin, plainText);

    int shift;
    cout << "Enter shift: ";
    cin >> shift; 

    string cipherText = encryptCaesar(plainText, shift);
    cout << "Ciphertext: " << cipherText << endl;

    return 0;
}

char shiftChar(char c, int rshift) {
    char answer = c;

    if (isalpha(c)) {
        char base;
        if (isupper(c)) {
            base = 'A';
        } else {
            base = 'a';
        }
        answer = char(base + (int(c) - base + rshift) % 26);
    }

    return answer;
}

string encryptCaesar(string plaintext, int rshift) {
    string answer; 

    for (int i = 0; i < plaintext.length(); i++) {
        answer += shiftChar(plaintext[i], rshift);
    }

    return answer;
}