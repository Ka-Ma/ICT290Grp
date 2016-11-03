	/**
	@brief HUD elements
	@author Katherine Mann, except where noted
	@version 01
	@date 13/10/2016
	@version 02 - updated to class KJM
	@date 19/10/2016
	@version 03 - MT::update with dynamic tracking of ui elements
	@date 25/10/2016
	@version 04 - KJM added instruction screen
	@date 2/11/2016
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
	@param tempImage - pointer to UI image passed in
	*/
	void displayUIHUD(const GLuint & tempImage);

	/**
	@brief display the instruction Screent
	@param tempImage - pointer to UI image passed in
	*/
	void displayInstruct(const GLuint & tempImage);

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
	/**
	@brief Getter to get how many balls are in play
	@return cball
	*/
	int getBallCount();
	/**
	@brief Getter to calculate the time
	@return time
	*/
	float getTimeCount();
	/**
	@brief function to generate the score
	@return score
	*/
	int genScore();
	/**
	@brief function to calculate the distance between cam and goal
	@return distance
	*/
	int getDist();
	/**
	@brief getter to find how many balls can be played
	@return current_balls
	*/
	int getTotalBallCount(); 
	/**
	@brief setter to generate how many balls are left
	*/
	void setTotalBallCount(int currentBalls);
	/**
	@brief function to check if the ball is hit a planet                                                                                                                                                               
	*/
	void hitPlanet();
	/**
	@brief function to reset clock                                                                                                                                                             
	*/
	void resetClock();
	/**
	@brief setter to set clock to nclock time                                                                                                                                                            
	*/
	void setClock(clock_t nclock);
	/**
	@brief setter to set the score                                                                                                                                                           
	*/
	void setScore(int score);
	/**
	@brief setter to set the distance                                                                                                                                                           
	*/
	void setDist(int dist);
	/**
	@brief getter to get the zeroCLOCK
	@return zeroClock                                                                                                                                                           
	*/
	bool getZeroClock();
	/**
	@brief setter to set the clock to false                                                                                                                                                           
	*/
	void setZeroClock(bool check);

private:
	char buffer[30]; //buffer for string conversion MT
	int width; //screen width
	int height; //screen height
	int cball = 0; //current ball count MT
	clock_t start = clock(); //starting clock
	int curScore =0; //current score
	int distance; //distance from planets
	int current_Balls;
	int hit_Planets = 0;
	bool zeroClock = true;
};

	

#endif // UIHUD_H
