	/**
	@brief HUD elements
	@author Katherine Mann, except where noted
	@version 01
	@date 13/10/2016
	@version 02 - updated to class KJM
	@date 19/10/2016
	*/

#ifndef UIHUD_H
#define UIHUD_H

#include "globalVariable.h"
#include "gl/freeglut.h"  //for glutBitmapString()
#include "gl/glut.h"
#include "EasySound.h"

class uiHUD {
public:

	uiHUD(int w, int h);

	/**
	@brief update the members of the HUD to new screen size
	@param w - width of the screen
	@param h - height of the screen
	*/
	void updateUIHIDMembers(int w, int h);

	/**
	@brief display the elements of the HUD
	@param w - width of the screen
	@param h - height of the screen
	@param tempImage - pointer to UI image passed in
	*/
	void displayUIHUD(const GLuint & tempImage);

	/**
	@brief Function operation of mouse in this setting
	@param button - the button that was pressed
	@param state
	@param x - x position
	@param y - y position
	*/
	void mouseUIHUD(int button, int state, int x, int y);

private:
	int width; //screen width
	int height; //screen height
};

	

#endif // UIHUD_H
