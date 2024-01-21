/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 2.1

This program asks the user to input:
• The number of gallons of gas in the tank
• The fuel efficiency in miles per gallon
• The price of gas per gallon
Then print the cost per 100 miles and how far the car can go with 
the gas in the tank.
*/

#include <iostream>
using namespace std;

int main() {
    float tank; 
    cout << "Enter the number of gallons of gas in the tank: ";
    cin >> tank;

    float efficiency; 
    cout << "Enter the fuel efficiency in miles per gallon: ";
    cin >> efficiency; 

    float price; 
    cout << "Enter the price of gas per gallon: ";
    cin >> price;

    float cost = (100.0 / efficiency) * price;
    cout << "The cost per 100 miles is " << cost << ".";

    float distance = tank * efficiency;
    cout << " The car can travel " << distance << " miles.";

    return 0;
}