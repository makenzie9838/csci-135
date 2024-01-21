/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab11D

This program is an improved version of the previous program. The class 
Network should be changed to allow users post messages and remember them.
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

struct Post{
    string username;
    string message;
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

        static const int MAX_POSTS = 100;
        int numPosts;                    // number of posts
        Post posts[MAX_POSTS];           // array of all posts

        
    public:
        // Constructor, makes an empty network (numUsers = 0)
        Network() {
            numUsers = 0;

            for (int i = 0; i < MAX_USERS; i++) {
                for (int j = 0; j < MAX_USERS; j++) {
                    following[i][j] = false;
                }
            }

            numPosts = 0;
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

        // Add a new post
        bool writePost(string usrn, string msg) {
            if (findID(usrn) == -1) {
                return false;
            }

            if (numPosts == MAX_POSTS) {
                return false;
            }

            Post newPost = {usrn, msg};
            posts[numPosts] = newPost;
            numPosts++;

            return true;
        }

        // Print user's "timeline"
        bool printTimeline(string usrn) {
            for (int i = numPosts; i >= 0; i--) {
                if (posts[i].username == usrn) {
                    cout << profiles[findID(usrn)].getFullName() << ": " << posts[i].message << endl;
                } else if (following[findID(usrn)][findID(posts[i].username)] == true) {
                    cout << profiles[findID(posts[i].username)].getFullName() << ": " << posts[i].message << endl;
                }
            }
            return true;
        }

};

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}