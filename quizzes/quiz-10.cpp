/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 10

This program contains the class Date.
*/

#include <iostream>
#include <string>
using namespace std;

class Date {
    public: 
        int month;
        int day;
        int year;
};

string formatDate(Date * input) {
    string month;

    if (input->month == 1) {
        month = "Jan";
    } else if (input->month == 2) {
        month = "Feb";
    } else if (input->month == 3) {
        month = "Mar";
    } else if (input->month == 4) {
        month = "Apr";
    } else if (input->month == 5) {
        month = "May";
    } else if (input->month == 6) {
        month = "Jun";
    } else if (input->month == 7) {
        month = "Jul";
    } else if (input->month == 8) {
        month = "Aug";
    } else if (input->month == 9) {
        month = "Sep";
    } else if (input->month == 10) {
        month = "Oct";
    } else if (input->month == 11) {
        month = "Nov";
    } else if (input->month == 12) {
        month = "Dec";
    }

    string dayString = to_string(input->day);
    string yearString = to_string(input->year);

    return month + " " + dayString + "," + yearString;
}

int main() {
    Date * date = new Date;
    date->month = 1;
    date->day = 2;
    date->year = 2023;

    cout << formatDate(date) << endl;
}