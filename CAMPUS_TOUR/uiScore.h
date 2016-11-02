	/**
	@brief Score elements
	@author Katherine Mann
	@version 01
	@date 2/11/2016
	*/

#ifndef UISCORE_H
#define UISCORE_H

//for troubleshooting
#include <iostream>

#include "globalVariable.h"
#include "gl/freeglut.h"  //for glutBitmapString()
#include "gl/glut.h"
#include "EasySound.h"
#include <string>

using namespace std;

class uiScore {
public:
	uiScore(int w, int h);

	/**
	@brief update the members of the options to new screen size
	@param w - width of the screen
	@param h - height of the screen
	*/
	void updateUIScoreMembers(int w, int h);

	/**
	@brief Displays visual elements of this UI
	@param tempImage - passing in pointer for image to be used
	*/
	void displayUIScore(const GLuint & tempImage, int score);

	/**
	@brief Function operation of mouse in this setting
	@param button - the button that was pressed
	@param state
	@param x - x position
	@param y - y position
	*/
	void mouseUIScore(int button, int state, int x, int y);

	/**
	@brief sets string of intials for this score from ints
	*/
	void setInitials(int arr[]);

	/**
	@brief returns string of intials for this score
	*/
	string getInitials();


private:
	int width;  //screen width
	int height; //screen height
	int arr[3]; //letter of alphabet for initials
	string initials;

	/**
	@brief returns string of converstion from int to alpha
	*/
	string alphaFromInt(int letter);
};

	

#endif // UISCORE_H
