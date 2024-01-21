/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab11A

This program implements the class Profile that can store the info about 
a user of the network.
*/

#include <iostream>
using namespace std;

class Profile {
    private:
        string username;
        string displayname;
    public:
        // Profile constructor for a user (initializing 
        // private variables username=usrn, displayname=dspn)
        Profile(string usrn, string dspn) {
            username = usrn;
            displayname = dspn;
        }
        // Default Profile constructor (username="", displayname="")
        Profile();
        // Return username
        string getUsername() {
            return username;
        }
        // Return name in the format: "displayname (@username)"
        string getFullName() {
            return displayname + " (@" + username + ")";
        }
        // Change display name
        void setDisplayName(string dspn) {
            displayname = dspn;
        }
};

int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}