#pragma once
class Player;
class PlayerLS :
	public IObject
{
public:
	Player * m_Player;
	Sprite2D m_Sprite;
public:
	float fSpeed = 2300.f;
	float fPower = 1.f;
public:
	PlayerLS();
	virtual ~PlayerLS();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
};

