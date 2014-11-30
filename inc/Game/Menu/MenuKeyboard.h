/*
 * MenuKeyboard.h
 *
 *  Created on: Oct 4, 2014
 *      Author: rami
 */

#ifndef MENUKEYBOARD_H_
#define MENUKEYBOARD_H_
#include <bits/stdc++.h>
#include "../GameManager.h"

class MenuKeyboard {
public:
	static void respondToStroke(unsigned char key, int x, int y, GameManager*);
};



#endif /* MENUKEYBOARD_H_ */
