/**
@brief Evaluates situation, if particular UI is displayed passes click & coords to that UI and returns true.
@author Katherine Mann
@version 01
@date 18/10/2016
*/

#ifndef UIMOUSEHANDLER_H
#define UIMOUSEHANDLER_H

//for troubleshooting
#include <iostream>

#include "globalVariable.h"
#include "uiHUD.h"
#include "uiMenu.h"
#include "uiOptions.h"
#include "uiLeaderBoard.h"

bool uiMouseHandler(int button, int state, int x, int y);

#endif //UIMOUSEHANDLER_H
