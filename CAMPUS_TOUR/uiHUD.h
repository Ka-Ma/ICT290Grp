	/**
	@brief HUD elements
	@author Katherine Mann, except where noted
	@version 01
	@date 13/10/2016
	*/

#ifndef UIHUD_H
#define UIHUD_H

#include "globalVariable.h"

void displayUIHUD();

	/**
	@brief Function operation of keys in this setting
	@param key - the key that was pressed
	@param x - x position 
	@param y - y position 
	*/
void keysUIHUD(unsigned char key, int x, int y);

void mouseUIOptions(int button, int state, int x, int y);

#endif // UIHUD_H
