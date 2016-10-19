#include "uiLeaderBoard.h"

uiLeaderBoard::uiLeaderBoard(int w, int h)
{
	updateUILeaderBoardMembers(w, h);
}

void uiLeaderBoard::updateUILeaderBoardMembers(int w, int h)
{
	width = w;
	height = h;
}

void uiLeaderBoard::displayUILeaderBoard(const GLuint & tempImage)
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
	//for (each entry in leaderboard vector)
	//glRasterPos2i(x, y+25);
	glRasterPos2i(wc - d+100, hc+d-200); 
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)"ABC   18/10/2016   512890"); // need to replace with details from leaderboard vector
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void uiLeaderBoard::mouseUILeaderBoard(int button, int state, int x, int y)
{
	int wc = width / 2;
	int hc = height / 2;

	//KM 18/10/2016 click noise - sourced from http://soundbible.com/1705-Click2.html
	CEasySound *es;
	CSound* clickSound;
	es = CEasySound::Instance();
	clickSound = es->GetSound(es->Load("sounds/Click2-Sebastian-759472264.wav"));

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		std::cout << "x " << x << ", y " << y << std::endl;
		//return to menu
		if (x >= wc + 168 && x <= wc + 275 && y >= hc +241 && y <= hc+272)
		{
			clickSound->Play();
			gVar.uiLeaderBoard = false;
			gVar.uiMenu = true;
		}
	}
}

