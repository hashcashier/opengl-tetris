/*
 * GameManager.h
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_
#include <bits/stdc++.h>
#include "../Shapes/Tetromino.h"
#include "Play/PlayAnimator.h"

using namespace std;

class KeyboardManager;
class MouseManager;
class DisplayManager;

typedef chrono::time_point<chrono::system_clock> timestamp;
typedef chrono::duration<double> duration;
typedef vector<vector<Tetromino<int>>> tetromat;

class GameManager {
private:
	KeyboardManager *keyboardManager;
	MouseManager *mouseManager;
	DisplayManager *displayManager;
	int score, state;
	thread::id animatorId;
	tetromat shapes;
	Tetromino<int> activeTetromino = Tetromino<int>(0, 0);
	timestamp lastAnimation;
	duration nextAnimation;
	thread animator;
	mutex mut;
	condition_variable cond;

public:
	GameManager();

	DisplayManager* getDisplayManager() const;
	KeyboardManager* getKeyboardManager() const;
	MouseManager* getMouseManager() const;
	int getScore() const;
	int getState() const;

	void startGame();
	void pauseGame();
	void resumeGame();
	void endGame();
	void gameOver();
	void exit();

	bool isPaused();
	bool isStopped();
	bool isOver();

	void updateScore(int);

	tetromat *getTetrominos();
	void setTetrominos(tetromat tetrominos);

	timestamp getLastAnimationTime();
	void setLastAnimationTime(timestamp time);

	duration getNextAnimation();
	void resetNextAnimation();

	mutex *getMutex();
	condition_variable *getConditionVar();

	thread::id getAnimatorId();

	Tetromino<int> getActiveTetromino();
	void setActiveTetromino(Tetromino<int> tetromino);

	static const int STATE_STOP = 0, STATE_PLAY = 1, STATE_PAUSE = 2, STATE_OVER = 3;
};
#endif /* GAMEMANAGER_H_ */
