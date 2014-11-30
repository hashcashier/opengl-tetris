/*
 * PlayAnimator.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: rami
 */

#include "PlayAnimator.h"

#define EPS 1e-3

GameManager *globalGM;

bool checkState() {
	return globalGM->getState() == GameManager::STATE_PLAY;
}

extern void idleFunc();

void PlayAnimator::animate(GameManager *gameManager) {
	globalGM = gameManager;
	condition_variable *cond = gameManager->getConditionVar();
	mutex *mut = gameManager->getMutex();
	while(gameManager->getAnimatorId() == this_thread::get_id()) {
		unique_lock<mutex> lk(*mut);
		cond->wait(lk, checkState);

		duration remaining = gameManager->getNextAnimation();
		remaining -= chrono::system_clock::now() - gameManager->getLastAnimationTime();

		cout << "Time To Animate: " << remaining.count() << endl;
		if(remaining.count() > EPS) {
			lk.unlock();
			this_thread::sleep_for(remaining);
			continue;
		} else if(gameManager->getAnimatorId() != this_thread::get_id())
			break;

		Tetromino<int> active = gameManager->getActiveTetromino();
		tetromat &tets = *(gameManager->getTetrominos());

		int n = tets.size(), m = tets[0].size();

		if(!active.isBlank()) {
			cerr << "Falling down" << endl;
			// move down active tetromino
			bool freeze = false;
			for(int i = 0; !freeze && i < active.points.size(); i++) {
				int col = active.col + active.points[i].real();
				int row = active.row + active.points[i].imag();
				if(row == n-1 || !tets[row+1][col].isBlank())
					freeze = true;
			}
			if(freeze) {
				for(int i = 0; i < active.points.size(); i++) {
					int col = active.col + active.points[i].real();
					int row = active.row + active.points[i].imag();
					tets[row][col] = Tetromino<int>(active.points[i], row, col);
					tets[row][col].setColor(active.red, active.green, active.blue);
				}
				active = Tetromino<int>(0, 0);
			} else {
				active.row += 1;
				gameManager->setActiveTetromino(active);
			}
		}

		for(int i = n - 1; i >= 0; i--) {
			bool full = true;
			for(int j = 0; full && j < m; j++)
				if(tets[i][j].isBlank())
					full = false;

			if(full) {
				gameManager->updateScore(10);
				tets[i] = vector<Tetromino<int>>(m, Tetromino<int>(0, 0));
				for(int j = i - 1; j >= 0; j--)
					swap(tets[j], tets[j+1]);
			}
		}

		if(active.isBlank()) {
			// spawn random tetromino from tetromino generator
			Tetromino<int> next = TetrominoGenerator<int>::generate();
			if(!PlayActions::assertEmpty(next, tets, 0, 0))
				gameManager->gameOver();
			else
				gameManager->setActiveTetromino(next);
		}

		gameManager->resetNextAnimation();
		gameManager->setLastAnimationTime(chrono::system_clock::now());
		cerr << "Tic Toc.." << endl;
//		GLUT::redisplay();
		GLUT::pendingRedisplay = true;
		glutIdleFunc(idleFunc);
	}
}
