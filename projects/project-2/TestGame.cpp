#include <iostream>
#include "Field.hpp"
#include "Game.hpp"
using namespace std;

int main() {
    //call default constructor using
    Game minesweeper;
    //Game minesweeper(9, 3);
    minesweeper.play();
    return 0;
}