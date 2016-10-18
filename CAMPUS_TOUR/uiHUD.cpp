#include "uiHUD.h"



void displayUIHUD(int w, int h, const GLuint & tempImage)
{
	int d = 200; //width and height of hud arc
	
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//gl depth test disabled so hud draws correctly
	glDisable(GL_DEPTH_TEST|GL_LIGHTING); // disable depth test for 2d, lighting for text
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D); //need for tempImage

	// display images: quad is counterclockwise starting top left, texture coords are top left = 0,0
	// this will be the corners with the menu, timer, ball stats, player/score stats
	// BALL STATS
	glBindTexture(GL_TEXTURE_2D, tempImage); 
	glBegin(GL_QUADS);
		glTexCoord2f(0.5, 0.0);
		glVertex2f(0, d);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(0, 0);
		glTexCoord2f(1.0, 0.5);
		glVertex2f(d, 0);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(d, d);
	glEnd();

	//TIMER
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.5);
		glVertex2f(w-d, h);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(w-d, h-d);
		glTexCoord2f(0.5, 1.0);
		glVertex2f(w, h-d);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(w, h);
	glEnd();

	//MENU
	glBegin(GL_QUADS);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(0, h);
		glTexCoord2f(0.5, 1.0);
		glVertex2f(0, h - d);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(d, h-d);
		glTexCoord2f(1.0, 0.5);
		glVertex2f(d, h);
	glEnd();

	//PLAYER/SCORE STATS 
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(w - d, d);
		glTexCoord2f(0.0, 0.5);
		glVertex2f(w-d, 0);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(w, 0);
		glTexCoord2f(0.5, 0.0);
		glVertex2f(w, d);
	glEnd();
	
	//data will need to be converted to string in order to put on screen
	glBindTexture(GL_TEXTURE_2D, 0); //sets active to none
	glColor3f(0.498f, 1.0f, 0.0f);
	glRasterPos2i(30, 10);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"1");  //replace with ballsInPlay variable to string
	glRasterPos2i(w-110, h-20);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"1000");  //replace with timer variable to string
	glRasterPos2i(w-150, 10);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"51200");  // replace with distFromGoal variable to string & planetsHit variable to string

	glEnable(GL_DEPTH_TEST|GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	
}

void mouseUIHUD(int button, int state, int x, int y)
{
	//KM 15/10/2016 click noise - sourced from http://soundbible.com/1705-Click2.html
	CEasySound *es;
	CSound* clickSound;
	es = CEasySound::Instance();
	clickSound = es->GetSound(es->Load("sounds/Click2-Sebastian-759472264.wav"));

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if (x <= 200 && x >= 0 && y <= 200 && y >= 0) 
		{
			clickSound->Play();
			gVar.uiMenu = true;
			//pause timer & animation
		}
		/*else if ((gVar.DisplayExit) && (x <= width / 2.0 + 256.0) && (x >= width / 2.0 - 256.0)
			&& (y <= height / 2.0 + 256.0) && (y >= height / 2.0 - 256.0))
		{
			DeleteImageFromMemory(image);
			exit(1);
		}*/
	}
}

