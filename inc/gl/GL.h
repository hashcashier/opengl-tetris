/*
 * GL.h
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */

#ifndef GL_H_
#define GL_H_
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>
using namespace std;

class GL {
public:
	static void setBackgroundColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	static void setLinewidth(GLfloat width);
	static void setPointSize(GLfloat size);
	static void set2DView(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top);
	static void scale(GLdouble x, GLdouble y, GLdouble z);
	static void setRasterPosition(GLfloat x, GLfloat y);
	static void setColorf(GLfloat red, GLfloat green, GLfloat blue);
};

#endif /* GL_H_ */
