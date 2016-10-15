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
    case ' ': 
	    // thing
        break;
    case 27: //quit
		gVar.uiMenu = false;
        gVar.DisplayExit = true;
        break;
    }
}

void mouseUIMenu(int button, int state, int x, int y)
{
	//when click in pixel area of menu option make click sound and do expected action   
}

