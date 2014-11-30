/*
 * MenuDisplay.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */

#include "MenuDisplay.h"

void MenuDisplay::display(GameManager *gameManager) {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glColor3f(1.0f,0.0f,0.0f);

	glBegin(GL_QUADS);
	glVertex2i(40, 40);
	glVertex2i(70, 40);
	glVertex2i(70, 190);
	glVertex2i(40, 190);


	glVertex2i(10, 190);
	glVertex2i(100, 190);
	glVertex2i(100, 230);
	glVertex2i(10, 230);

	glColor3f(1.0f,1.0f,0.0f);

	glVertex2i(70, 40);
	glVertex2i(90, 40);
	glVertex2i(90, 190);
	glVertex2i(70, 190);

	glVertex2i(90, 160);
	glVertex2i(120, 160);
	glVertex2i(120, 190);
	glVertex2i(90, 190);

	glVertex2i(90, 100);
	glVertex2i(120, 100);
	glVertex2i(120, 130);
	glVertex2i(90, 130);

	glVertex2i(90, 40);
	glVertex2i(120, 40);
	glVertex2i(120, 70);
	glVertex2i(90, 70);

	glColor3f(0.0f,1.0f,0.0f);

	glVertex2i(120, 70);
	glVertex2i(140, 70);
	glVertex2i(140, 190);
	glVertex2i(120, 190);

	glVertex2i(100, 130);
	glVertex2i(160, 130);
	glVertex2i(160, 160);
	glVertex2i(100, 160);

	glVertex2i(120, 70);
	glVertex2i(160, 70);
	glVertex2i(160, 100);
	glVertex2i(120, 100);

	glColor3f(0.0f,0.0f,1.0f);

	glVertex2i(145, 100);
	glVertex2i(180, 100);
	glVertex2i(180, 130);
	glVertex2i(145, 130);

	glVertex2i(160, 60);
	glVertex2i(180, 60);
	glVertex2i(180, 145);
	glVertex2i(160, 145);

	glColor3f(0.0f, 1.0f,1.0f);

	glVertex2i(180, 40);
	glVertex2i(200, 40);
	glVertex2i(200, 105);
	glVertex2i(180, 105);

	glVertex2i(180, 125);
	glVertex2i(200, 125);
	glVertex2i(200, 150);
	glVertex2i(180, 150);

	glColor3f(1.0f, 0.0f, 1.0f);

	glVertex2i(200, 40);
	glVertex2i(220, 40);
	glVertex2i(220, 60);
	glVertex2i(200, 60);

	glVertex2i(210, 60);
	glVertex2i(230, 60);
	glVertex2i(230, 80);
	glVertex2i(210, 80);

	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	GLUT::printText(250, 150, "PRESS S TO START!");

	glPopMatrix();
	glFlush();
}


