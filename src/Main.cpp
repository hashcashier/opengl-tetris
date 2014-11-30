//============================================================================
// Name        : Graphics.cpp
// Author      : Rami Khalil
// Version     :
// Copyright   : Don't steal my code
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>
#include "../inc/Game/GameManager.h"
#include "../inc/gl/GLUT.h"
#include "../inc/gl/GL.h"

using namespace std;

int main(int argc, char** argr)
{
	GLUT::initWindow("Tetris", 1280, 720, &argc, argr);

	GameManager mainGameManager{};

	GLUT::bindToGame(&mainGameManager);

//	GL::setBackgroundColor(0.0, 1.0, 1.0, 0.0);
	GL::setPointSize(1.0f);
	GL::setLinewidth(1.0);
	GL::set2DView(0.0, 1280.0, 0.0, 720.0);

	GLUT::mainLoop();

	return 0;
}
