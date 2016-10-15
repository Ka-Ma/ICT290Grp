	/**
	@brief Menu elements
	@author Katherine Mann, except where noted
	@version 01
	@date 15/10/2016
	*/

#ifndef UIMENU_H
#define UIMENU_H

#include "globalVariable.h"
#include "gl/freeglut.h"  //for glutBitmapString()
#include "gl/glut.h"


	/**
	@brief Displays visual elements of this UI
	@param screenWidth
	@param screenHeight 
	@param tempImage - passing in pointer for image to be used
	*/
void displayUIMenu(int screenWidth, int screenHeight, const GLuint & tempImage);

	/**
	@brief Function operation of keys in this setting
	@param key - the key that was pressed
	@param x - x position 
	@param y - y position 
	*/
void keysUIMenu(unsigned char key, int x, int y);

	/**
	@brief Function operation of mouse in this setting
	@param button - the button that was pressed
	@param state
	@param x - x position
	@param y - y position
	*/
void mouseUIMenu(int button, int state, int x, int y);

#endif // UIMENU_H
