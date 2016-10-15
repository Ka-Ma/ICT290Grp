#include "uiHUD.h"



void displayUIHUD(int screenWidth, int screenHeight, const GLuint & tempImage)
{
	int d = 200; //width and height of hud arc
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
	glDisable(GL_LIGHTING);  //need to disable for text to render properly
	glEnable(GL_TEXTURE_2D); //need for tempImage

	// display images
	// this will be the corners with the menu, timer, ball stats, player/score stats
	// BALL STATS
	glBindTexture(GL_TEXTURE_2D, tempImage); 
	glBegin(GL_QUADS);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(0, 0);
		glTexCoord2f(0.5, 1);
		glVertex2f(0, 170);
		glTexCoord2f(1, 1);
		glVertex2f(170, 170);
		glTexCoord2f(1, 0.5);
		glVertex2f(170, 0);
	glEnd();

	//TIMER
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(screenWidth-d, screenHeight-d);
		glTexCoord2f(0.0, 0.5);
		glVertex2f(screenWidth-d, screenHeight);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(screenWidth, screenHeight);
		glTexCoord2f(0.5, 0.0);
		glVertex2f(screenWidth, screenHeight-d);
	glEnd();

	//MENU
	glBegin(GL_QUADS);
		glTexCoord2f(0.5, 0.0);
		glVertex2f(0, screenHeight - d);
		glTexCoord2f(1, 0.0);
		glVertex2f(d, screenHeight - d);
		glTexCoord2f(1, .5);
		glVertex2f(d, screenHeight);
		glTexCoord2f(.50, 0.5);
		glVertex2f(0, screenHeight);
	glEnd();

	//PLAYER/SCORE STATS 
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0.5);
		glVertex2f(screenWidth - d, 0);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(screenWidth, 0);
		glTexCoord2f(0.5, 1);
		glVertex2f(screenWidth, d);
		glTexCoord2f(0, 1);
		glVertex2f(screenWidth - d, d);
	glEnd();
	
	//need to add this texts to image so it doesn't cause problems when it exceeds the window size
	//data will need to be converted to string in order to put on screen
	glBindTexture(GL_TEXTURE_2D, 0); //sets active to none
	glColor3f(0.498f, 1.0f, 0.0f);
	glRasterPos2i(10, 10);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)"Balls In Play / Available");  
	glRasterPos2i(screenWidth-110, screenHeight-20);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)"Timer");
	glRasterPos2i(10, screenHeight - 20);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"Menu");
	glRasterPos2i(screenWidth-150, 10);
	glutBitmapString(GLUT_BITMAP_HELVETICA_10, (const unsigned char*)"Dist from Goal / Planets Hit");
	glEnable(GL_LIGHTING);


	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
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

