/*
 * PlayDisplay.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */

#include "PlayDisplay.h"

void PlayDisplay::display(GameManager *gameManager) {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	GL::setColorf(1.0, 1.0, 1.0);
	if(gameManager->isPaused()) {
		GLUT::printText(900, 600, "PAUSED");
		GLUT::printText(900, 570, "Press R to resume.");
	} else {
		ostringstream oss;
		oss << gameManager->getScore();
		GLUT::printText(900, 600, "Score: " + oss.str());
		if(gameManager->isOver())
			GLUT::printText(900, 570, "Game Over. Press S to return to menu.");
		else
			GLUT::printText(900, 570, "Press P to pause.");

		displayShapes(gameManager);
	}

	GL::setColorf(1.0, 1.0, 1.0);
	glBegin(GL_LINES);

	for(int i = 0, x = 440; i < 11; i++, x += 40) {
		glVertex3i(x, 10, 1);
		glVertex3i(x, 650, 1);
	}

	for(int i = 0, y = 10; i < 16; i++, y += 40) {
		glVertex3i(440, y, 1);
		glVertex3i(840, y, 1);
	}

	glEnd();

	glPopMatrix();
	glFlush();
}

void PlayDisplay::displayShapes(GameManager *gameManager) {
	lock_guard<mutex> lk(*(gameManager->getMutex()));
	Tetromino<int> active = gameManager->getActiveTetromino();
	tetromat &tets = *(gameManager->getTetrominos());
//	cerr << "Display Shapes" << endl;

	glBegin(GL_QUADS);
	int n = tets.size(), m = tets[0].size();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(!tets[i][j].isBlank()) {
				Tetromino<int> &curr = tets[i][j];
				GL::setColorf(curr.red, curr.green, curr.blue);
				glVertex3i(440 + j*40, 650 - i * 40, 0);
				glVertex3i(440 + j*40, 650 - i * 40 - 40, 0);
				glVertex3i(440 + j*40 + 40, 650 - i * 40 - 40, 0);
				glVertex3i(440 + j*40 + 40, 650 - i * 40, 0);
			}
		}

	GL::setColorf(active.red, active.green, active.blue);
//	cout << "=======" << endl;
	for(int i = 0; i < active.points.size(); i++) {
		int col = active.col + active.points[i].real();
		int row = active.row + active.points[i].imag();
//		cout << row << ' ' << col << endl;
		glVertex3i(440 + col*40, 650 - row * 40, 0);
		glVertex3i(440 + col*40, 650 - row * 40 - 40, 0);
		glVertex3i(440 + col*40 + 40, 650 - row * 40 - 40, 0);
		glVertex3i(440 + col*40 + 40, 650 - row * 40, 0);
	}
//	cout << "=======" << endl;
	glEnd();
}
