/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 7.16

This program computes the distance between 2-points based on x and y
coordinates
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point pointA = {1, 1};

    Point pointB = {0, 0};

    cout << distance(pointA, pointB);

    return 0;
}