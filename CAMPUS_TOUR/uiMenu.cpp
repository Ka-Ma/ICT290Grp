#include "uiMenu.h"

uiMenu::uiMenu(int w, int h)
{
	updateUIMenuMembers(w, h);
}

void uiMenu::updateUIMenuMembers(int w, int h)
{
	width = w;
	height = h;
}

void uiMenu::displayUIMenu(const GLuint & tempImage)
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

void uiMenu::mouseUIMenu(int button, int state, int x, int y)
{
	//KM 15/10/2016 click noise - sourced from http://soundbible.com/1705-Click2.html
	CEasySound *es;
	CSound* clickSound;
	es = CEasySound::Instance();
	clickSound = es->GetSound(es->Load("sounds/Click2-Sebastian-759472264.wav"));

	//screen height and width centres
	int hc = height/2;
	int wc = width/2;
	int btnW = 190 / 2; // width of button, halved for calcs
	//fyi: button is 20px high and there is 60px between buttons
	
	//when click in pixel area of menu option make click sound and do expected action
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//will need to height-y to convert coords to match screen and mouse together
		
		std::cout << "height " << height << ", width " << width << std::endl;
		std::cout << "x " << x << ", y " << y << std::endl;
		//if coord range equals 
		//restart: reset all variables to beginning state and uiMenu = false
		if (x >= wc - btnW && x <= wc+btnW && y >= hc-100 && y <= hc - 75)
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
		if (x >= wc - btnW && x <= wc + btnW && y >= hc - 22 && y <= hc - 2)
		{
			clickSound->Play();
			//restart animation
			//restart timer

			//returns to game
			gVar.uiMenu = false;
		}
		//options: uiOptions = true
		if (x >= wc - btnW && x <= wc + btnW && y >= hc +57 && y <= hc +77)
		{
			clickSound->Play();
			gVar.uiOptions = true;
			gVar.uiMenu = false;
		}
		//leaderboard: uiLeaderboard = true
		if (x >= wc - btnW && x <= wc + btnW && y >= hc +135 && y <= hc + 155)
		{
			clickSound->Play();
			gVar.uiLeaderBoard = true;
			gVar.uiMenu = false;
		}
		//exit: displayExit = true
		if (x >= wc - btnW && x <= wc + btnW && y >= hc + 214 && y <= hc + 234)
		{
			clickSound->Play();
			gVar.DisplayExit = true;
			gVar.uiMenu = false;
		}

	}
}

