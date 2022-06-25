#pragma once
class PlayerAtt :
	public IObject
{
public:
	Sprite2D m_Sprite;
	Vector3 m_Direction;
public:
	float fSpeed = 800.f;
	float fPower = 10.f;
public:
	PlayerAtt();
	PlayerAtt(Vector3 direction);
	virtual ~PlayerAtt();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
};

