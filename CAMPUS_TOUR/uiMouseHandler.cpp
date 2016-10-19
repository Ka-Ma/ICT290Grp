#include "uiMouseHandler.h"

bool uiMouseHandler(int button, int state, int x, int y, uiHUD & uih, uiMenu & uim, uiOptions & uio, uiLeaderBoard & uil)
{
    
	if(gVar.uiMenu) 
	{
		std::cout << "Menu has control of mouse" << std::endl;
		uim.mouseUIMenu(button, state, x, y);
		return true;
	}
	else if (gVar.uiOptions)
	{
		std::cout << "Options has control of mouse" << std::endl;
		uio.mouseUIOptions(button, state, x, y);
		return true;
	}
	else if (gVar.uiLeaderBoard) {
		std::cout << "LeaderBoard has control of mouse" << std::endl;
		uil.mouseUILeaderBoard(button, state, x, y);
		return true;
	}
	else if(gVar.uiHUD)
	{
		std::cout << "HUD has control of mouse" << std::endl;
		uih.mouseUIHUD(button, state, x, y);
		return true;
	}
	else
        return false;
}
