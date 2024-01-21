/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab5A-G

This program uses helper functions to check a bunch of conditions on
integers.
*/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d);
bool isPrime(int n);
int nextPrime(int n);
int countPrimes(int a, int b);
bool isTwinPrime(int n);
int nextTwinPrime(int n);
int largestTwinPrime(int a, int b);

int main() {
    int num1; 
    cout << "Enter an integer: ";
    cin >> num1;

    int num2;
    cout << "Enter another integer: ";
    cin >> num2;

    //if (isDivisibleBy(num1, num2)) {
    //    cout << "Yes";
    //} else {
    //    cout << "No";
    //}
    
    //if (isPrime(num1)) {
    //   cout << "Yes";
    //} else {
    //    cout << "No;"
    //}

    //cout << nextPrime(num1) << endl;

    //cout << countPrimes(num1, num2) << endl;

    //if (isTwinPrime(num1)) {
    //    cout << "True";
    //} else {
    //    cout << "False";
    //}

    //cout << nextTwinPrime(num1) << endl;

    cout << largestTwinPrime(num1, num2) << endl;

    return 0;
}

bool isDivisibleBy(int n, int d) {
    if (d == 0) {
        return false;
    }

    return (n % d == 0);
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int nextPrime(int n) {
    int num = n + 1;

    while (!isPrime(num)) {
        num++;
    }

    return num;
}

int countPrimes(int a, int b) {
    int answer = 0; 

    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            answer++;
        }
    }

    return answer;
}

bool isTwinPrime(int n) {
    if (!isPrime(n)) {
        return false;
    }

    return isPrime(n - 2) || isPrime(n + 2);
}

int nextTwinPrime(int n) {
    int num = n + 1;

    while (!isTwinPrime(num)) {
        num++;
    }
    
    return num;
}

int largestTwinPrime(int a, int b) {
    int max = -1;

    for (int i = b; i >= a; i--) {
        if (isTwinPrime(i)) {
            max = i;
            break;
        }
    }

    return max;
}