/**
@brief Evaluates situation, if particular UI is displayed passes keystroke to that UI and returns true.
@author Katherine Mann
@version 01
@date 13/10/2016
*/

#ifndef UIKEYSHANDLER_H
#define UIKEYSHANDLER_H

#include "globalVariable.h"
//include uiHeaders.h
#include "uiHUD.h"
#include "uiMenu.h"

bool uiKeysHandler(unsigned char key, int x, int y);

#endif //UIKEYSHANDLER_H
