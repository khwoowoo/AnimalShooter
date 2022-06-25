#pragma once
class Bullet :
	public IObject
{
public:
	Sprite2D m_Sprite;
	Vector3 m_Direction;
public:
	float fSpeed = 800.f;
	float fPower = 10.f;

	//특별한 공격
	bool isNewAtt = false;
	float fNewAttTime = 0.f;
public:
	Bullet();
	Bullet(Vector3 direction);
	virtual ~Bullet();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
};

