/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2 Task B

These are the methods for the Game class for the Minesweeper game.
*/

#include "Game.hpp"
#include <iostream>
using namespace std;

//Default constructor of Game class.
Game::Game() : area() {
}

//Non-default constructor of Game class.
Game::Game(int size, int num_mines) : area( size, num_mines) {
}

//Gets user from input that is in bounds and hasn't been checked yet
int Game::input() const {
    cout << "Please choose a cell (the first starts from 0): ";
    int num;

    cin >> num;
    //If num is out of range
    while (num < 0 || num >= area.get_size()) {
        cout << "Enter an integer in [0, " << area.get_size() - 1 << "]: ";

        cin >> num;
    }

    //If cell is checked already
    while (area.is_checked(num)) {
        cout << "Cell is already chosen. Please re-enter: ";

        cin >> num;
    }

    return num;
}

//TODO: code to show how to play a game. 
//Star with an empty layout of field,
//keep choosing a valid index for an unchecked cell 
//until one of the following happens.
//(a) A cell with a mine is chosen, 
//    in that case, print "Mine explodes! Game ends."
//(b) All cells without mines are found out, 
//    in that case, print 
//    "Congratulations! Find out all the cells without mines."
//(c) After the game, print the layout of fields 
//    where mines are marked as * 
//    and nonmines are marked by its number of neighbor(s).
void Game::play() {
    bool gameWon = true;
    int round = 1;
    int size = area.get_size();
    int num_mines = area.get_num_mines();

    int moves_left = size - num_mines;

    cout << area.empty_layout_string() << endl;

    while (moves_left > 0) {
        cout << "Round " << round << ": ";
        int index = input();

        if (area.has_mine(index)) {
            cout << "Mine explodes! Game ends." << endl;
            gameWon = false;
            break;

        } else {
            area.mark_checked(index);

            cout << area.to_string() << endl;
        }

        moves_left--;
        round++;
    }

    if (gameWon) {
        cout << "Congratulations! Find out all the cells without mines." << endl;
    }
    
    cout << endl << "The answer is " << endl;
    cout << area.answer_string() << endl;
}