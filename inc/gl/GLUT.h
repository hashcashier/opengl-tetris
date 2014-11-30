/*
 * GLUT.h
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#ifndef GLUT_H_
#define GLUT_H_
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

using namespace std;

class GameManager;
class DisplayManager;
class KeyboardManager;
class MouseManager;

void displayFunction();
void keyboardFunction();
void mouseFunction();

class GLUT {
public:
	static DisplayManager* displayManager;
	static KeyboardManager* keyboardManager;
	static MouseManager* mouseManager;
	static bool pendingRedisplay;
	static void bindToGame(GameManager*);
	static void initWindow(const char*, int, int, int*, char**);
	static void redisplay();
	static void mainLoop();
	static void printText(int x, int y, string text);
};

#endif /* GLUT_H_ */
