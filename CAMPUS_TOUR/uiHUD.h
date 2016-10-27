	/**
	@brief HUD elements
	@author Katherine Mann, except where noted
	@version 01
	@date 13/10/2016
	@version 02 - updated to class KJM
	@date 19/10/2016
	@version 03 - MT::update with dynamic tracking of ui elements
	@date 25/10/2016
	*/

#ifndef UIHUD_H
#define UIHUD_H

#include "globalVariable.h"
#include "gl/freeglut.h"  //for glutBitmapString()
#include "gl/glut.h"
#include "EasySound.h"
#include <time.h>
#include <string>

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
	
	/**
	@brief Setter for setting the current ball count ingame
	@param ball - ball count
	*/
	void setBallCount(int ball);
	int getBallCount();
	float getTimeCount();
	int genScore();
	int getDist();

	void setClock(clock_t nclock);
	void setScore(int score);
	void setDist(int dist);

private:
	char buffer[30]; //buffer for string conversion MT
	int width; //screen width
	int height; //screen height
	int cball = 0; //current ball count MT
	clock_t start = clock(); //starting clock
	int curScore =0; //current score
	int distance; //distance from planets
};

	

#endif // UIHUD_H
