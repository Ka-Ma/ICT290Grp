	/**
	@brief LeaderBoard elements
	@author Katherine Mann
	@version 01
	@date 18/10/2016
	*/

#ifndef UILEADERBOARD_H
#define UILEADERBOARD_H

//troubleshooting
#include <iostream>

#include "globalVariable.h"
#include "gl/freeglut.h"  //for glutBitmapString()
#include "gl/glut.h"
#include "EasySound.h"

	/**
	@brief display the elements of the LeaderBoard
	@param w - width of the screen
	@param h - height of the screen
	@param tempImage - pointer to UI image passed in
	*/
void displayUILeaderBoard(int w, int h, const GLuint & tempImage);

	/**
	@brief Function operation of mouse in this setting
	@param button - the button that was pressed
	@param state
	@param x - x position
	@param y - y position
	*/
void mouseUILeaderBoard(int button, int state, int x, int y);

#endif // UILEADERBOARD_H
