/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab6C

This program has functions that implement the Vingnere cipher encryption.
*/

#include <iostream>
#include <cctype>
using namespace std;

string encryptVigenere(string plaintext, string keyword);

int main() {
    string plainText;
    cout << "Enter plaintext: ";
    getline(cin, plainText);

    string keyWord;
    cout << "Enter keyword: ";
    getline(cin, keyWord);

    string cipherText = encryptVigenere(plainText, keyWord);
    cout << "Ciphertext: " << cipherText << endl;

    return 0;
}

string encryptVigenere(string plaintext, string keyword) {
    string answer;
    int indexOfKeyword = 0; 

    for (int i = 0; i < plaintext.length(); i++) {
        char encryptedChar = plaintext[i];
        int rshift = int(keyword[indexOfKeyword]) - 'a';

        if (isalpha(encryptedChar)) {
            char base; 
            if (isupper(encryptedChar)) {
                base = 'A';
            } else {
                base = 'a';
            }

            encryptedChar = char(base + (int(encryptedChar) - base + rshift) % 26);
            indexOfKeyword = (indexOfKeyword + 1) % keyword.length();
        }

        answer += encryptedChar;
    }

    return answer;
}