#pragma once
class MonsterBeta :
	public MonsterBase
{
public:
	MonsterBeta();
	virtual ~MonsterBeta();
public:
	//능력 가능 수, 베타는 분열, 수가 많을 수 록 더 많이 분열
	//주의! 분열의 분열을 하여 2 이면 총 4마리 나옴
	int m_iAbilityPossibleCount;
	bool m_isSpriteOpecity;
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
public:
	void SetUp(LPCSTR filename, Vector3 Pos, int eMoveState, int eWeaponState, float speed, int AbilityPossibleCount);
	void Dead_Ability();
};

