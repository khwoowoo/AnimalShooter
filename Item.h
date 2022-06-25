#pragma once
class Item :
	public IObject
{
public:
	Sprite2D m_Sprite;
public:
	enum EITEM_STATE
	{
		EITEM_HAERT,
		EITEM_POWER,
		EITEM_UNIT,
	};
public:
	EITEM_STATE m_eItemState;
public:
	//충돌 범위
	float m_fCollisionLength;

	float m_fSpeed;
public:
	Item();
	virtual ~Item();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
public:
	void SetUp(int itemImage, Vector3 pos, float speed);
	void EffectGet();
};

