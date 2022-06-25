#include "stdafx.h"


Physics::Physics()
{
	mass = 1.f;
	drag = 1.f;
}


Physics::~Physics()
{
}

void Physics::AddForce(Vector3 force)
{
	vForce += force;
}

Vector3 Physics::Update(Vector3 vInput, float deltatime)
{
	Vector3 vOutPut = vInput;

	vVelocity += vAccel * deltatime;
	vOutPut += vVelocity * deltatime;

	vOutPut += vForce / mass * deltatime;

	Vector3 temp(0.f, 0.f, 0.f);
	D3DXVec3Lerp(&vForce, &vForce, &temp, drag * deltatime);
	return vOutPut;
}
