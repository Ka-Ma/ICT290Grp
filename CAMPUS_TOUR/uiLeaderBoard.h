	/**
	@brief LeaderBoard elements
	@author Katherine Mann
	@version 01
	@date 18/10/2016
	@version 02
	@date 25/10/2016 - added function to add to vector
	*/

#ifndef UILEADERBOARD_H
#define UILEADERBOARD_H

//troubleshooting
#include <iostream>

//leaderboard file
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#include "globalVariable.h"
#include "gl/freeglut.h"  //for glutBitmapString()
#include "gl/glut.h"
#include "EasySound.h"

class uiLeaderBoard {
public:
	uiLeaderBoard(int w, int h);

	/**
	@brief update the members of the LeaderBoard to new screen size
	@param w - width of the screen
	@param h - height of the screen
	*/
	void updateUILeaderBoardMembers(int w, int h);

	/**
	@brief display the elements of the LeaderBoard
	@param tempImage - pointer to UI image passed in
	*/
	void displayUILeaderBoard(const GLuint & tempImage);

	/**
	@brief Function operation of mouse in this setting
	@param button - the button that was pressed
	@param state
	@param x - x position
	@param y - y position
	*/
	void mouseUILeaderBoard(int button, int state, int x, int y);

	/**
	@brief populate leaderboard vector from leaderboard text file
	*/
	void getLeaderBoard();

	/**
	@brief rewrite LeaderBoard.txt
	*/
	void setLeaderBoard();

	/**
	@brief add score to leaderboard vector
	@param newName - three characters (initials)
	@param newDate - dd/mm/yyyy
	@param newScore - as calculated
	*/
	void addLeaderBoard(std::string newName, std::string newDate, int newScore);

private:
	int width; //screen width
	int height; //screen height
	struct score 
	{ 
		std::string name; 
		std::string sDate; 
		int nScore; 
	};
	std::vector<score> lboard;

	/**
	@brief sort scores in leaderboard vector, largest score first
	*/
	void sortLeaderBoard();
};

	

#endif // UILEADERBOARD_H
