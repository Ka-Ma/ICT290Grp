#include "uiScore.h"

uiScore::uiScore(int w, int h)
{
	updateUIScoreMembers(w, h);
	initials = "AAA";
}

void uiScore::updateUIScoreMembers(int w, int h)
{
	width = w;
	height = h;
}

void uiScore::displayUIScore(const GLuint & tempImage, int score)
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

	//convert int value to letter
	if (arr[0] == NULL) { // if arr is null otherwise leave as is
		arr[0] = 1;
		arr[1] = 1;
		arr[2] = 1;
	}
	string sinitial1 = alphaFromInt(arr[0]);
	string sinitial2 = alphaFromInt(arr[1]);
	string sinitial3 = alphaFromInt(arr[2]);
	string sscore = to_string(score);


	//data will need to be converted to string in order to put on screen
	glBindTexture(GL_TEXTURE_2D, 0); //sets active to none
	glColor3f(0.498f, 1.0f, 0.0f);
	glRasterPos2i(wc - 50, hc + 50);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)sscore.c_str());
	glRasterPos2i(wc - 60, hc -115);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)sinitial1.c_str());
	glRasterPos2i(wc -5, hc - 115);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)sinitial2.c_str());
	glRasterPos2i(wc +45, hc - 115);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)sinitial3.c_str());

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	// Reset Perspective Projection
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void uiScore::mouseUIScore(int button, int state, int x, int y)
{
	//KM 15/10/2016 click noise - sourced from http://soundbible.com/1705-Click2.html
	CEasySound *es;
	CSound* clickSound;
	es = CEasySound::Instance();
	clickSound = es->GetSound(es->Load("sounds/Click2-Sebastian-759472264.wav"));

	//variables for boundaries
	int hc = height / 2;
	int wc = width / 2;
	int maxLetter = 26;
	int minLetter = 1;

	//when click in pixel area of menu option make click sound and do expected action
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		//will need to height-y to convert coords to match screen and mouse together

		//std::cout << "height " << height << ", x " << x << ", y " << y << std::endl;
		/* Trouble shooting couts
		cout << "intitials ";
		for (int i = 0; i < 3; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;*/
		//if coord range equals 
		//scroll up wards in alpha for intial 1
		if (x >= wc-72 && x <= wc-42 && y >= hc+70 && y <= hc+92)
		{
			clickSound->Play();
			if (arr[0] >= minLetter && arr[0] < maxLetter) {
				arr[0]++;
			}
		}
		//scroll down wards in alpha for intial 1
		if (x >= wc - 72 && x <= wc-42 && y >= hc+124 && y <= hc+149)
		{
			clickSound->Play();
			if (arr[0] > minLetter && arr[0] <= maxLetter) {
				arr[0]--;
			}
		}
		//scroll up wards in alpha for intial 2
		if (x >= wc - 18 && x <= wc + 14 && y >= hc + 70 && y <= hc + 92)
		{
			clickSound->Play();
			if (arr[1] >= minLetter && arr[1] < maxLetter) {
				arr[1]++;
			}
		}
		//scroll down wards in alpha for intial 2
		if (x >= wc - 18 && x <= wc +14 && y >= hc + 124 && y <= hc + 149)
		{
			clickSound->Play();
			if (arr[1] > minLetter && arr[1] <= maxLetter) {
				arr[1]--;
			}
		}
		//scroll up wards in alpha for intial 3
		if (x >= wc +34 && x <= wc +69 && y >= hc + 70 && y <= hc + 92)
		{
			clickSound->Play();
			if (arr[2] >= minLetter && arr[2] < maxLetter) {
				arr[2]++;
			}
		}
		//scroll down wards in alpha for intial 3
		if (x >= wc +34 && x <= wc +69 && y >= hc + 124 && y <= hc + 149)
		{
			clickSound->Play();
			if (arr[2] > minLetter && arr[2] <= maxLetter) {
				arr[2]--;
			}
		}
		//return to game
		if (x >= wc-54 && x <= wc+54 && y >= hc+236 && y <= hc+271)
		{
			clickSound->Play();
			setInitials(arr);
			gVar.uiScore = false;
			gVar.paused = false;
		}
	}
}

void uiScore::setInitials(int arr[] )
{
	string temp;
	string temp2;

	//cout << "moving array to string " << temp << endl;

	for (int i = 0; i < 3; i++) {
		temp2 = alphaFromInt(arr[i]);
		temp.append(temp2);
		//cout << "moving array to string " << temp << endl;
	}

	initials = temp;
}

string uiScore::getInitials()
{
	return initials;
}

string uiScore::alphaFromInt(int letter) {
	switch (letter) {
	case 1: return "A";
		break; 
	case 2: return "B";
		break;
	case 3: return "C";
		break;
	case 4: return "D";
		break;
	case 5: return "E";
		break;
	case 6: return "F";
		break;
	case 7: return "G";
		break;
	case 8: return "H";
		break;
	case 9: return "I";
		break;
	case 10: return "J";
		break;
	case 11: return "K";
		break; 
	case 12: return "L";
		break; 
	case 13: return "M";
		break; 
	case 14: return "N";
		break; 
	case 15: return "O";
		break; 
	case 16: return "P";
		break; 
	case 17: return "Q";
		break; 
	case 18: return "R";
		break; 
	case 19: return "S";
		break; 
	case 20: return "T";
		break; 
	case 21: return "U";
		break; 
	case 22: return "V";
		break; 
	case 23: return "W";
		break;
	case 24: return "X";
		break; 
	case 25: return "Y";
		break; 
	case 26: return "Z";
		break; 
	default: return "-";
	}
}


