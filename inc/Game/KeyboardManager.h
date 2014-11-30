/*
 * KeyboardManager.h
 *
 *  Created on: Oct 3, 2014
 *      Author: rami
 */

#ifndef KEYBOARDMANAGER_H_
#define KEYBOARDMANAGER_H_
#include <bits/stdc++.h>
using namespace std;

class GameManager;

class KeyboardManager {
private:
	GameManager *gameManager;
public:
	KeyboardManager(GameManager*);
	void respondToStroke(unsigned char key, int x, int y);
	void respondToKey(int key, int x, int y);
};




#endif /* KEYBOARDMANAGER_H_ */
