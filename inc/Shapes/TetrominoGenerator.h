/*
 * TetrominoGenerator.h
 *
 *  Created on: Oct 15, 2014
 *      Author: rami
 */

#ifndef TETROMINOGENERATOR_H_
#define TETROMINOGENERATOR_H_

#include <bits/stdc++.h>
#include "Tetromino.h"

using namespace std;

template<typename T>
class TetrominoGenerator {
	static bool seeded;
	static void seed();
	static vector<Tetromino<T>> tetrominos;
	static uniform_int_distribution<> dist;
	static random_device rd;
	static mt19937 gen;
public:
	static Tetromino<T> generate();
};

#endif /* TETROMINOGENERATOR_H_ */
