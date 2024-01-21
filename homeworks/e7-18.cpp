/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: E 7.16

Define a structure Triangle that contains three Point members. Write a function that
computes the perimeter of a Triangle. Write a program that reads the coordinates of
the points, calls your function, and displays the result.
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

struct Triangle {
    Point pointA;
    Point pointB;
    Point pointC;
};

double perimeter(Triangle triangle) {
    double sideA = distance(triangle.pointA, triangle.pointB);
    double sideB = distance(triangle.pointB, triangle.pointC);
    double sideC = distance(triangle.pointC, triangle.pointA);

    return sideA + sideB + sideC;
}

int main() {
    Point pointA = {0, 0};
    Point pointB = {0, 5};
    Point pointC = {3, 10};

    Triangle triangle = {pointA, pointB, pointC};

    cout << perimeter(triangle);

    return 0;
}