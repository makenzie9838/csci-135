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

    if (minutesUntil(ts1, ts2) < 0) {
        intervalBetweenStartTimes = minutesUntil(ts2, ts1);

        if (ts2.movie.duration > intervalBetweenStartTimes) {
            return false;
        }

    } else {
        intervalBetweenStartTimes = minutesUntil(ts1, ts2);

        if (ts1.movie.duration > intervalBetweenStartTimes) {
            return false;
        }
    }

    return true;
}
