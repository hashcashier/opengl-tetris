/*
 * PlayActions.h
 *
 *  Created on: Oct 15, 2014
 *      Author: rami
 */

#ifndef PLAYACTIONS_H_
#define PLAYACTIONS_H_
#include <bits/stdc++.h>
#include "../GameManager.h"

using namespace std;

typedef vector<vector<Tetromino<int>>> tetromat;


class PlayActions {
public:
	static bool assertEmpty(Tetromino<int> &active, tetromat &tets, int dr, int dc);
	static void moveLeft(GameManager* gameManager);
	static void moveRight(GameManager* gameManager);
	static void moveDown(GameManager* gameManager);
	static void rotateClockwise(GameManager* gameManager);
	static void rotateAntiClockwise(GameManager* gameManager);
};

#endif /* PLAYACTIONS_H_ */
