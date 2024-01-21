/*
Author: Mackenzie Eng
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2 Task A

These are the methods for the Field class for the Minesweeper game.
*/

#include "Field.hpp"
#include <iostream>
#include <cstdlib> //rand, srand
#include <ctime>

using namespace std;

// int main() {
//     return 0;
// }

//Define default constructor 
Field::Field() {
    //6. Use srand(time(NULL)); to use current time as seed
    //   to generate a sequence of random integers.
    srand(time(NULL));

    //1. Initialize size to be 7 and num_mines to be 2. 
    size = 7;
    num_mines = 2;

    //2. Set cells to be an array with capacity size, 
    //   elements are either 0 or 1, where number of 1's 
    //   equals num_mines.
    cells = new int[size];

    int num_ones = 0;

    while (num_ones < num_mines) {
        int position = rand() % size;

        if (cells[position] == 0) {
            cells[position] = 1;
            num_ones++;
        }
    }

    //3. Set checked to be an array with capacity size, 
    //   each element is set to be false.
    checked = new bool[size];

    for (int i = 0; i < size; i++) {
        checked[i] = false;
    }
}
  
//Define non-default constructor
Field::Field(int size, int num_mines) {
    //6. Use srand(time(NULL)); to use current time as seed
    //   to generate a sequence of random integers.
    srand(time(NULL));

    //1. If given parameter size is <= 3, 
    //   set data member size to be 7, 
    //   otherwise, use given parameter size to 
    //   inialize data member size.
    if (size <= 3) {
        size = 7;
    }

    //2. If given parameter num_mines < 2, 
    //   set data member num_mines to be 2, 
    //   otherwise, use given parameter num_mines to 
    //   inialize data member num_mines.
    if (num_mines < 2) {
        num_mines = 2;
    } 

    //3. If num_mines >= size, which means mines are 
    //   more than the number of cells, 
    //   then set num_mines to be one third (1/3) of size.
    if (num_mines >= size) {
        num_mines = size / 3;
    }

    this->size = size;
    this->num_mines = num_mines;

    //4. Set cells to be an array with capacity size, 
    //   elements are either 0 or 1, 
    //   where number of 1's equals num_mines.
    cells = new int[size];

    for (int i = 0; i < size; i++) {
        cells[i] = 0;
    }

    int num_ones = 0;

    while (num_ones < num_mines) {
        int position = rand() % size;

        if (cells[position] == 0) {
            cells[position] = 1;
            num_ones++;
        }
    }

    //5. Set checked to be an array with capacity size, 
    //   each element is set to be false. 
    checked = new bool[size];

    for (int i = 0; i < size; i++) {
        checked[i] = false;
    }

}

//destructor ~Field
Field::~Field() {
    //TODO: release dynamically allocated memory
    //      applied by the data members of the current object.
    //      After releasing the memory,
    //      set the corresponding pointer to nullptr
    //      to avoid dangling pointer problem.
    delete[] this->cells;
    delete[] this->checked;

    this->cells = nullptr;
    this->checked = nullptr;
}

//Return a string representing labels of indices.
string get_labels(int size) {
    string str;
    for (int i = 0; i < size; i++) { 
        str += "  ";
        if (i < 10)
           str += " " + std::to_string(i);
        else str += to_string(i);
        str += "  ";
    }
    str += "\n";
    return str;
}

//Since get_separate_line is not a must-provided
//functionality for Field class,
//it is not a method in Field class.
//Hence it does not have Field:: in front of its name.
//Function get_separate_line is called by
//to_string method of Field class.
string get_separate_line(int size) {
    string str = "+";
    for (int i = 0; i < size; i++)
        str += "-----+";
    str += "\n";
    return str;
}

//Return a string representing the cells with labels.
string Field::to_string() const {
    string str = get_labels(size);
    str += get_separate_line(size);

    str += "|";
    for (int i = 0; i < size; i++) {
    //If a cell does not have a mine and is checked, 
    //then display the number of its neighbors,
    //Otherwise, cell does not have a mine 
    //but is not checked or a cell has a mine,
    //display an empty cell. 
    //    if (cells[i] == 0) 
    //     {
    //        if (checked[i] == true)
    //            str += "  " + std::to_string(neighbor_mines(i)) +
    //                   "  |";
    //        else str += "     |";
    //     }
    //     else //must have a mine 
    //         str += "     |";

        //The above if-else can be simplified.
        //Idea: 

        //if a cell has no mine and is checked,
        //display its neighboring information,
        if (this->cells[i] == 0 && this->checked[i] == true) {
            str += "  " + std::to_string(neighbor_mines(i)) + "  |";
        } else {
            //otherwise, that is a cell with a mine or
            //it does not have a mine but is not checked yet,
            //so do not display anything in that cell.
            str += "     |";
        }
    }

    str += "\n";

    str += get_separate_line(size);

    return str;
}

//Return a string representing the cells with answers revealed
string Field::answer_string() const {
    string str = get_labels(size);
    str += get_separate_line(size);

    str += '|';
    
    for (int i = 0; i < this->size; i++) {
        //If a cell does not have a mine, 
        //then display the number of its neighbors, 
        if (this->cells[i] == 0) {
            str += "  " + std::to_string(neighbor_mines(i)) + "  |";
        } else {
            //Else it is a mine, so display an asterisk
            str += "  *  |";
        }
    }

    str += "\n";

    str += get_separate_line(size);

    return str;
}

//Returns a string representing the cells empty
//This method is called in the beginning of a game.
string Field::empty_layout_string() const {
    string str = get_labels(size);
    str += get_separate_line(size);

    str += '|';

    for (int i = 0; i < this->size; i++) {
        str += "     |";
    }

    str += "\n";

    str += get_separate_line(size);

    return str;
}

//Returns the number of cells of the field (the value of data member size).
int Field::get_size() const {
    return this->size;
}

//Return the number of mines of the field (the value of data member num_mines).
int Field::get_num_mines() const {
    return this->num_mines;
}

//TODO: if current cell indexed at index 
//does not contain a mine, 
//return number of mines in its left neighbor (if any) and
//right neighbor (if any), otherwise, return -1.
int Field::neighbor_mines(int index) const {
    if (this->cells[index] == 0) {
        int num_mines = 0;
        
        int left_neighbor = index - 1;

        if (left_neighbor >= 0 && left_neighbor < this->size) {
            if (this->has_mine(left_neighbor)) {
                num_mines++;
            }
        }

        int right_neighbor = index + 1;

        if (right_neighbor >= 0 && right_neighbor < this->size) {
            if (this->has_mine(right_neighbor)) {
                num_mines++;
            }
        }

        return num_mines;
    } else {
        return -1;
    }
}

//Marks a cell as checked
void Field::mark_checked(int index) {
    //checks if index is in bounds
    if (index >= 0 && index < this->size) {
        this->checked[index] = true;
    }
}

//Returns the value of index in the checked array
bool Field::is_checked(int index) const {
    if (this->checked[index] == true) {
        return true;
    } else {
        return false;
    }
}

//Checks whether cell has a mine
bool Field::has_mine(int index) const {
    //if the element at the corresponding index of cells contains a mine, return true
    if (this->cells[index] == 1) {
        return true;
    } else {
        return false;
    }
}