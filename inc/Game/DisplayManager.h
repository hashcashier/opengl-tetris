/*
 * DisplayManager.h
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#ifndef DISPLAYMANAGER_H_
#define DISPLAYMANAGER_H_
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

class GameManager;

class DisplayManager {
private:
	GameManager *gameManager;
public:
	DisplayManager(GameManager*);
	void display();
};

#endif /* DISPLAYMANAGER_H_ */
