#include "uiMenu.h"



void displayUIMenu(int w, int h, const GLuint & tempImage)
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
	glDisable(GL_DEPTH_TEST|GL_LIGHTING); 
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

	glEnable(GL_DEPTH_TEST|GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void mouseUIMenu(int button, int state, int x, int y)
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
	int btnW = 190 / 2; // width of button, halved for calcs
	//fyi: button is 20px high and there is 60px between buttons
	
	//when click in pixel area of menu option make click sound and do expected action
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//will need to height-y to convert coords to match screen and mouse together
		
		std::cout << "x " << x << ", y " << y << std::endl;
		//if coord range equals 
		//restart: reset all variables to beginning state and uiMenu = false
		if (x >= wc - btnW && x <= wc+btnW && y >= 400 && y <= 425)
		{
			clickSound->Play();
			
			//reset game to starting variables
			//timer = max
			//planetsHit = 0
			//player position = start
			//balls = start

			//restarts animation
			//restarts timer

			//returns to game
			gVar.uiMenu = false;
		}
		//resume: uiMenu = false, restarts animation and timer
		if (x >= wc - btnW && x <= wc + btnW && y >= 478 && y <= 498)
		{
			clickSound->Play();
			//restart animation
			//restart timer

			//returns to game
			gVar.uiMenu = false;
		}
		//options: uiOptions = true
		if (x >= wc - btnW && x <= wc + btnW && y >= 557 && y <= 577)
		{
			clickSound->Play();
			gVar.uiOptions = true;
			gVar.uiMenu = false;
		}
		//leaderboard: uiLeaderboard = true
		if (x >= wc - btnW && x <= wc + btnW && y >= 635 && y <= 655)
		{
			clickSound->Play();
			gVar.uiLeaderBoard = true;
			gVar.uiMenu = false;
		}
		//exit: displayExit = true
		if (x >= wc - btnW && x <= wc + btnW && y >= 714 && y <= 734)
		{
			clickSound->Play();
			gVar.DisplayExit = true;
			gVar.uiMenu = false;
		}

	}
}

