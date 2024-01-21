/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab9A-C, E

This program defines a function length() that receives the coordinates of a 
point P passed as a pointer, and computes the distance from the origin 
to the point P.

fartherFromOrigin returns the pointer of the coordinates furthest away from
the origin.

move gets the position and the velocity of an object and has to compute 
object’s new coordinates after the time interval dt. The function does not 
return any values, instead, it should update the object’s position ppos 
with its new position coordinates

createCoord3D allocates memory and initializes.

deleteCoord3D frees memory.
*/

#include <iostream>
#include <cmath>
using namespace std;


class Coord3D {
    public:
        double x;
        double y;
        double z;
};

double length(Coord3D *p) {
    return sqrt((p->x * p->x) + (p->y * p->y) + (p->z * p->z));
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    if (length(p1) > length(p2)) {
        return p1;
    } else {
        return p2;
    }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    ppos->x = ppos->x + (pvel->x * dt);
    ppos->y = ppos->y + (pvel->y * dt);
    ppos->z = ppos->z + (pvel->z * dt);
}

Coord3D* createCoord3D(double x, double y, double z) {
    Coord3D * p = new Coord3D;

    p->x = x;
    p->y = y;
    p->z = z;

    return p;
}

void deleteCoord3D(Coord3D *p) {
    delete p;
}

int main() {
    // Coord3D pointP = {10, 20, 30};
    // Coord3D pointQ = {-20, 21, -22};

    //cout << length(&pointP) << endl; // would print 37.4166

    // cout << "Address of P: " << &pointP << endl;
    // cout << "Address of Q: " << &pointQ << endl << endl;

    // Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);

    // cout << ans << endl;

    //Coord3D pos = {0, 0, 100.0};
    //Coord3D vel = {1, -5, 0.2};

    //move(&pos, &vel, 2.0); // object pos gets changed
    //cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4

    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);

    return 0;
}