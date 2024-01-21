/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab10A-E

This program implements functions using the class Time.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Time { 
    public:
        int h;
        int m;
};

int minutesSinceMidnight(Time time) {
    return (time.h * 60) + time.m;
}

int minutesUntil(Time earlier, Time later) {
    return (((later.h * 60) + later.m) - ((earlier.h * 60) + earlier.m));
}

Time addMinutes(Time time0, int min) {
    int totalMinutes = time0.h * 60 + time0.m + min;
    int hours = totalMinutes / 60;
    int mins = totalMinutes % 60;

    Time after = {hours, mins};

    return after;
}

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
    public: 
        string title;
        Genre genre;     // only one genre per movie
        int duration;    // in minutes
};

class TimeSlot { 
    public: 
        Movie movie;     // what movie
        Time startTime;  // when it starts
};

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts) {
    string startTimeString = "[starts at " + to_string(ts.startTime.h) + ":" + to_string(ts.startTime.m) + ", ";
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    string endTimeString = "ends by " + to_string(endTime.h) + ":" + to_string(endTime.m) + "]";

    printMovie(ts.movie);
    cout << " " << startTimeString << endTimeString << endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);

    TimeSlot nextSlot = {nextMovie, endTime};

    return nextSlot;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    int intervalBetweenStartTimes;

    if (minutesUntil(ts1.startTime, ts2.startTime) < 0) {
        intervalBetweenStartTimes = minutesUntil(ts2.startTime, ts1.startTime);

        if (ts2.movie.duration > intervalBetweenStartTimes) {
            return true;
        }

    } else {
        intervalBetweenStartTimes = minutesUntil(ts1.startTime, ts2.startTime);

        if (ts1.movie.duration > intervalBetweenStartTimes) {
            return true;
        }
    }

    return false;
}

int main() {
    // Time firstTime;
    // cout << "Enter a first time: ";
    // cin >> firstTime.h >> firstTime.m;

    // Time secondTime;
    // cout << "Enter a second time: ";
    // cin >> secondTime.h >> secondTime.m;

    // cout << "These moments of time are " << minutesSinceMidnight(firstTime) << " and " << minutesSinceMidnight(secondTime) << " after midnight." << endl;

    // cout << "The interval between them is " << minutesUntil(firstTime, secondTime) << " minutes." << endl;

    // Time time0 = {8, 10};

    // int mins;

    // cout << "Enter an amount of minutes to add: ";
    // cin >> mins;

    // Time result = addMinutes(time0, mins);

    // cout << "{" << result.h << ", " << result.m << "}" << endl;

    // Movie movie1 = {"Back to the Future", COMEDY, 116};
    // Movie movie2 = {"Black Panther", ACTION, 134};

    // TimeSlot morning = {movie1, {9, 15}};  
    // TimeSlot daytime = {movie2, {12, 15}}; 
    // TimeSlot evening = {movie2, {16, 45}}; 

    // printTimeSlot(morning);
    // printTimeSlot(daytime);
    // printTimeSlot(evening);
    
    TimeSlot ts1 = {{"The Wolf of Wall Street", COMEDY, 180}, {10, 30}};
    TimeSlot ts2 = {{"5 Centimeters Per Second", DRAMA, 63}, {10, 30}};

    bool overlap = timeOverlap(ts1, ts2);

    if (overlap) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
        }
    
    return 0;
}