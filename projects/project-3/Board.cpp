/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 3 Task A-D

These are the constructors, destructors and methods for the 1024 game.
*/

#include "Board.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

Board::Board() {
    numRows = 3;
    numCols = 3;
    max = 0;
    target = 32;

    panel = new int*[numRows];
    for (int i = 0; i < numRows; ++i) {
        panel[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            panel[i][j] = 0;
        }
    }
}

Board::Board(int m) {
    if (m >= 1) {
        numRows = m;
        numCols = m;
    } else {
        numRows = 3;
        numCols = 3;
    }

    max = 0; 
    target = 32;

    panel = new int*[numRows];
    for (int i = 0; i < numRows; ++i) {
        panel[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            panel[i][j] = 0;
        }
    }
}

Board::Board(int m, int n) {
    if (m >= 1 && n >= 1) {
        numRows = m;
        numCols = n;
    } else {
        numRows = 3;
        numCols = 3;
    }

    max = 0; 
    target = 32;

    panel = new int*[numRows];
    for (int i = 0; i < numRows; ++i) {
        panel[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            panel[i][j] = 0;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < numRows; i++) {
        delete[] panel[i];
        panel[i] = nullptr;
    }

    delete[] panel;
    panel = nullptr;
}

void print_separate_line(int numCols) {
    cout << "+";
    for (int i = 0; i < numCols; i++) {
        cout << "----+";
    }

    cout << endl;
}

void Board::print() const {
    print_separate_line(numCols);
    for (int i = 0; i < numRows; i++) {
        cout << '|';
        for (int j = 0; j < numCols; j++) {
            if (panel[i][j] != 0) {
                cout << setw(4) << panel[i][j] << "|";
            } else {
                cout << "    |";
            }
        }
        cout << endl;
        print_separate_line(numCols);
    }
}

int Board::getNumRows() const {
    return numRows;
}

int Board::getNumCols() const {
    return numCols;
}

int Board::getTarget() const {
    return target;
}

int Board::getMax() const {
    return max;
}

bool Board::noAdjacentSameValue() const {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols - 1; j++) {
            if (panel[i][j] == panel[i][j + 1]) {
                return false;
            }
        }
    }

    for (int i = 0; i < numRows - 1; i++) {
        for (int j = 0; j < numCols; j++) {
            if (panel[i][j] == panel[i + 1][j]) {
                return false;
            }
        }
    }

    return true;
}

struct Cell {
    int row;
    int col;
};

void Board::selectRandomCell(int& row, int& col) {
    vector<Cell> emptyCells;
    Cell location;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (panel[i][j] == 0) {
                location.row = i;
                location.col = j;
                emptyCells.push_back(location);
            }
        }
    }

    int size = emptyCells.size();
    if (size == 0) {
        if (max < target) {
            cout << "Game over. Try again." << endl;
            exit(0);
        }

    }

    //srand(time(0));
    
    int pick = rand() % size;
    row = emptyCells[pick].row;
    col = emptyCells[pick].col;
    panel[row][col] = 1;

    print();

    if (size == 1 && noAdjacentSameValue()) {
        cout << "Game over. Try again." << endl;
        exit(0);
    }
}


void Board::pressUp() {
    for (int col = 0; col < numCols; col++) {
        vector<int> nonZeroes;

        for (int row = 0; row < numRows; row++) {
            if (panel[row][col] != 0) {
                nonZeroes.push_back(panel[row][col]);
            }
        }

        int curr = 0;

        while (curr < nonZeroes.size()) {
            if (curr + 1 < nonZeroes.size() && nonZeroes[curr] == nonZeroes[curr + 1]) {
                nonZeroes[curr] *= 2;
                nonZeroes[curr + 1] = 0;
                max = nonZeroes[curr] > max ? nonZeroes[curr] : max;
                curr += 2;
            } else {
                curr++;
            }
        }

        int row = 0;
        for (int curr = 0; curr < nonZeroes.size(); curr++) {
            if (nonZeroes[curr] != 0) {
                panel[row][col] = nonZeroes[curr];
                row++;
            }
        }

        while (row < numRows) {
            panel[row][col] = 0;
            row++;
        }
    }

    int row = 0;
    int col = 0;
    selectRandomCell(row, col);
}

void Board::pressDown() {
    for (int col = 0; col < numCols; col++) {
        vector<int> nonZeroes;

        for (int row = numRows - 1; row >= 0; row--) {
            if (panel[row][col] != 0) {
                nonZeroes.push_back(panel[row][col]);
            }
        }

        int curr = 0;

        while (curr < nonZeroes.size()) {
            if (curr + 1 < nonZeroes.size() && nonZeroes[curr] == nonZeroes[curr + 1]) {
                nonZeroes[curr] *= 2;
                nonZeroes[curr + 1] = 0;
                max = nonZeroes[curr] > max ? nonZeroes[curr] : max;
                curr += 2;
            } else {
                curr++;
            }
        }

        int row = numRows - 1;
        for (int curr = 0; curr < nonZeroes.size(); curr++) {
            if (nonZeroes[curr] != 0) {
                panel[row][col] = nonZeroes[curr];
                row--;
            }
        }

        while (row >= 0) {
            panel[row][col] = 0;
            row--;
        }
    }

    int row = 0;
    int col = 0;
    selectRandomCell(row, col);
}

void Board::pressLeft() {
    for (int row = 0; row < numRows; row++) {
        vector<int> nonZeroes;

        for (int col = 0; col < numCols; col++) {
            if (panel[row][col] != 0) {
                nonZeroes.push_back(panel[row][col]);
            }
        }

        int curr = 0;

        while (curr < nonZeroes.size()) {
            if (curr + 1 < nonZeroes.size() && nonZeroes[curr] == nonZeroes[curr + 1]) {
                nonZeroes[curr] *= 2;
                nonZeroes[curr + 1] = 0;
                max = nonZeroes[curr] > max ? nonZeroes[curr] : max;
                curr += 2;
            } else {
                curr++;
            }
        }

        int col = 0;
        for (int curr = 0; curr < nonZeroes.size(); curr++) {
            if (nonZeroes[curr] != 0) {
                panel[row][col] = nonZeroes[curr];
                col++;
            }
        }

        while (col < numRows) {
            panel[row][col] = 0;
            col++;
        }
    }

    int row = 0;
    int col = 0;
    selectRandomCell(row, col);
}

void Board::pressRight() {
    for (int row = 0; row < numRows; row++) {
        vector<int> nonZeroes;

        for (int col = numCols - 1; col >= 0; col--) {
            if (panel[row][col] != 0) {
                nonZeroes.push_back(panel[row][col]);
            }
        }

        int curr = 0;

        while (curr < nonZeroes.size()) {
            if (curr + 1 < nonZeroes.size() && nonZeroes[curr] == nonZeroes[curr + 1]) {
                nonZeroes[curr] *= 2;
                nonZeroes[curr + 1] = 0;
                max = nonZeroes[curr] > max ? nonZeroes[curr] : max;
                curr += 2;
            } else {
                curr++;
            }
        }

        int col = numCols -1;
        for (int curr = 0; curr < nonZeroes.size(); curr++) {
            if (nonZeroes[curr] != 0) {
                panel[row][col] = nonZeroes[curr];
                col--;
            }
        }

        while (col >= 0) {
            panel[row][col] = 0;
            col--;
        }
    }

    int row = 0;
    int col = 0;
    selectRandomCell(row, col);
}

// void Board::start() {
//     int round = 1;

//     int row = 0; 
//     int col = 0;

//     selectRandomCell(row, col);
//     selectRandomCell(row, col);

//     char ch;

//     while (true) {
//     if (max >= target) {
//         cout << "Congratulations!" << endl;
//         break;
//     }

//     if (getchar() == '\033') {
//         if (getchar() == '[') {
//             switch(getchar()) {
//                 case 'A':
//                     cout << "Round" << setw(4) << round << ": Press UP." << endl;
//                     pressUp();
//                     round++;
//                     break;
//                 case 'B':
//                     cout << "Round" << setw(4) << round << ": Press DOWN." << endl;
//                     pressDown();
//                     round++;
//                     break;
//                 case 'C':
//                     cout << "Round" << setw(4) << round << ": Press RIGHT." << endl;
//                     pressRight();
//                     round++;
//                     break;
//                 case 'D': 
//                     cout << "Round" << setw(4) << round << ": Press LEFT." << endl;
//                     pressLeft();
//                     round++;
//                     break;
//                 }
//             }
//         }
//     }
// }

void Board::start() {
    int round = 1;
    
    //TODO: call selectRandomCell twice to generate two values
    int row = 0; 
    int col = 0;

    selectRandomCell(row, col);
    selectRandomCell(row, col);
    
    char ch;
    while (true) {
        if (max >= target) { //in case goal is not a power of 2, we check for max > goal.
            cout << "Congratulation!" << endl;
            break;
        }
        
        //https://stackoverflow.com/questions/10463201/getch-and-arrowcodes
        //cannot replace getchar by getch
        //When encountering letter S, even if the
        //project does not finish running yet,
        //can leave while (true) loop.
        //Add this line to stop time out exception.
        
        ch = getchar();
        if (ch == 'S') {
            break;
        }
        
        if (ch == '\033') { // if the first value is esc
            getchar(); // skip the [
            switch(getchar()) { // the real value
                case 'A':
                    // code for arrow up
                    cout << "Round " << setw(4) << round << ": ";
                    cout << "Press UP. " 
                        << "Goal: " << target << endl;
                    pressUp();
                    round++;
                    break;
                //TODO: finish the rest of code.
                case 'B':
                    cout << "Round " << setw(4) << round << ": ";
                    cout << "Press DOWN. "
                        << "Goal: " << target << endl;
                    pressDown();
                    round++;
                    break;
                case 'C':
                    cout << "Round " << setw(4) << round << ": ";
                    cout << "Press RIGHT. "
                        << "Goal: " << target << endl;
                    pressRight();
                    round++;
                    break;
                case 'D':
                    cout << "Round " << setw(4) << round << ": ";
                    cout << "Press LEFT. "
                        << "Goal: " << target << endl;
                    pressLeft();
                    round++;
                    break;
            }
        }
    }
}