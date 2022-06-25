#pragma once
class MonsterGamma :
	public MonsterBase
{
public:
	bool m_isDead_Ability;
	float m_fScaleIndex;
	float m_fPower;
public:
	MonsterGamma();
	virtual ~MonsterGamma();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
public:
	void SetUp(LPCSTR filename, Vector3 Pos, int eMoveState, int eWeaponState, float speed);
	void Dead_Ability();
};

