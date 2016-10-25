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

/**
@brief controls which ui has control of the mouse
@param button
@param state
@param x
@param y
@param uih - pointer to the hud object
@param uim - pointer to the menu object
@param uio - pointer to the options object
@param uil - pointer to the leaderboard object
*/
bool uiMouseHandler(int button, int state, int x, int y, uiHUD & uih, uiMenu & uim, uiOptions & uio, uiLeaderBoard & uil);

#endif //UIMOUSEHANDLER_H
