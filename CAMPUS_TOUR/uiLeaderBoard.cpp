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

	//data will need to be converted to string/unsigned char* in order to put on screen
	std::string strName;
	const unsigned char * strName1;
	std::string strDate;
	const unsigned char * strDate1;
	std::string strScore;
	const unsigned char * strScore1;
	glBindTexture(GL_TEXTURE_2D, 0); //sets active to none
	glColor3f(0.498f, 1.0f, 0.0f);
	//for (each entry in leaderboard vector) the rasterposition will need to move down
	int y = hc + d - 200;

	//find which is larger, 10 or the size of the vector
	size_t size = 0;
	if (lboard.size() < 10)
		size = lboard.size();
	else
		size = 10;

	for (int i = 0; i < size; i++)
	{
		//preparing strings for rendering
		strName = lboard[i].name;
		strName1 = reinterpret_cast<const unsigned char *> (strName.c_str());
		strDate = lboard[i].sDate;
		strDate1 = reinterpret_cast<const unsigned char *> (strDate.c_str());
		std::stringstream convert;  //to convert int to string
		convert << lboard[i].nScore;
		strScore = convert.str(); 
		strScore1 = reinterpret_cast<const unsigned char *> (strScore.c_str());

		//rendering
		glRasterPos2i(wc - d + 60, y);
		glutBitmapString(GLUT_BITMAP_9_BY_15, strName1); 
		glRasterPos2i(wc - d + 200, y);
		glutBitmapString(GLUT_BITMAP_9_BY_15, strDate1);
		glRasterPos2i(wc - d + 350, y);
		glutBitmapString(GLUT_BITMAP_9_BY_15, strScore1);
		
		// ready for next line
		y = y - 25;  
	}
		
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
		//std::cout << "x " << x << ", y " << y << std::endl;
		//return to menu
		if (x >= wc + 168 && x <= wc + 275 && y >= hc +241 && y <= hc+272)
		{
			clickSound->Play();
			gVar.uiLeaderBoard = false;
			gVar.uiMenu = true;
		}
	}
}

void uiLeaderBoard::getLeaderBoard() 
{
	//leaderboard file
	std::ifstream lbFile;
	lbFile.open("data/LeaderBoard.txt");
	score temp;
	std::string lineparts[3];
	
	if (lbFile.is_open())
	{
		while (!lbFile.eof())
		{
			for (int i = 0; i < 3; i++) {
				std::getline(lbFile, lineparts[i], ',');
			}
			//eat the newline
			lbFile.ignore();

			temp.name = lineparts[0];
			temp.sDate = lineparts[1];
			
			//converting score to int
			std::stringstream convert(lineparts[2]); 

			if (!(convert >> temp.nScore))  //puts value in position
				temp.nScore = 0;  //if that fails sets to 0

			//test
			//std::cout << "name " << temp.name << std::endl;
			//std::cout << "date " << temp.sDate << std::endl;
			//std::cout << "score " << temp.nScore << std::endl;

			//add this score to the vector
			lboard.push_back(temp);
		}
		lbFile.close();
	}

	sortLeaderBoard();
}

void uiLeaderBoard::setLeaderBoard()
{
	//for each score in the vector write to the file 
	std::ofstream lbFile;
	lbFile.open("data/LeaderBoard.txt");

	size_t size = lboard.size();

	for (int i = 0; i < size; i++)
	{
		lbFile << lboard[i].name <<","<< lboard[i].sDate <<","<< lboard[i].nScore << "," ;
		if (i < size - 1) //newline for each except last
			lbFile << "\n";
	}

	lbFile.close();
}

void uiLeaderBoard::addLeaderBoard(std::string newName, std::string newDate, int newScore)
{
	score temp;
	temp.name = newName;
	temp.sDate = newDate;
	temp.nScore = newScore;

	lboard.push_back(temp);

	sortLeaderBoard();
}

void uiLeaderBoard::sortLeaderBoard() 
{
	//sort largest score first
	std::sort(lboard.begin(), lboard.end(), [](const score& lhs, const score& rhs)
	{
		return lhs.nScore > rhs.nScore;
	});
}