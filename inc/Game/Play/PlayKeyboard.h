/*
 * MenuKeyboard.h
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */

#ifndef PLAYKEYBOARD_H_
#define PLAYKEYBOARD_H_
#include <bits/stdc++.h>
#include "../GameManager.h"
#include "PlayActions.h"

class PlayKeyboard {
public:
	static void respondToStroke(unsigned char key, int x, int y, GameManager*);
	static void respondToKey(int key, int x, int y, GameManager*);
};



#endif /* PLAYKEYBOARD_H_ */
