/*
 * PlayAnimator.h
 *
 *  Created on: Oct 15, 2014
 *      Author: rami
 */

#ifndef PLAYANIMATOR_H_
#define PLAYANIMATOR_H_
#include <bits/stdc++.h>
#include "../../gl/GL.h"
#include "../../gl/GLUT.h"
#include "../GameManager.h"
#include "../../Shapes/Tetromino.h"
#include "../../Shapes/TetrominoGenerator.h"
#include "PlayActions.h"

using namespace std;

typedef chrono::time_point<chrono::system_clock> timestamp;
typedef chrono::duration<double> duration;

class GameManager;
template<typename T>
class Tetromino;


class PlayAnimator {
public:
	static void animate(GameManager *gameManager);
};



#endif /* PLAYANIMATOR_H_ */
