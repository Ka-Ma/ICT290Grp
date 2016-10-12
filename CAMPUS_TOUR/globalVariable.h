/**
@brief Global Variables for user interface
@author Katherine Mann
@version 01
@date 12/10/2016
*/

#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

typedef struct globalVariable {
	///transferred from Shays world
	// display campus map
	bool DisplayMap;
	// display welcome screen
	bool DisplayWelcome;
	// display exit screen
	bool DisplayExit;
	// display light fittings
	bool lightsOn;
	// display ECL block
	bool displayECL;
	
	///game display states
	bool uiHUD;
	bool uiMenu;
	bool uiOptions;
	bool uiLeaderBoard;
}globalVariable;

extern struct globalVariable gVar;

#endif
