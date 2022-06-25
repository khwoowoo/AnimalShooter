#pragma once
class MonsterAlpha :
	public MonsterBase
{
public:
	MonsterAlpha();
	virtual ~MonsterAlpha();
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

