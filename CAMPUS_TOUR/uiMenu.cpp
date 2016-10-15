#include "uiMenu.h"



void displayUIMenu(int screenWidth, int screenHeight, const GLuint & tempImage)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//gl depth test disabled so hud draws correctly
	glDisable(GL_DEPTH_TEST); 
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D); //need for tempImage

	// display menu image at screen centre
	glBindTexture(GL_TEXTURE_2D, tempImage); 
	glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex2f(screenWidth / 2 - 300, screenHeight / 2 - 300);
		glTexCoord2f(0, 0);
		glVertex2f(screenWidth/2-300, screenHeight/2+300);
		glTexCoord2f(1, 0);
		glVertex2f(screenWidth/2+300, screenHeight / 2 + 300);
		glTexCoord2f(1, 1);
		glVertex2f(screenWidth / 2 + 300, screenHeight / 2 - 300);
	glEnd();

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void keysUIMenu(unsigned char key, int x, int y)
{
	switch (key)
    {
    case 'm': 
	case 'M':
		gVar.uiMenu = false;
        break;
    case 27: //quit
		gVar.uiMenu = false;
        gVar.DisplayExit = true;
        break;
    }
}

void mouseUIMenu(int button, int state, int x, int y)
{
	//KM 15/10/2016 click noise - sourced from http://soundbible.com/1705-Click2.html
	CEasySound *es;
	CSound* clickSound;
	es = CEasySound::Instance();
	clickSound = es->GetSound(es->Load("sounds/Click2-Sebastian-759472264.wav"));



	//when click in pixel area of menu option make click sound and do expected action
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//will need to height-y to convert coords to match screen and mouse together
		clickSound->Play();
		//if coord range equals 
		//restart: reset all variables to beginning state and uiMenu = false
		//resume: uiMenu = false
		//options: uiOptions = true
		//leaderboard: uiLeaderboard = true
		//exit: displayExit = true
	}
}

