/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab8G

This program implements a horizontal edge detection operation. 
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int fcn(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    return (g + (2 * h) + i) - (a + (2 * b) + c);
}

void kernel(int image[MAX_H][MAX_W], int height, int width, int result[MAX_H][MAX_W]) {
    for (int m = 0; m< height; m++) {
        for (int n = 0; n < width; n++) {
            int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0;

            if (m - 1 >= 0 && n - 1 >= 0) {
                a = image[m - 1][n - 1];
            }

            if (m - 1 >= 0) {
                b = image[m - 1][n];
            }

            if (m - 1 >= 0 && n + 1 < width) {
                c = image[m - 1][n + 1];
            }

            if (n - 1 >= 0) {
                d = image[m][n - 1];
            }

            e = image[m][n];

            if (n + 1 < width) {
                f = image[m][n + 1];
            }

            if (m + 1 < height && n - 1 >= 0) {
                g = image[m + 1][n - 1];
            }

            if (m + 1 < height) {
                h = image[m + 1][n];
            }

            if (m + 1 < height && n + 1 < width) {
                i = image[m + 1][n + 1];
            }

            int fcnResult = fcn(a, b, c, d, e, f, g, h, i);

            if (fcnResult < 0) {
                result[m][n] = 0;
            } else if (fcnResult > 255) {
                result[m][n] = 255;
            } else {
                result[m][n] = fcnResult;
            }
        }
    }
}


int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

    int out[MAX_H][MAX_W];

    kernel(img, h, w, out);

	// and save this new image to file "outImage.pgm"
	// writeImage(out, h, w);
    writeImage(out, h, w);
}
