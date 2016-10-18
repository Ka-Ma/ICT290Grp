	/**
	@brief Options elements
	@author Katherine Mann
	@version 01
	@date 18/10/2016
	*/

#ifndef UIOPTIONS_H
#define UIOPTIONS_H

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
void displayUIOptions(int w, int h, const GLuint & tempImage);

	/**
	@brief Function operation of mouse in this setting
	@param button - the button that was pressed
	@param state
	@param x - x position
	@param y - y position
	*/
void mouseUIOptions(int button, int state, int x, int y);

#endif // UIOPTIONS_H
