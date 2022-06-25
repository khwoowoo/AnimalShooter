#pragma once
class MonsterBase :
	public IObject
{
public:
	Sprite2D m_Sprite;
	Sprite2D m_HPBar;
	Math m_Math;
	Vec3Calc m_Vec3Calc;
public:
	enum EWEAPON_STATE
	{
		EWEAPON_NONE,
		EWEAPON_SINGLE,
		EWEAPON_BARRAGE,
		EWEAPON_N_WAY,
		EWEAPON_STAGE1_MIDDLE,
		EWEAPON_STAGE1_LAST,
	};

	enum EMOVE_STATE
	{
		EMOVE_NONE,
		EMOVE_FRONT,
		EMOVE_BACK,
		EMOVE_LEFT,
		EMOVE_RIGHT,
		EMOVE_LEFT_RIGHT_MOVE,
	};

	enum EKIND_STATE
	{
		EKIND_ALPHA,
		EKIND_BETA,
		EKIND_GAMMA,
	};
public:
	EMOVE_STATE m_eMoveState;
	EWEAPON_STATE m_eWeaponState;
	EKIND_STATE m_eKindState;
public:
	//�̵��ӵ�
	float m_iMoveSpeed = 700.f;

	//���ݼӵ�
	float m_fTotalShotDelay = 0.f;
	const float m_fShotDelay = 2.0f;
	const float m_fMiddleShotDelay = 0.7f;
	const float m_fLastShotDelay = 2.0f;

	//������ȯ ����
	int m_iNextWeapon = 0;

	//������ �޾��� ���
	bool m_bDamage = false;
	float m_fDemageTime = 0.f;
	float m_fTime = 0.f;

	//ü��
	float m_fHP = 100.f;
	float m_fMaxHP = 100.f;

	//������ ����
	float m_fDamage = 0.f;

	//ó���� ��Ī�Ҷ� �޾Ҵ� �̵� state;
	int m_iFirstMoveState;

	//�÷��̾ ���� ����
	int m_iScore;

	//���ݷ�
	float m_fPower = 10.f;

	//����
	float m_fDirection = 1.f;
public:
	MonsterBase();
	virtual ~MonsterBase();
public:
	void Move(float deltatime);
	void WeaponState(float deltatime);
	void Damage(float deltatime, float Delay);
	void DemageEffect();
	void DemageEffect(float damageNumber);
};

