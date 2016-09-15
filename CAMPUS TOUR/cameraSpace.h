#ifndef CAMERASPACE_H
#define CAMERASPACE_H

#include "camera.h"

class CameraSpace : public Camera
{
	public:
		CameraSpace() :Camera() {}

		bool AmInSpace() { return InSpace; };
		void ToFromSpace();
		void MoveUD();

	protected:
		//void SetPlains(const int & moveX,const int & moveY, const int & moveZ);

	private:
		GLdouble m_yLast;
		bool InSpace = false;
};
#endif