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

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
}

void mouseUIOptions(int button, int state, int x, int y)
{
	//KM 15/10/2016 click noise - sourced from http://soundbible.com/1705-Click2.html
	CEasySound *es;
	CSound* clickSound;
	es = CEasySound::Instance();
	clickSound = es->GetSound(es->Load("sounds/Click2-Sebastian-759472264.wav"));

	//temp vars that may need to be in gVar or sim
	//screen height and width centres
	int hc = 500;
	int wc = 500;
	int maxPlanets = 9;
	int numPlanets = 9;
	int minPlanets = 2;
	
	//when click in pixel area of menu option make click sound and do expected action
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//will need to height-y to convert coords to match screen and mouse together
		
		std::cout << "x " << x << ", y " << y << std::endl;
		//if coord range equals 
		//increase planet number
	/*	if (x >= wc - btnW && x <= wc+btnW && y >= 400 && y <= 425)
		{
			clickSound->Play();
			if (numPlanets != maxPlanets) {
				numPlanets++;
			}
		}
		//decrease planet number
		if (x >= wc - btnW && x <= wc + btnW && y >= 478 && y <= 498)
		{
			clickSound->Play();
			if (numPlanets != minPlanets) {
				numPlanets--;
			}
		}
		//increase projectiles
		if (x >= wc - btnW && x <= wc + btnW && y >= 557 && y <= 577)
		{
			clickSound->Play();
			if (numProj != maxProj) {
				numProj++;
			}
		}
		//decreate projectiles
		if (x >= wc - btnW && x <= wc + btnW && y >= 635 && y <= 655)
		{
			clickSound->Play();
			if (numProj != minProj) {
				numProj--;
			}
		}
		//return to game
		if (x >= wc - btnW && x <= wc + btnW && y >= 714 && y <= 734)
		{
			clickSound->Play();
			gVar.uiOptions = false;
			// reset and start timer, 
			// reset all other game variables 
			// restart animation
		}
*/
	}
}

