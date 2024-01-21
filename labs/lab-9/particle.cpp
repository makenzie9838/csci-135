/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab9A-C, E

This program models accelerated motion of a particle, which is done by 
making the velocity of the particle increase on each time step.
*/

#include <iostream>
using namespace std;

class Particle {
    public:
       double positionX;
       double positionY;
       double positionZ;

       double velocityX;
       double velocityY;
       double velocityZ;      
};

class Coord3D {
    public:
        double x;
        double y;
        double z;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
    Particle * p = new Particle;

    p->positionX = x;
    p->positionY = y;
    p->positionZ = z;

    p->velocityX = vx;
    p->velocityY = vy;
    p->velocityZ = vz;

    return p;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
    p->velocityX = vx;
    p->velocityY = vy;
    p->velocityZ = vz;
}

// get its current position
Coord3D getPosition(Particle *p) {
    Coord3D currentPosition;

    currentPosition.x = p->positionX;
    currentPosition.y = p->positionY;
    currentPosition.z = p->positionZ;

    return currentPosition;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt) {
    p->positionX = p->positionX + (p->velocityX * dt);
    p->positionY = p->positionY + (p->velocityY * dt);
    p->positionZ = p->positionZ + (p->velocityZ * dt);
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p) {
    delete p;
}

int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: " << getPosition(p).x << ", " << getPosition(p).y << ", " << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}