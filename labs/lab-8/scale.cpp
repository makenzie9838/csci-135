/*
Author: Mackenzie Eng
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab8E

This program scales the original picture to 200% of its size.
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

void scale(const int img[MAX_H][MAX_W], int scaledImg[MAX_H][MAX_W], int& h, int& w) {
    // (2a) Update h to be new height of the scaled image.
    // (2b) Update w to be new width of the scaled image.
    h = 2 * h;
    w = 2 * w;

    // (2c) For row index i in [0, h) and column index j in [0, w), set scaledImg[i][j] by some cell
    // in img, that is, map scaledImg[i][j] to img[x][y]. Find out how x is related with i and how
    // y is related with j.
    for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
            // scaledImg[row + 1][col + 1] = img[row][col];
            // scaledImg[row + 1][col + 2] = img[row][col];
            // scaledImg[row + 2][col + 1] = img[row][col];
            // scaledImg[row + 2][col + 2] = img[row][col];
            scaledImg[row][col] = img[row / 2][col / 2];
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

    int scaledImg[MAX_H][MAX_W];

    scale(img, scaledImg, h, w);

    // for(int row = 0; row < h; row++) {
	// 	for(int col = 0; col < w; col++) {
	// 		out[row][col] = img[row][col];
	// 	}
	// }

	// and save this new image to file "outImage.pgm"
	// writeImage(out, h, w);
    writeImage(scaledImg, h, w);
}
