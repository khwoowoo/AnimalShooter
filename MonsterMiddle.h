#pragma once
class MonsterMiddle :
	public MonsterBase
{
public:
	Sprite2D m_BossUISprite;
public:
	//µÓ¿Â ¿Ã∆Â∆Æ
	bool m_bEff = true;
public:
	MonsterMiddle();
	virtual ~MonsterMiddle();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
public:
	void SetUp(LPCSTR filename, Vector3 Pos, int eMoveState, int eWeaponState, float speed);
};

