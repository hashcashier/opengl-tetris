/*
 * GameManager.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#include "GameManager.h"
#include "DisplayManager.h"
#include "KeyboardManager.h"
#include "MouseManager.h"
#include "../gl/GLUT.h"

GameManager::GameManager() {
	displayManager = new DisplayManager(this);
	keyboardManager = new KeyboardManager(this);
	mouseManager = new MouseManager(this);
	score = 0;
	state = STATE_STOP;
}

void GameManager::startGame() {
	lastAnimation = chrono::system_clock::now();
	resetNextAnimation();

	activeTetromino = Tetromino<int>(0, 0);

	animator = thread{PlayAnimator::animate, this};
	animatorId = animator.get_id();
	animator.detach();

	cerr << "Game started!" << endl;
	score = 0;
	shapes.assign(16, vector<Tetromino<int>>(10, Tetromino<int>(0, 0)));
	state = STATE_PLAY;
	GLUT::redisplay();
}

void GameManager::pauseGame() {
	lock_guard<mutex> lk(mut);
	duration deltaTime = chrono::system_clock::now() - lastAnimation;
	nextAnimation -= deltaTime;
	if(nextAnimation.count() < 0)
		nextAnimation = duration(0);
	cerr << "Played for: " << deltaTime.count() << ", next animation: " << nextAnimation.count() << endl;

	cerr << "Pausing Game" << endl;
	state = STATE_PAUSE;
	GLUT::redisplay();
}

void GameManager::resumeGame() {
	lock_guard<mutex> lk(mut);
	lastAnimation = chrono::system_clock::now();
	cond.notify_one();

	cerr << "Resuming Game" << endl;
	state = STATE_PLAY;
	GLUT::redisplay();
}

void GameManager::endGame() {
	lock_guard<mutex> lk(mut);
	cerr << "Ending Game" << endl;
	state = STATE_STOP;
	GLUT::redisplay();
}

void GameManager::gameOver() {
//	lock_guard<mutex> lk(mut);
	cerr << "Game Over" << endl;
	state = STATE_OVER;
	GLUT::redisplay();
}

void GameManager::exit() {
	glutExit();
}

DisplayManager* GameManager::getDisplayManager() const {
	return displayManager;
}

KeyboardManager* GameManager::getKeyboardManager() const {
	return keyboardManager;
}

MouseManager* GameManager::getMouseManager() const {
	return mouseManager;
}

int GameManager::getScore() const {
	return score;
}

int GameManager::getState() const {
	return state;
}

void GameManager::updateScore(int value) {
	score += value;
}

bool GameManager::isPaused() {
	return state == STATE_PAUSE;
}

bool GameManager::isStopped() {
	return state == STATE_STOP;
}

bool GameManager::isOver() {
	return state == STATE_OVER;
}

tetromat *GameManager::getTetrominos() {
	return &shapes;
}


void GameManager::setTetrominos(tetromat tetrominos) {
	shapes = tetrominos;
}

timestamp GameManager::getLastAnimationTime() {
	return lastAnimation;
}

void GameManager::setLastAnimationTime(timestamp time) {
	lastAnimation = time;
}

duration GameManager::getNextAnimation() {
	return nextAnimation;
}

void GameManager::resetNextAnimation() {
	nextAnimation = duration(1);
}

mutex *GameManager::getMutex() {
	return &mut;
}

condition_variable* GameManager::getConditionVar() {
	return &cond;
}

thread::id GameManager::getAnimatorId() {
	return animatorId;
}

Tetromino<int> GameManager::getActiveTetromino() {
	return activeTetromino;
}

void GameManager::setActiveTetromino(Tetromino<int> tetromino) {
	activeTetromino = tetromino;
}
