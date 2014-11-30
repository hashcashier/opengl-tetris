/*
 * GL.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */

#include "GL.h"

void GL::setBackgroundColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	glClearColor(red, green, blue, alpha);
}

void GL::setLinewidth(GLfloat width) {
	glLineWidth(width);
}

void GL::setPointSize(GLfloat size) {
	glPointSize(size);
}

void GL::set2DView(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top) {
	gluOrtho2D(left, right, bottom, top);
}

void GL::scale(GLdouble x, GLdouble y, GLdouble z) {
	glScaled(x, y, z);
}

void GL::setRasterPosition(GLfloat x, GLfloat y) {
	glRasterPos2f(x, y);
}

void GL::setColorf(GLfloat red, GLfloat green, GLfloat blue) {
	glColor3f(red, green, blue);
}
