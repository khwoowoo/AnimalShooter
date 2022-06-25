#pragma once
class Vec3Calc
{
public:
	Vec3Calc();
	virtual ~Vec3Calc();
public:
	static inline float Angle(Vector3 a, Vector3 b)
	{
		float angle = D3DXToRadian(acosf(D3DXVec3Dot(&a, &b) / (D3DXVec3Length(&a)  * (D3DXVec3Length(&b)))));

		Vector3 vCross;
		D3DXVec3Cross(&vCross, &a, &b);

		return (vCross.z < 0.f) ? -angle : angle;
	}

	static inline Vector3 Rotate(Vector3 vec3, float angle)
	{
		angle = D3DXToRadian(angle);

		Vector3 vOutPut;
		vOutPut.x = cosf(angle) * vec3.x - sinf(angle) * vec3.y;
		vOutPut.y = sinf(angle) * vec3.x + cosf(angle) * vec3.y;
		vOutPut.z = 0.f;

		return vOutPut;
	}
};

