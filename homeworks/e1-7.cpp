/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 1.7

This program asks the users to input 3 names and prints them on 
three seperate lines. 
*/

#include <iostream>
using namespace std;

int main() {
    string name1; 
    cout << "Enter a name: ";
    cin >> name1; 

    string name2;
    cout << "Enter another name: ";
    cin >> name2; 

    string name3;
    cout << "Enter one last name: ";
    cin >> name3;

    cout << name1 << endl << name2 << endl << name3 << endl;

    return 0;
}