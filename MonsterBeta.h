#pragma once
class MonsterBeta :
	public MonsterBase
{
public:
	MonsterBeta();
	virtual ~MonsterBeta();
public:
	//�ɷ� ���� ��, ��Ÿ�� �п�, ���� ���� �� �� �� ���� �п�
	//����! �п��� �п��� �Ͽ� 2 �̸� �� 4���� ����
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

