#include "globalVariable.h"

struct globalVariable gVar = {
	// setting defaults

	// display campus map
	false,
	// display welcome screen
	false,
	// display exit screen
	false,
	// display light fittings
	false,
	// display ECL block
	true,

	//game display states
	//uiHUD
	false,
	//uiMenu
	false,
	//uiOptions
	false,
	//uiLeaderboard
	false,
	//uiScore
	false,
	//uiInstruct
	false,
	//paused
	false,
	//LevelNum
	3,
	//Number of balls
	15,
	//end score
	0
};