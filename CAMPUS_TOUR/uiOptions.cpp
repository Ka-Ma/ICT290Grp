#include "uiOptions.h"



void displayUIOptions(int w, int h, const GLuint & tempImage)
{
	//finding centre of screen
	int wc = w / 2; 
	int hc = h / 2;
	int d = 300; // half of width and height of UI screen

	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//gl depth test disabled so hud draws correctly
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING); 
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D); //need for tempImage

	// display menu image at screen centre
	glBindTexture(GL_TEXTURE_2D, tempImage); 
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(wc - d, hc + d);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(wc - d, hc - d);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(wc + d, hc - d);
		glTexCoord2f(1.0, 0.0);
		glVertex2f(wc + d, hc + d);
	glEnd();

	//data will need to be converted to string in order to put on screen
	glBindTexture(GL_TEXTURE_2D, 0); //sets active to none
	glColor3f(0.498f, 1.0f, 0.0f);
	glRasterPos2i(527, 495);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"9"); // need to replace with numPlanets
	glRasterPos2i(527, 421);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"15"); // need to replace with numProj
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void mouseUIOptions(int button, int state, int x, int y)
{
	//KM 15/10/2016 click noise - sourced from http://soundbible.com/1705-Click2.html
	CEasySound *es;
	CSound* clickSound;
	es = CEasySound::Instance();
	clickSound = es->GetSound(es->Load("sounds/Click2-Sebastian-759472264.wav"));

	//temp vars that may need to be in gVar or similar
	//screen height and width centres
	int hc = 500;
	int wc = 500;
	int maxPlanets = 9;
	int numPlanets = 9;
	int minPlanets = 2;
	int maxProj = 1000;
	int minProj = 1;
	int numProj = 15;
	
	//when click in pixel area of menu option make click sound and do expected action
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//will need to height-y to convert coords to match screen and mouse together
		
		std::cout << "x " << x << ", y " << y << std::endl;
		//if coord range equals 
		//increase planet number
		if (x >= 520 && x <= 547 && y >= 471 && y <= 487)
		{
			clickSound->Play();
			if (numPlanets != maxPlanets) {
				numPlanets++;
			}
		}
		//decrease planet number
		if (x >= 520 && x <= 547 && y >= 505 && y <= 519)
		{
			clickSound->Play();
			if (numPlanets != minPlanets) {
				numPlanets--;
			}
		}
		//increase projectiles
		if (x >= 518 && x <= 547 && y >= 549 && y <= 565)
		{
			clickSound->Play();
			if (numProj != maxProj) {
				numProj++;
			}
		}
		//decreate projectiles
		if (x >= 519 && x <= 547 && y >= 584 && y <= 597)
		{
			clickSound->Play();
			if (numProj != minProj) {
				numProj--;
			}
		}
		//return to game
		if (x >= 640 && x <= 736 && y >= 714 && y <= 735)
		{
			clickSound->Play();
			gVar.uiOptions = false;
			// reset and start timer, 
			// reset all other game variables 
			// restart animation
		}
	}
}

