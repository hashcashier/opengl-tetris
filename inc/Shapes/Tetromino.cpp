/*
 * Tetromino.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: rami
 */

#include "Tetromino.h"

template<typename T>
Tetromino<T>::Tetromino(int r, int c) {
	red = green = blue = 0;
	row = r;
	col = c;
}

template<typename T>
Tetromino<T>::Tetromino(vector<complex<T>> pts, int r, int c) {
	red = green = blue = 0;
	row = r;
	col = c;
	points = pts;
}

template<typename T>
Tetromino<T>::Tetromino(complex<T> pt, int r, int c) {
	red = green = blue = 0;
	row = r;
	col = c;
	points.push_back(pt);
}

template<typename T>
Tetromino<T> Tetromino<T>::translate(T drow, T dcol) {
	Tetromino<T> res(points, row+drow, col+dcol);
	res.setColor(red, green, blue);
	return res;
}

template<typename T>
Tetromino<T> Tetromino<T>::rotateCW() {
	Tetromino<T> res(row, col);
	res.setColor(red, green, blue);
	for(int i = 0; i < points.size(); i++)
		// col -> real, row -> imag
		res.points.push_back(complex<T>(3 - points[i].imag(), points[i].real()));
	return res;
}

template<typename T>
Tetromino<T> Tetromino<T>::rotateCCW() {
	Tetromino<T> res(row, col);
	res.setColor(red, green, blue);
	for(int i = 0; i < points.size(); i++)
		// col -> real, row -> imag
		res.points.push_back(complex<T>(points[i].imag(), 3 - points[i].real()));
	return res;
}

template<typename T>
bool Tetromino<T>::isBlank() {
	return points.empty();
}

template<typename T>
void Tetromino<T>::setColor(double r, double g, double b) {
	red = r;
	green = g;
	blue = b;
}

template class Tetromino<int>;
