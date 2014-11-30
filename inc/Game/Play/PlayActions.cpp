/*
 * PlayActions.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: rami
 */

#include "PlayActions.h"

bool PlayActions::assertEmpty(Tetromino<int> &active, tetromat &tets, int dr, int dc) {
	int n = tets.size(), m = tets.empty() ? 0 : tets[0].size();
	for(int i = 0; i < (int) active.points.size(); i++) {
		int col = active.col + active.points[i].real() + dc;
		int row = active.row + active.points[i].imag() + dr;
		if(col < 0 || col >= m || row < 0 || row >= n)
			return false;
		if(!tets[row][col].isBlank())
			return false;
	}
	return true;
}

void PlayActions::moveLeft(GameManager* gameManager) {
	lock_guard<mutex> lk(*(gameManager->getMutex()));
	Tetromino<int> active = gameManager->getActiveTetromino();
	tetromat &tets = *(gameManager->getTetrominos());
	if(assertEmpty(active, tets, 0, -1)) {
		gameManager->setActiveTetromino(active.translate(0, -1));
		GLUT::redisplay();
	}
}

void PlayActions::moveRight(GameManager* gameManager) {
	lock_guard<mutex> lk(*(gameManager->getMutex()));
	Tetromino<int> active = gameManager->getActiveTetromino();
	tetromat &tets = *(gameManager->getTetrominos());
	if(assertEmpty(active, tets, 0, 1)) {
		gameManager->setActiveTetromino(active.translate(0, 1));
		GLUT::redisplay();
	}
}

void PlayActions::moveDown(GameManager* gameManager) {
	lock_guard<mutex> lk(*(gameManager->getMutex()));
	Tetromino<int> active = gameManager->getActiveTetromino();
	tetromat &tets = *(gameManager->getTetrominos());
	if(assertEmpty(active, tets, 1, 0)) {
		gameManager->setActiveTetromino(active.translate(1, 0));
		GLUT::redisplay();
	}
}

void PlayActions::rotateClockwise(GameManager* gameManager) {
	lock_guard<mutex> lk(*(gameManager->getMutex()));
	Tetromino<int> active = gameManager->getActiveTetromino();
	tetromat &tets = *(gameManager->getTetrominos());

	Tetromino<int> neu = active.rotateCW();
	if(assertEmpty(neu, tets, 0, 0)) {
		gameManager->setActiveTetromino(neu);
		GLUT::redisplay();
	}
}

void PlayActions::rotateAntiClockwise(GameManager* gameManager) {
	lock_guard<mutex> lk(*(gameManager->getMutex()));
	Tetromino<int> active = gameManager->getActiveTetromino();
	tetromat &tets = *(gameManager->getTetrominos());

	Tetromino<int> neu = active.rotateCCW();
	if(assertEmpty(neu, tets, 0, 0)) {
		gameManager->setActiveTetromino(neu);
		GLUT::redisplay();
	}
}
