#include "OBJLoader.h"

using namespace std;

int OBJLoader::loadObject(const char* filename)
{
	//open and check file
	ifstream in(filename);
	if (!in.is_open())
	{
		cout << "File did not open" << endl;
		return -1;
	}

	//load file into coord vector
	char buf[256];
	while (!in.eof())
	{
		in.getline(buf, 256);
		coord.push_back(new string(buf));
	}

	//convert coord vector into each of the types (vertex,normal,face)
	for (int i = 0; i < coord.size(); i++)
	{
		if ((*coord[i])[0] == '#')
			continue;
		if ((*coord[i])[0] == 'v' && (*coord[i])[1] == ' ')
		{
			float tmpx, tmpy, tmpz;
			sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);
			vertex.push_back(new coordinates(tmpx, tmpy, tmpz));
		}
		else if ((*coord[i])[0] == 'v' && (*coord[i])[1] == 'n')
		{
			float tmpx, tmpy, tmpz;
			sscanf(coord[i]->c_str(), "vn %f %f %f", &tmpx, &tmpy, &tmpz);
			normals.push_back(new coordinates(tmpx, tmpy, tmpz));
		}
		else if ((*coord[i])[0] == 'f')
		{
			int a, b, c, d, e;
			if (count(coord[i]->begin(), coord[i]->end(), ' ') == 4)
			{
				sscanf(coord[i]->c_str(), "f %d//%d %d//%d %d//%d %d//%d", &b, &a, &c, &a, &d, &a, &e,&a);
				faces.push_back(new face(a, b, c, d, e));
			}
			else
			{
				sscanf(coord[i]->c_str(), "f %d//%d %d//%d %d//%d", &b, &a, &c, &a, &d, &a );
				faces.push_back(new face(a, b, c, d));
			}			
		}
	}
	//draw object
	int num;
	num = glGenLists(1);
	glNewList(num, GL_COMPILE);
	for (int i = 0; i < faces.size(); i++)
	{
		if (faces[i]->four)
		{
			glBegin(GL_QUADS);
				glNormal3f(normals[faces[i]->face_num-1]->x, normals[faces[i]->face_num - 1]->y, normals[faces[i]->face_num - 1]->z);
				glVertex3f(vertex[faces[i]->faces[0] - 1]->x, vertex[faces[i]->faces[0] - 1]->y, vertex[faces[i]->faces[0] - 1]->z);
				glVertex3f(vertex[faces[i]->faces[1] - 1]->x, vertex[faces[i]->faces[1] - 1]->y, vertex[faces[i]->faces[1] - 1]->z);
				glVertex3f(vertex[faces[i]->faces[2] - 1]->x, vertex[faces[i]->faces[2] - 1]->y, vertex[faces[i]->faces[2] - 1]->z);
				glVertex3f(vertex[faces[i]->faces[3] - 1]->x, vertex[faces[i]->faces[3] - 1]->y, vertex[faces[i]->faces[3] - 1]->z);
			glEnd();
		}
		else
		{
			glBegin(GL_TRIANGLES);
				glNormal3f(normals[faces[i]->face_num - 1]->x, normals[faces[i]->face_num - 1]->y, normals[faces[i]->face_num - 1]->z);
				glVertex3f(vertex[faces[i]->faces[0] - 1]->x, vertex[faces[i]->faces[0] - 1]->y, vertex[faces[i]->faces[0] - 1]->z);
				glVertex3f(vertex[faces[i]->faces[1] - 1]->x, vertex[faces[i]->faces[1] - 1]->y, vertex[faces[i]->faces[1] - 1]->z);
				glVertex3f(vertex[faces[i]->faces[2] - 1]->x, vertex[faces[i]->faces[2] - 1]->y, vertex[faces[i]->faces[2] - 1]->z);
			glEnd();
		}
	}
	glEndList();

	coord.clear();
	faces.clear();
	normals.clear();
	vertex.clear();

	//for (int i = 0; i < coord.size(); i++)
	//{
	//	delete coord[i];
	//}
	//for (int i = 0; i < faces.size(); i++)
	//{
	//	delete faces[i];
	//}
	//for (int i = 0; i < normals.size(); i++)
	//{
	//	delete normals[i];
	//}
	//for (int i = 0; i < vertex.size(); i++)
	//{
	//	delete vertex[i];
	//}

	return num;
}