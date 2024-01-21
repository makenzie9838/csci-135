/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab6D

This program demonstrates encryption and decryption for both ciphers.
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift);
string encryptCaesar(string plaintext, int rshift);
string decryptCaesar(string ciphertext, int rshift);
string encryptVigenere(string plaintext, string keyword);
string decryptVigenere(string ciphertext, string keyword);

int main() {
    string plainText;
    cout << "Enter plaintext: ";
    getline(cin, plainText);

    cout << "= Caeser =" << endl;

    int shift;
    cout << "Enter shift: ";
    cin >> shift; 

    cin.ignore();

    string caeserText = encryptCaesar(plainText, shift);
    cout << "Ciphertext: " << caeserText << endl;

    string decryptedCaeser = decryptCaesar(caeserText, shift);
    cout << "Decrypted: " << decryptedCaeser << endl;

    cout << "= Vigenere =" << endl;

    string keyWord;
    cout << "Enter keyword: ";
    getline(cin, keyWord);

    string vigenereText = encryptVigenere(plainText, keyWord);
    cout << "Ciphertext: " << vigenereText << endl;

    string decryptedVignere = decryptVigenere(vigenereText, keyWord);
    cout << "Decrypted: " << decryptedVignere << endl;

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
        
        int shifted = int(c) - base + rshift;
        if (shifted < 0) {
            shifted = 26 - (-shifted % 26);
        }

        answer = char(base + (shifted) % 26);
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

string decryptCaesar(string ciphertext, int rshift) {
    string answer; 

    for (int i = 0; i < ciphertext.length(); i++) {
        answer += shiftChar(ciphertext[i], -rshift);
    }

    return answer; 
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

string decryptVigenere(string ciphertext, string keyword) {
    string answer;
    int indexOfKeyword = 0; 

    for (int i = 0; i < ciphertext.length(); i++) {
        char decryptedChar = ciphertext[i];
        int rshift = -(int(keyword[indexOfKeyword]) - 'a');

        if (isalpha(decryptedChar)) {
            char base; 
            if (isupper(decryptedChar)) {
                base = 'A';
            } else {
                base = 'a';
            }

            int shifted = int(decryptedChar) - base + rshift;
            if (shifted < 0) {
                shifted = 26 - (-shifted % 26);
            }

            decryptedChar = char(base + (shifted) % 26);
            indexOfKeyword = (indexOfKeyword + 1) % keyword.length();
        }

        answer += decryptedChar;
    }

    return answer;
}