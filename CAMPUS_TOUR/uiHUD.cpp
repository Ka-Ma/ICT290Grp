#include "uiHUD.h"



void displayUIHUD(int screenWidth, int screenHeight)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, screenWidth, 0, screenHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// display image
	// this will be the corners with the menu, timer, ball stats, player/score stats
	/*glBindTexture(GL_TEXTURE_2D, tempImage); 
	glBegin(GL_QUADS);
		glTexCoord2f(flipX, 0.0);
		glVertex3f(xStart, yStart, zStart);
		glTexCoord2f(flipX, yTimes);
		glVertex3f(xStart, yStart + (yImgSize * yTimes), zStart);
		glTexCoord2f(tempX, yTimes);
		glVertex3f(xStart + (xImgSize * xTimes), yStart + (yImgSize * yTimes), zStart);
		glTexCoord2f(tempX, 0.0);
		glVertex3f(xStart + (xImgSize * xTimes), yStart, zStart);
	glEnd();*/
	
	glDisable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, 0); //sets active to none
	glColor3f(0.498f, 1.0f, 0.0f); 
	glRasterPos2i(120, 120);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"HUD GREEN FOR THE WIN!!!");
	glEnable(GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
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

