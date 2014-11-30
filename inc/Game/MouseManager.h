/*
 * MouseManager.h
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#ifndef MOUSEMANAGER_H_
#define MOUSEMANAGER_H_
#include <bits/stdc++.h>
using namespace std;

class GameManager;

class MouseManager {
private:
	GameManager *gameManager;
public:
	MouseManager(GameManager*);
	void respondToClick(int, int, int, int);
};

#endif /* MOUSEMANAGER_H_ */
