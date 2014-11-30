/*
 * MouseManager.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#include "MouseManager.h"
#include "GameManager.h"

MouseManager::MouseManager(GameManager *gm) {
	gameManager = gm;
}

void MouseManager::respondToClick(int button, int state, int x, int y) {
	cerr << "Mouseclick: " << button << ' ' << state << ' ' << x << ' ' << y << endl;
}
