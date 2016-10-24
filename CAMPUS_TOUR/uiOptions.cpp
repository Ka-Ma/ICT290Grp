#include "uiOptions.h"

uiOptions::uiOptions(int w, int h)
{
	updateUIOptionsMembers(w, h);
}

void uiOptions::updateUIOptionsMembers(int w, int h)
{
	width = w;
	height = h;
}

void uiOptions::displayUIOptions(const GLuint & tempImage)
{
	//finding centre of screen
	int wc = width / 2; 
	int hc = height / 2;
	int d = 300; // half of width and height of UI screen

	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
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
	glRasterPos2i(wc + 27, hc - 5);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)"9"); // need to replace with numPlanets
	glRasterPos2i(wc + 27, hc - 79);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)"15"); // need to replace with numProj
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void uiOptions::mouseUIOptions(int button, int state, int x, int y)
{
	//KM 15/10/2016 click noise - sourced from http://soundbible.com/1705-Click2.html
	CEasySound *es;
	CSound* clickSound;
	es = CEasySound::Instance();
	clickSound = es->GetSound(es->Load("sounds/Click2-Sebastian-759472264.wav"));

	//temp vars that may need to be in gVar or similar
	//screen height and width centres
	int hc = height /2;
	int wc = width/2;
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
		if (x >= wc+20 && x <= wc+47 && y >= hc-29 && y <= hc-13)
		{
			clickSound->Play();
			if (numPlanets != maxPlanets) {
				numPlanets++;
			}
		}
		//decrease planet number
		if (x >= wc + 20 && x <= wc+47 && y >= hc+5 && y <= hc+19)
		{
			clickSound->Play();
			if (numPlanets != minPlanets) {
				numPlanets--;
			}
		}
		//increase projectiles
		if (x >= wc+18 && x <= wc+47 && y >= hc+49 && y <= hc+65)
		{
			clickSound->Play();
			if (numProj != maxProj) {
				numProj++;
			}
		}
		//decreate projectiles
		if (x >= wc+19 && x <= wc+47 && y >= hc+84 && y <= hc+97)
		{
			clickSound->Play();
			if (numProj != minProj) {
				numProj--;
			}
		}
		//return to game
		if (x >= wc+140 && x <= wc+236 && y >= hc+214 && y <= hc+235)
		{
			clickSound->Play();
			gVar.uiOptions = false;
			// reset and start timer, 
			// reset all other game variables 
			// restart animation
		}
	}
}

