	/**
	@brief Menu elements
	@author Katherine Mann, except where noted
	@version 01
	@date 15/10/2016
	*/

#ifndef UIMENU_H
#define UIMENU_H

//for troubleshooting
#include <iostream>

#include "globalVariable.h"
#include "gl/freeglut.h"  //for glutBitmapString()
#include "gl/glut.h"
#include "EasySound.h"


	/**
	@brief Displays visual elements of this UI
	@param w - width of screen
	@param h - height of screen 
	@param tempImage - passing in pointer for image to be used
	*/
void displayUIMenu(int w, int h, const GLuint & tempImage);

	/**
	@brief Function operation of mouse in this setting
	@param button - the button that was pressed
	@param state
	@param x - x position
	@param y - y position
	*/
void mouseUIMenu(int button, int state, int x, int y);

#endif // UIMENU_H