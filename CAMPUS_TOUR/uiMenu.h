	/**
	@brief Menu elements
	@author Katherine Mann, except where noted
	@version 01
	@date 15/10/2016
	@version 02 - convert to class - KJM
	@date 19/10/2016
	*/

#ifndef UIMENU_H
#define UIMENU_H

//for troubleshooting
#include <iostream>

#include "globalVariable.h"
#include "gl/freeglut.h"  //for glutBitmapString()
#include "gl/glut.h"
#include "EasySound.h"

class uiMenu {
public:
	uiMenu(int w, int h);

	/**
	@brief update the members of the menu to new screen size
	@param w - width of the screen
	@param h - height of the screen
	*/
	void updateUIMenuMembers(int w, int h);

	/**
	@brief Displays visual elements of this UI
	@param tempImage - passing in pointer for image to be used
	*/
	void displayUIMenu(const GLuint & tempImage);

	/**
	@brief Function operation of mouse in this setting
	@param button - the button that was pressed
	@param state
	@param x - x position
	@param y - y position
	*/
	void mouseUIMenu(int button, int state, int x, int y);

private:
	int width; //screen width
	int height; //screen height
};

	

#endif // UIMENU_H
