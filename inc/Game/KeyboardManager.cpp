/*
 * KeyboardManager.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#include "KeyboardManager.h"
#include "GameManager.h"
#include "Menu/MenuKeyboard.h"
#include "Play/PlayKeyboard.h"

KeyboardManager::KeyboardManager(GameManager *gm) {
	gameManager = gm;
}

void KeyboardManager::respondToStroke(unsigned char c, int x, int y) {
	int state = gameManager->getState();
	cerr << "Keystroke: " << c << ' ' << x << ' ' << y << ' ' << state << endl;

	switch(state){
	case GameManager::STATE_STOP:
		MenuKeyboard::respondToStroke(c, x, y, gameManager);
		break;
	case GameManager::STATE_PLAY:
	case GameManager::STATE_PAUSE:
	case GameManager::STATE_OVER:
		PlayKeyboard::respondToStroke(c, x, y, gameManager);
		break;
	default:
		break;
	}

}

void KeyboardManager::respondToKey(int key, int x, int y) {
	int state = gameManager->getState();
	cerr << "Key pressed: " << key << ' ' << x << ' ' << y << ' ' << state << endl;

	switch(state){
	case GameManager::STATE_STOP:
		break;
	case GameManager::STATE_PLAY:
	case GameManager::STATE_PAUSE:
		PlayKeyboard::respondToKey(key, x, y, gameManager);
		break;
	default:
		break;
	}

}

