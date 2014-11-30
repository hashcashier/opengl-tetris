/*
 * MenuKeyboard.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */
#include "MenuKeyboard.h"

void MenuKeyboard::respondToStroke(unsigned char key, int x, int y, GameManager* gameManager) {
//	assert(gameManager->getState() == GameManager::STATE_STOP);

	switch(key) {
	case 's':
	case 'S':
		gameManager->startGame();
		break;
	case '':
		gameManager->exit();
		break;
	default:
		break;
	}
}



