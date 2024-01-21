/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 12

This program contains the class Customer.
*/

#include <iostream>
#include <string>
using namespace std;

class Customer {
    private:
        string name;
        string unique_id;
    public:
        Customer() {
            name = "";
            unique_id = "";
        }
        Customer(string name, string unique_id) {
            this->name = name;
            this->unique_id = unique_id;
        }
        string get_name() {
            return name;
        }
        string get_unique_id() {
            return unique_id;
        }
        void set_name(string input_name) {
            name = input_name;
        }
        void set_unique_id(string input_unique_id) {
            unique_id = input_unique_id;
        }
};

int main() {
    return 0;
}