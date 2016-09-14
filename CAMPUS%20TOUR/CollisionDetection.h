#ifndef CollisionDetection_H
#define CollisionDetection_H
#endif

#include <iostream>
#include <math.h>
#include <Windows.h>
#include <gl/glu.h>

typedef float point3[3];

class CollisionDetection
{
private:

	struct collider_sphere
	{
		point3 position;
		point3 offset;
		float radius;
		short isColliding;
	};

	struct collider_AABB
	{
		point3 position;
		point3 offset;
		float sizeX;
		float sizeY;
		float sizeZ;
		short isColliding;
	};

public:

	// set up for collision spheres and AABBs
	void collisionInit_S(collider_sphere* sph, float posX, float posY, float posZ, float r);

	void collisionInit_B(collider_AABB* box, float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ);

	void collisionOffset_S(collider_sphere* sph, float offsetX, float offsetY, float offsetZ);

	void collisionOffset_B(collider_AABB* box, float offsetX, float offsetY, float offsetZ);

	// collision detection funcs
	short collisionColliderSS(collider_sphere* sph1, collider_sphere* sph2);

	short collisionColliderSB(collider_sphere*sph, collider_AABB* box);

	short collisionColliderBB(collider_AABB* box1, collider_AABB* box2);

	float collisionFindNormalSS(collider_sphere* coll_1, collider_sphere* coll_2, float* norm_sph1X, float* norm_sph1Y, float* norm_sph1Z, float* norm_sph2X, float* norm_sph2Y, float* norm_sph2Z);

	float collisionFindNormalSB(collider_sphere* coll_1, collider_AABB* coll_2, float* norm_sphX, float* norm_sphY, float* norm_sphZ, float* norm_boxX, float* norm_boxY, float* norm_boxZ);

	float collisionFindNormalBB(collider_AABB* coll_1, collider_AABB* coll_2, float* norm_box1X, float* norm_box1Y, float* norm_box1Z, float* norm_box2X, float* norm_box2Y, float* norm_box2Z);
};