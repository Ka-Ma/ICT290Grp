#include <iostream>
#include <math.h>
#include "CollisionDetection.h"

using namespace std;

// set up for collision spheres and AABBs
void CollisionDetection::collisionInit_S(collider_sphere* sph, float posX, float posY, float posZ, float r)
{
	sph->position[0] = posX;
	sph->position[1] = posY;
	sph->position[2] = posZ;

	sph->offset[0] = 0;
	sph->offset[1] = 0;
	sph->offset[2] = 0;

	sph->radius = r;

	sph->isColliding = 0;
}

void CollisionDetection::collisionInit_B(collider_AABB* box, float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ)
{
	box->position[0] = posX;
	box->position[1] = posY;
	box->position[2] = posZ;

	box->offset[0] = 0;
	box->offset[1] = 0;
	box->offset[2] = 0;

	box->sizeX = sizeX;
	box->sizeY = sizeY;
	box->sizeZ = sizeZ;

	box->isColliding = 0;
}

void CollisionDetection::collisionOffset_S(collider_sphere* sph, float offsetX, float offsetY, float offsetZ)
{
	sph->offset[0] = offsetX;
	sph->offset[1] = offsetY;
	sph->offset[2] = offsetZ;
}

void CollisionDetection::collisionOffset_B(collider_AABB* box, float offsetX, float offsetY, float offsetZ)
{
	box->offset[0] = offsetX;
	box->offset[1] = offsetY;
	box->offset[2] = offsetZ;
}

// collision detection funcs
short CollisionDetection::collisionColliderSS(collider_sphere* sph1, collider_sphere* sph2)
{
	float magX = (sph1->position[0] - sph2->position[0]) * (sph1->position[0] - sph2->position[0]);
	float magY = (sph1->position[1] - sph2->position[1]) * (sph1->position[1] - sph2->position[1]);
	float magZ = (sph1->position[2] - sph2->position[2]) * (sph1->position[2] - sph2->position[2]);

	if (sqrt(magX + magY + magZ) <= (sph1->radius + sph2->radius))
	{
		sph1->isColliding = 1;
		sph2->isColliding = 1;
		return 1;   // TRUE.
	}
	else
		return 0;   // FALSE.

}

short CollisionDetection::collisionColliderSB(collider_sphere*sph, collider_AABB* box)
{
	short coll = 1;	// TRUE.

					// Test X axis.
	if (sph->position[0] + sph->radius < box->position[0] - 0.5f * box->sizeX)
	{
		coll = 0;   // FALSE.
	}
	else if (sph->position[0] - sph->radius > box->position[0] + 0.5f * box->sizeX)
	{
		coll = 0;   // FALSE.
	}
					// Test Y axis.
	else if (sph->position[1] + sph->radius < box->position[1] - 0.5f * box->sizeY)
	{
		coll = 0;   // FALSE.
	}
	else if (sph->position[1] - sph->radius > box->position[1] + 0.5f * box->sizeY) 
	{
		coll = 0;   // FALSE.
	}
					// Test Z axis.
	else if (sph->position[2] + sph->radius < box->position[2] - 0.5f * box->sizeZ)
	{
		coll = 0;   // FALSE.
	}
	else if (sph->position[2] - sph->radius > box->position[2] + 0.5f * box->sizeZ)
	{
		coll = 0;   // FALSE.
	}

	sph->isColliding = coll;
	box->isColliding = coll;

	return coll;
}

short CollisionDetection::collisionColliderBB(collider_AABB* box1, collider_AABB* box2)
{
	short coll = 1; // TRUE.

	// Test X axis.
	if (box1->position[0] + 0.5f * box1->sizeX < box2->position[0] - 0.5f * box2->sizeX)
	{
		coll = 0;   // FALSE.
	}
	else if (box1->position[0] - 0.5f * box1->sizeX > box2->position[0] + 0.5f * box2->sizeX)
	{
		coll = 0;   // FALSE.
	}

	// Test Y axis.
	else if (box1->position[1] + 0.5f * box1->sizeY < box2->position[1] - 0.5f * box2->sizeY)
	{
		coll = 0;   // FALSE.
	}

	else if (box1->position[1] - 0.5f * box1->sizeY > box2->position[1] + 0.5f * box2->sizeY)
	{
		coll = 0;   // FALSE.
	}

	// Test Z axis.
	else if (box1->position[2] + 0.5f * box1->sizeZ < box2->position[2] - 0.5f * box2->sizeZ)
	{
		coll = 0;   // FALSE.
	}
	else if (box1->position[2] - 0.5f * box1->sizeZ > box2->position[2] + 0.5f * box2->sizeZ)
	{
		coll = 0;   // FALSE.
	}

	box1->isColliding = coll;
	box2->isColliding = coll;

	return coll;
}

float CollisionDetection::collisionFindNormalSS(collider_sphere* coll_1, collider_sphere* coll_2, float* norm_sph1X, float* norm_sph1Y, float* norm_sph1Z, float* norm_sph2X, float* norm_sph2Y, float* norm_sph2Z)
{
	// Find the un-normalised direction of the collision face of the other sphere.
	point3 dir = { coll_1->position[0] - coll_2->position[0],
		coll_1->position[1] - coll_2->position[1],
		coll_1->position[2] - coll_2->position[2] };

	float dir_sq = dir[0] * dir[0] + dir[1] * dir[1] + dir[2] * dir[2];

	// Normalise the un-normalised direction.
	*norm_sph1X = -dir[0] / sqrt(dir_sq);
	*norm_sph1Y = -dir[1] / sqrt(dir_sq);
	*norm_sph1Z = -dir[2] / sqrt(dir_sq);

	*norm_sph2X = -*norm_sph1X;
	*norm_sph2Y = -*norm_sph1Y;
	*norm_sph2Z = -*norm_sph1Z;

	float magX = (coll_1->position[0] - coll_2->position[0]) * (coll_1->position[0] - coll_2->position[0]);
	float magY = (coll_1->position[1] - coll_2->position[1]) * (coll_1->position[1] - coll_2->position[1]);
	float magZ = (coll_1->position[2] - coll_2->position[2]) * (coll_1->position[2] - coll_2->position[2]);

	float penetrationDepth = (coll_1->radius + coll_2->radius) - sqrt(magX + magY + magZ);

	return penetrationDepth;
}

float CollisionDetection::collisionFindNormalSB(collider_sphere* coll_1, collider_AABB* coll_2, float* norm_sphX, float* norm_sphY, float* norm_sphZ, float* norm_boxX, float* norm_boxY, float* norm_boxZ)
{
	*norm_sphX = 0;
	*norm_sphY = 0;
	*norm_sphZ = 0;

	*norm_boxX = 0;
	*norm_boxY = 0;
	*norm_boxZ = 0;

	// The penetration depths for each set of faces. FORMAT: { sphere <-> right, sphere <-> left, sphere <-> bottom, sphere <-> top, sphere <-> back, sphere <-> front  }.
	float penetrations[6] = { 0,0,0,0,0,0 };

	// Calculate the penetration depths for each set of sides.
	penetrations[0] = abs((coll_1->position[0] - coll_1->radius) - (coll_2->position[0] + coll_2->sizeX * 0.5f));
	penetrations[1] = abs((coll_1->position[0] + coll_1->radius) - (coll_2->position[0] - coll_2->sizeX * 0.5f));
	penetrations[2] = abs((coll_1->position[1] + coll_1->radius) - (coll_2->position[1] - coll_2->sizeY * 0.5f));
	penetrations[3] = abs((coll_1->position[1] - coll_1->radius) - (coll_2->position[1] + coll_2->sizeY * 0.5f));
	penetrations[4] = abs((coll_1->position[2] + coll_1->radius) - (coll_2->position[2] - coll_2->sizeZ * 0.5f));
	penetrations[5] = abs((coll_1->position[2] - coll_1->radius) - (coll_2->position[2] + coll_2->sizeZ * 0.5f));

	// Find the smallest penetration depth.
	int i;
	float min = penetrations[0];
	int minIndex = 0;

	for (i = 1; i < 6; i++)
	{
		if (penetrations[i] < min)
		{
			min = penetrations[i];
			minIndex = i;
		}
	}

	// Use the index of the smallest penetration depth to dictate the normal of the colliding face.
	switch (minIndex)
	{
	case 0:
		*norm_sphX = 1;
		*norm_boxX = -1;
		break;

	case 1:
		*norm_sphX = -1;
		*norm_boxX = 1;
		break;

	case 2:
		*norm_sphY = -1;
		*norm_boxY = 1;
		break;

	case 3:
		*norm_sphY = -1;
		*norm_boxY = 1;
		break;

	case 4:
		*norm_sphZ = 1;
		*norm_boxZ = -1;
		break;

	case 5:
		*norm_sphZ = 1;
		*norm_boxZ = -1;
		break;

	default:
		// Do nothing...
		break;
	}

	return min;
}

float CollisionDetection::collisionFindNormalBB(collider_AABB* coll_1, collider_AABB* coll_2, float* norm_box1X, float* norm_box1Y, float* norm_box1Z, float* norm_box2X, float* norm_box2Y, float* norm_box2Z)
{
	*norm_box1X = 0;
	*norm_box1Y = 0;
	*norm_box1Z = 0;

	*norm_box2X = 0;
	*norm_box2Y = 0;
	*norm_box2Z = 0;

	// The penetration depths for each set of faces. FORMAT: { left1 <-> Right2, right1 <-> Left2, top1 <-> Bottom2, bottom1 <-> Top2, front1 <-> Back2, back1 <-> Front2  }.
	float penetrations[6] = { 0,0,0,0,0,0 };

	// Calculate the penetration depths for each set of sides.
	penetrations[0] = abs((coll_1->position[0] - coll_1->sizeX * 0.5f) - (coll_2->position[0] + coll_2->sizeX * 0.5f));
	penetrations[1] = abs((coll_1->position[0] + coll_1->sizeX * 0.5f) - (coll_2->position[0] - coll_2->sizeX * 0.5f));
	penetrations[2] = abs((coll_1->position[1] + coll_1->sizeY * 0.5f) - (coll_2->position[1] - coll_2->sizeY * 0.5f));
	penetrations[3] = abs((coll_1->position[1] - coll_1->sizeY * 0.5f) - (coll_2->position[1] + coll_2->sizeY * 0.5f));
	penetrations[4] = abs((coll_1->position[2] + coll_1->sizeZ * 0.5f) - (coll_2->position[2] - coll_2->sizeZ * 0.5f));
	penetrations[5] = abs((coll_1->position[2] - coll_1->sizeZ * 0.5f) - (coll_2->position[2] + coll_2->sizeZ * 0.5f));

	// Find the smallest penetration depth.
	int i;
	float min = penetrations[0];
	int minIndex = 0;

	for (i = 1; i < 6; i++)
	{
		if (penetrations[i] < min)
		{
			min = penetrations[i];
			minIndex = i;
		}
	}

	// Use the index of the smallest penetration depth to dictate the normal of the colliding face.
	switch (minIndex)
	{
	case 0:
		*norm_box1X = 1;
		*norm_box2X = -1;
		break;

	case 1:
		*norm_box1X = -1;
		*norm_box2X = 1;
		break;

	case 2:
		*norm_box1Y = -1;
		*norm_box2Y = 1;
		break;

	case 3:
		*norm_box1Y = 1;
		*norm_box2Y = -1;
		break;

	case 4:
		*norm_box1Z = -1;
		*norm_box2Z = 1;
		break;

	case 5:
		*norm_box1Z = 1;
		*norm_box2Z = -1;
		break;

	default:
		// Do nothing...
		break;
	}

	return penetrations[minIndex];
}