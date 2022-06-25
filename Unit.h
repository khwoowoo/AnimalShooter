#pragma once
class Player;
class PlayerAtt;
class Unit :
	public IObject
{
public:
	Sprite2D m_Sprite;
	Player * m_pPlayer;
	Vector3 AddPositiom;
public:
	float m_fToaltime = 0.f;
	float m_fAttTime = 2.f;
public:
	Unit();
	virtual ~Unit();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
};

