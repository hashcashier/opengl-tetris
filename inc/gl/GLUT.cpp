/*
 * GLUT.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#include "GLUT.h"
#include "../Game/GameManager.h"
#include "../Game/DisplayManager.h"
#include "../Game/KeyboardManager.h"
#include "../Game/MouseManager.h"
#include "GL.h"

DisplayManager* GLUT::displayManager;
KeyboardManager* GLUT::keyboardManager;
MouseManager* GLUT::mouseManager;
bool GLUT::pendingRedisplay = false;

int glutWindowWidth = 0, glutWindowHeight = 0;

void reshapeWindow(int width, int height) {
	double ratW = width/(double)glutWindowWidth, ratH = height/(double)glutWindowHeight;
//	double rat = min(ratW, ratH);
//	GL::scale(rat, rat, 1.0);
	GL::scale(ratW, ratH, 1.0);
	cerr << "New resolution: " << glutWindowWidth << ' ' << glutWindowHeight << ' ' << width << ' ' << height << endl;
	cerr << "Scale factors: " << ratW << ' ' << ratH << endl;
	glutWindowWidth = width;
	glutWindowHeight = height;
}

void displayFunction() {
	GLUT::displayManager->display();
}

void keyboardFunction(unsigned char c, int x, int y) {
	GLUT::keyboardManager->respondToStroke(c, x, y);
}

void specialFunction(int key, int x, int y) {
	GLUT::keyboardManager->respondToKey(key, x, y);
}

void mouseFunction(int button, int state, int x, int y) {
	GLUT::mouseManager->respondToClick(button, state, x, y);
}

void idleFunc() {
//	GLUT::redisplay();
//	glutIdleFunc(NULL);
	static int ctr = 0;
	ctr ++;
	if(GLUT::pendingRedisplay) {
		cout << "Redisplay after: " << ctr << endl;
		ctr = 0;
		GLUT::pendingRedisplay = false;
		GLUT::redisplay();
	} else {
		this_thread::sleep_for(chrono::milliseconds(10));
//		glutIdleFunc(NULL);
	}
}

void GLUT::initWindow(const char *title, int width, int height, int* pargc, char** argv) {
	glutInit(pargc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutWindowWidth = width;
	glutWindowHeight = height;
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0,0);
	glutCreateWindow(title);
	glutReshapeFunc(reshapeWindow);
	glutFullScreen();
}

void GLUT::bindToGame(GameManager* gm) {
	GLUT::displayManager = gm->getDisplayManager();
	GLUT::keyboardManager = gm->getKeyboardManager();
	GLUT::mouseManager = gm->getMouseManager();

	glutDisplayFunc(displayFunction);
	glutKeyboardFunc(keyboardFunction);
	glutSpecialFunc(specialFunction);
	glutMouseFunc(mouseFunction);
	glutIdleFunc(idleFunc);
}

void GLUT::redisplay() {
	glutPostRedisplay();
}

void GLUT::mainLoop() {
	glutMainLoop();
}

void GLUT::printText(int x, int y, string text) {
	GL::setRasterPosition(x, y);
	for(int i = 0; i < (int) text.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}
