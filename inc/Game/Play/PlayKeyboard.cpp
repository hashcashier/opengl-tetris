/*
 * PlayKeyboard.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */
#include "PlayKeyboard.h"

void PlayKeyboard::respondToStroke(unsigned char key, int x, int y, GameManager* gameManager) {
	switch(key) {
	case 'p':
	case 'P':
		if(gameManager->getState() == GameManager::STATE_PLAY)
			gameManager->pauseGame();
		break;
	case 'r':
	case 'R':
		if(gameManager->getState() == GameManager::STATE_PAUSE)
			gameManager->resumeGame();
		break;
	case 's':
	case 'S':
		gameManager->endGame();
		break;
	case 'z':
	case 'Z':
		if(gameManager->getState() == GameManager::STATE_PLAY)
			PlayActions::rotateAntiClockwise(gameManager);
		break;
	case 'x':
	case 'X':
		if(gameManager->getState() == GameManager::STATE_PLAY)
			PlayActions::rotateClockwise(gameManager);
		break;
	default:
		break;
	}
}

void PlayKeyboard::respondToKey(int key, int x, int y, GameManager* gameManager) {
	switch(key) {
	case GLUT_KEY_LEFT:
		if(gameManager->getState() == GameManager::STATE_PLAY)
			PlayActions::moveLeft(gameManager);
		break;
	case GLUT_KEY_RIGHT:
		if(gameManager->getState() == GameManager::STATE_PLAY)
			PlayActions::moveRight(gameManager);
		break;
	case GLUT_KEY_DOWN:
		if(gameManager->getState() == GameManager::STATE_PLAY)
			PlayActions::moveDown(gameManager);
		break;
	default:
		break;
	}
}


