#include "uiKeysHandler.h"

bool uiKeysHandler(unsigned char key, int x, int y)
{
    
	if(gVar.uiMenu) 
	{
		std::cout << "Menu has control of keys" << std::endl;
		keysUIMenu(key, x, y);
		return true;
	}
	else if (gVar.uiHUD)
	{
		std::cout << "HUD has control of keys" << std::endl;
		keysUIHUD(key, x, y);
		return true;
	}
	else
        return false;
}
