/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Quiz 09

This program returns an output image that has a checkerboard pattern,
alternating between the image and black pixels.
*/

if ((row + col) % 2 == 0) {
    out[row][col] = 0;
} else {
    out[row][col] = img[row][col];
}