/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab13A-F

This program doesn't use any loops, global or static variables. It
only uses recursion.
*/

#include <iostream>
#include <cctype>
using namespace std;

void printRange(int left, int right) {
    if (left <= right) {
        cout << left << " ";
        printRange(left + 1, right);
    }
}

int sumRange(int left, int right) {
    if (right - left < 0) {
        return 0;
    } else {
        return left + sumRange(left + 1, right);
    }
}

int sumArray(int *arr, int size) {
    if (size == 0) {
        return 0;
    } else {
        return *arr + sumArray(arr + 1, size - 1);
    }
}

bool isAlphanumeric(string s) {
    if (s.length() == 0) {
        return true;
    } else {
        if (!isalnum(s[0])) {
            return false;
        }
        return isAlphanumeric(s.substr(1, s.length() - 1));
    }
}

bool nestedParens(string s) {
    if (s.length() == 0) {
        return true;
    } else {
        if (!(s[0] == '(' && s[s.length() - 1] == ')')) {
            return false;
        }
        return nestedParens(s.substr(1, s.length() - 2));
    }
}

bool solvable(int *prices, int size, int aliceTotal, int bobTotal) {
    if (size == 0) {
        return aliceTotal == bobTotal;
    }

    if (solvable(prices + 1, size - 1, aliceTotal + prices[0], bobTotal)) {
        return true;
    }

    if (solvable(prices + 1, size - 1, aliceTotal, bobTotal + prices[0])) {
        return true;
    }

    return false;
}

bool divisible(int *prices, int size) {
    int aliceTotal = 0;
    int bobTotal = 0;

    return solvable(prices, size, aliceTotal, bobTotal);
}

int main() {
    // printRange(-2, 10);

    // int x = sumRange(1, 3);
    // cout << "This is " << x << endl;   // 6
    
    // int y = sumRange(-2, 10);
    // cout << "That is " << y << endl;   // 52

    // int size = 10;
    // int *arr = new int[size]; // allocate array dynamically
    // arr[0] = 12;
    // arr[1] = 17;
    // arr[2] = -5;
    // arr[3] = 3;
    // arr[4] = 7;
    // arr[5] = -15;
    // arr[6] = 27;
    // arr[7] = 5;
    // arr[8] = 13;
    // arr[9] = -21;

    // int sum1 = sumArray(arr, size); // Add all elements
    // cout << "Sum is " << sum1 << endl;  // Sum is 43
    
    // int sum2 = sumArray(arr, 5); // Add up first five elements
    // cout << "Sum is " << sum2 << endl;  // Sum is 34

    // delete[] arr;         // deallocate it

    // cout << isAlphanumeric("ABCD") << endl;        // true (1)
    // cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
    // cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)

    // cout << nestedParens("((()))") << endl;      // true (1)
    // cout << nestedParens("()") << endl;          // true (1)
    // cout << nestedParens("") << endl;            // true (1)

    // cout << nestedParens("(((") << endl;         // false (0)
    // cout << nestedParens("(()") << endl;         // false (0)
    // cout << nestedParens(")(") << endl;          // false (0)
    // cout << nestedParens("a(b)c") << endl;       // false (0)

    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};

    cout << divisible(prices, 9);

    return 0;
}