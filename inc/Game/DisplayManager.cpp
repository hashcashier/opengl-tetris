/*
 * DisplayManager.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#include "DisplayManager.h"
#include "GameManager.h"
#include "Menu/MenuDisplay.h"
#include "Play/PlayDisplay.h"

DisplayManager::DisplayManager(GameManager *gm) {
	gameManager = gm;
}

void DisplayManager::display() {
	int state = gameManager->getState();
	switch(state) {
	case GameManager::STATE_PAUSE:
	case GameManager::STATE_PLAY:
	case GameManager::STATE_OVER:
		PlayDisplay::display(gameManager);
		break;
	case GameManager::STATE_STOP:
		MenuDisplay::display(gameManager);
		break;
	default:
		break;
	}
}
