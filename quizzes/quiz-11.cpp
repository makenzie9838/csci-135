/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 11

This program contains the class Money.
*/

#include <iostream>
#include <string>
using namespace std;

class Money {
    public:
        int dollars;
        int cents;
};

Money withdraw_money(Money x, Money y) {
    int initial = (x.dollars * 100) + x.cents;
    int subtract= (y.dollars * 100) + y.cents;

    int after = initial - subtract;

    Money output = {};

    if (after < 0) {
        output.dollars = 0;
        output.cents = 0;
        return output;
    }

    if (to_string(after).length() < 3) {
        output.dollars = 0;
    } else {
        output.dollars = after / 100;
    }

    output.cents = after % 100;

    return output;
}

int main() {
    Money m1 = {4, 80};
    Money m2 = {3, 90};
    Money m3 = withdraw_money(m1, m2);

    cout << m3.dollars << endl;
    cout << m3.cents << endl;
    return 0;
}