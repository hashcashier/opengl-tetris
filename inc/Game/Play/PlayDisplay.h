/*
 * PlayDisplay.h
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */

#ifndef PLAYDISPLAY_H_
#define PLAYDISPLAY_H_
#include <bits/stdc++.h>
#include "../../gl/GL.h"
#include "../../gl/GLUT.h"
#include "../GameManager.h"

using namespace std;

class PlayDisplay {
public:
	static void display(GameManager*);
	static void displayShapes(GameManager*);
};


#endif /* PLAYDISPLAY_H_ */
