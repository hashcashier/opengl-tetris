/*
 * TetrominoGenerator.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: rami
 */

#include "TetrominoGenerator.h"


template<typename T>
uniform_int_distribution<> TetrominoGenerator<T>::dist;

template<typename T>
random_device TetrominoGenerator<T>::rd;

template<typename T>
mt19937 TetrominoGenerator<T>::gen{rd()};

template<typename T>
bool TetrominoGenerator<T>::seeded = false;

template<typename T>
vector<Tetromino<T>> TetrominoGenerator<T>::tetrominos;

template<typename T>
void TetrominoGenerator<T>::seed() {
	ifstream input("tetrominoes.dat", std::ios::in);
	if(input) {
		int num;
		input >> num;
		for(int i = 0; i < num; i++) {
			double r, g, b;
			input >> r >> g >> b;
			Tetromino<int> tetromino(0, 3);
			for(int j = 0; j < 4; j++) {
				T row, col;
				input >> row >> col;
				tetromino.points.push_back(complex<T>(col, row));
			}
			tetromino.setColor(r, g, b);
			tetrominos.push_back(tetromino);
		}

		dist = uniform_int_distribution<>(0, num-1);
	} else {
		cerr << "Critical Error. Tetrominoes file not found!" << endl;
	}
}

template<typename T>
Tetromino<T> TetrominoGenerator<T>::generate() {
	if(!seeded)
		seed();
	if(tetrominos.empty()) {
		cerr << "Critical error. Tetrominoes file is empty." << endl;
		Tetromino<int> res = Tetromino<int>(complex<T>(0, 0), 0, 0);
		res.setColor(1, 1, 1);
		return res;
	}


	return tetrominos[dist(gen)];
}

template class TetrominoGenerator<int>;
