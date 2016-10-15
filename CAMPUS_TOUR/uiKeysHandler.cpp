#include "uiKeysHandler.h"

bool uiKeysHandler(unsigned char key, int x, int y)
{
    if(gVar.uiHUD)
    {
        keysUIHUD(key, x, y);
        return true;
    }
    else if(gVar.uiMenu) 
	{
		keysUIMenu(key, x, y);
		return true;
	}
	else
        return false;
}
