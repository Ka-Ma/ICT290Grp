#include "uiHUD.h"



void displayUIHUD()
{
    
}

void keysUIHUD(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'm': //menu
	case 'M':
        gVar.uiMenu = true;
        break;
    case 27: //quit
        gVar.DisplayExit = true;
        break;
    }
}

void mouseUIOptions(int button, int state, int x, int y)
{
    
}

