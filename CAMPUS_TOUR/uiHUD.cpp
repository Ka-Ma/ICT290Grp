#include "uiHUD.h"

uiHUD::uiHUD(int w, int h)
{
	updateUIHIDMembers(w, h);
}

void uiHUD::setBallCount(int ball)
{
	cball = ball;
}
int uiHUD::getBallCount()
{
	return cball;
}

int uiHUD::getDist()
{
	return distance;
}

void uiHUD::setDist(int distances)
{
	distance = distances;
}

int uiHUD::getTotalBallCount()
{
	return gVar.ballCount - current_Balls;
}

void uiHUD::setTotalBallCount(int currentBalls)
{
	current_Balls = currentBalls;
}


void uiHUD::hitPlanet()
{
	hit_Planets++;
}

float uiHUD::getTimeCount()
{
	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	return 10000 - seconds;
}	

void uiHUD::setScore(int score)
{
	curScore = score;
}

int uiHUD::genScore()
{
	curScore = ((getTimeCount() * 10) / cball) * 1000;
	return curScore;
}

void uiHUD::updateUIHIDMembers(int w, int h)
{
	width = w;
	height = h;
}

void uiHUD::setClock(clock_t nclock)
{
	start = nclock;
}

void uiHUD::displayUIHUD(const GLuint & tempImage)
{
	int d = 200; //width and height of hud arc
	
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
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
		glVertex2f(width-d, height);
		glTexCoord2f(0.0, 1.0);
		glVertex2f(width-d, height-d);
		glTexCoord2f(0.5, 1.0);
		glVertex2f(width, height-d);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(width, height);
	glEnd();

	//MENU
	glBegin(GL_QUADS);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(0, height);
		glTexCoord2f(0.5, 1.0);
		glVertex2f(0, height - d);
		glTexCoord2f(1.0, 1.0);
		glVertex2f(d, height-d);
		glTexCoord2f(1.0, 0.5);
		glVertex2f(d, height);
	glEnd();

	//PLAYER/SCORE STATS 
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex2f(width - d, d);
		glTexCoord2f(0.0, 0.5);
		glVertex2f(width-d, 0);
		glTexCoord2f(0.5, 0.5);
		glVertex2f(width, 0);
		glTexCoord2f(0.5, 0.0);
		glVertex2f(width, d);
	glEnd();
	
	//data will need to be converted to string in order to put on screen
	glBindTexture(GL_TEXTURE_2D, 0); //sets active to none
	glColor3f(0.498f, 1.0f, 0.0f);
	//FIX STARTS
	glRasterPos2i(30, 100);// position of balls in play counter
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)std::to_string(getBallCount()).c_str());  //replace with ballsInPlay variable to string **MT Changed to sing getters and sets to be converted to a string
	glRasterPos2i(100, 40);// position of balls in play counter
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)std::to_string(getTotalBallCount()).c_str());
   	glRasterPos2i(width-110, height-30);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)std::to_string(getTimeCount()).c_str());  //replace with timer variable to string
  	glRasterPos2i(width-140, 20);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)std::to_string(getDist()).c_str());  // replace with distFromGoal variable to string & planetsHit variable to string **MT now activly shows how far away from the goal you are
	glRasterPos2i(width - 50, 80);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)std::to_string(hit_Planets).c_str());//MT** Planets hits number
	//FIX ENDS
	
	glEnable(GL_DEPTH_TEST|GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	
}

void uiHUD::displayInstruct(const GLuint & tempImage)
{
	//finding centre of screen
	int wc = width / 2;
	int hc = height / 2;
	int d = 512/2; // half of width and height of screen

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

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void uiHUD::mouseUIHUD(int button, int state, int x, int y)
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
	}
}

