#include "uiMouseHandler.h"

bool uiMouseHandler(int button, int state, int x, int y)
{
    
	if(gVar.uiMenu) 
	{
		std::cout << "Menu has control of mouse" << std::endl;
		mouseUIMenu(button, state, x, y);
		return true;
	}
	else if (gVar.uiOptions)
	{
		std::cout << "Options has control of mouse" << std::endl;
		mouseUIOptions(button, state, x, y);
		return true;
	}
	else if (gVar.uiLeaderBoard) {
		std::cout << "LeaderBoard has control of mouse" << std::endl;
		mouseUILeaderBoard(button, state, x, y);
		return true;
	}
	else if(gVar.uiHUD)
	{
		std::cout << "HUD has control of mouse" << std::endl;
		mouseUIHUD(button, state, x, y);
		return true;
	}
	else
        return false;
}
