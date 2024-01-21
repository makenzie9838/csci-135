/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab11C

This program is an improved version of the previous program. The class 
Network should be changed to keep the friendship (following) relation 
between the users.
*/

#include <iostream>
#include <cctype>
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
        Profile() {
            username = "";
            displayname = "";
        }
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

class Network {
    private:
        static const int MAX_USERS = 20; // max number of user profiles
        int numUsers;                    // number of registered users
        Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
        // Returns user ID (index in the 'profiles' array) by their username
        // (or -1 if username is not found)
        int findID (string usrn) {
            for (int i = 0; i < numUsers; i++) {
                if (profiles[i].getUsername() == usrn) {
                    return i;
                }
            }

            return -1;
        }

        bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
        // following[id1][id2] == true when id1 is following id2

        
    public:
        // Constructor, makes an empty network (numUsers = 0)
        Network() {
            numUsers = 0;

            for (int i = 0; i < MAX_USERS; i++) {
                for (int j = 0; j < MAX_USERS; j++) {
                    following[i][j] = false;
                }
            }
        }
        // Attempts to sign up a new user with specified username and displayname
        // return true if the operation was successful, otherwise return false
        bool addUser(string usrn, string dspn) {
            if (usrn.length() == 0) {
                return false;
            }

            for (int i = 0; i < usrn.length(); i++) {
                if (!isalnum(usrn[i])) {
                    return false;
                }
            }

            for (int i = 0; i < numUsers; i++) {
                if (profiles[i].getUsername() == usrn) {
                    return false;
                }
            }

            if (numUsers == MAX_USERS) {
                return false;
            }

            Profile newUser = Profile(usrn, dspn);
            profiles[numUsers] = newUser;
            numUsers++;

            return true;
        }

        // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
        // return true if success (if both usernames exist), otherwise return false
        bool follow(string usrn1, string usrn2) {
            bool usrn1In = false;
            bool usrn2In = false;

            for (int i = 0; i < numUsers; i++) {
                if (profiles[i].getUsername() == usrn1) {
                    usrn1In = true;
                }

                if (profiles[i].getUsername() == usrn2) {
                    usrn2In = true;
                }
            }

            if (usrn1In == false || usrn2In == false) {
                return false;
            }

            following[findID(usrn1)][findID(usrn2)] = true;

            return true;
        }

        // Print Dot file (graphical representation of the network)
        void printDot() {
            cout << "digraph {" << endl;
            for (int i = 0; i < numUsers; i++) {
                cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
            }
            cout << endl;
            for (int person1 = 0; person1 < numUsers; person1++) {
                for (int person2 = 0; person2 < MAX_USERS; person2++) {
                    if (following[person1][person2] == true) {
                        cout << "  \"@" << profiles[person1].getUsername() << "\" -> \"@" << profiles[person2].getUsername() << "\"" << endl;
                    }
                }
            }
            cout << "}";
        }
};

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}