#include "cameraSpace.h"

/*CameraSpace::CameraSpace()
{
	//m_rotateSpeed = 0.0f;
	//m_moveSpeed = 0.0f;
	//
	//ResetXYZ();
	//
	//m_deltaMoveFB = 0;
	//m_deltaMoveLR = 0;
	//m_deltaMoveUD = 0;
	//
	//m_rotateAngleLR = 0.0;
	//m_rotateAngleUD = 0.0;
	//m_deltaAngleLR = 0.0;
	//m_deltaAngleUD = 0.0;
	//
	//m_CollisionDetectionOn = true;
	//
	//// sound objects
	//es = CEasySound::Instance();
	//stepSound = es->GetSound(es->Load("sounds/step.wav"));
	Camer
}

void CameraSpace::MoveFB()
{
	if (InSpace == false)
	{
		// record previous co-ordinates
		m_xLast = m_x;
		m_zLast = m_z;

		// set movement step
		GLdouble moveZ = (m_deltaMoveFB * (m_lookZ)* m_moveSpeed);
		GLdouble moveX = (m_deltaMoveFB * (m_lookX)* m_moveSpeed);

		if (m_CollisionDetectionOn)
		{
			GLdouble startX = m_x + moveX * 5.0;
			GLdouble startZ = m_z + moveZ * 5.0;

			// check if collsion
			if (!(m_colDetect.Collide(startX + m_lookX, m_y + m_lookY, startZ + m_lookZ)))
			{
				// increment position
				m_x += moveX;
				m_z += moveZ;
				// check plain
				SetPlains(moveX, moveZ);
				// redisplay
				callGLLookAt();
			}
		}
		else
		{
			// increment position
			m_x += moveX;
			m_z += moveZ;
			if (InSpace == false)
			{
				// check plain
				SetPlains(moveX, moveZ);
			}
			else
			{
				// check plain
				//SetPlains(moveX,moveY, moveZ);
			}
			// redisplay
			callGLLookAt();
		}
	}
	else
	{
		GLdouble moveZ = (m_deltaMoveFB * (m_lookZ)* m_moveSpeed);
		GLdouble moveY = (m_deltaMoveFB * (m_lookY)* m_moveSpeed);
		GLdouble moveX = (m_deltaMoveFB * (m_lookX)* m_moveSpeed);

		m_x += moveX;
		m_y += moveY;
		m_z += moveZ;
	}
}*/


void CameraSpace::ToFromSpace()
{
	if (InSpace)
	{
		InSpace = false;
	}
	else
	{
		InSpace = true;
	}
}

void CameraSpace::MoveUD()
{
	if (m_CollisionDetectionOn)
	{
		GLdouble startY = m_y + m_deltaMoveUD * (m_lookYY)* m_moveSpeed * 5.0;

		if (!(m_colDetect.Collide(m_x + m_lookXX, startY + m_lookYY, m_z + m_lookZZ)))
		{
			m_y += m_deltaMoveUD * (m_lookYY)* m_moveSpeed;
			callGLLookAt();
		}
	}
	else
	{
		m_y += m_deltaMoveUD * (m_lookYY)* m_moveSpeed;
		callGLLookAt();
	}
}

//void CameraSpace::SetPlains(const int & moveX, const int & moveY, const int & moveZ)
//{
//
//}