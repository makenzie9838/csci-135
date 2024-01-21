/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 4.8

This program reads a word and prints each character of the word 
on a separate line.
*/

#include <iostream>
using namespace std;

int main() {
    string word; 
    
    cout << "Enter a word: ";
    cin >> word; 

    for (int i = 0; i < word.length(); i++) {
        cout << word[i] << endl; 
    }
    
    return 0; 
}