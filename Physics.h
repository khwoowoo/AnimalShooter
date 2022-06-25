#pragma once
class Physics
{
public:
	float mass, drag;
public:
	Vector3 vAccel    = Vector3(0.f, 0.f, 0.f);
	Vector3 vVelocity = Vector3(0.f, 0.f, 0.f);
	Vector3 vForce    = Vector3(0.f, 0.f, 0.f);
public:
	Physics();
	virtual ~Physics();
public:
	void AddForce(Vector3 force);
	Vector3 Update(Vector3 vInput, float deltatime);
};

