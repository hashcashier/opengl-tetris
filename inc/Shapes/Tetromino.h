/*
 * Tetromino.h
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#ifndef TETROMINO_H_
#define TETROMINO_H_

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Tetromino {
public:
	double red, green, blue;
	int row, col;
	vector<complex<T>> points;
	Tetromino(int row, int col);
	Tetromino(vector<complex<T>> pts, int row, int col);
	Tetromino(complex<T>, int row, int col);
	Tetromino<T> translate(T drow, T dcol);
	Tetromino<T> rotateCW();
	Tetromino<T> rotateCCW();
	bool isBlank();
	void setColor(double r, double g, double b);
};

#endif /* TETROMINO_H_ */
