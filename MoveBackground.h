#pragma once
class MoveBackground :
	public IObject
{
public:
	Sprite2D m_Sprite;
	Vector3 m_vFirst, m_vSecond;
public:
	float m_fSpeed;
	float m_fHeight;
public:
	MoveBackground();
	virtual ~MoveBackground();
public:
	void SetUp(LPCSTR filename, float speed);
	virtual void Update(float deltatime);
	virtual void Render();
};

