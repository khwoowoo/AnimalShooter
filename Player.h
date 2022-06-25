#pragma once
class Player :
	public IObject
{
public:
	Sprite2D m_Sprite;
	Sprite2D m_HPBar;
	Math m_Math;
	Physics m_Physics;
	Unit * m_pUnit[4];
	Sprite2D m_WeaponStateSprite;
public:
	enum EPLAYER_STATE
	{
		EPLAYER_NONE,
		EPLAYER_UP,
		EPLAYER_DOWN,
		EPLAYER_LEFT,
		EPLAYER_RIGHT,
		EPLAYER_ATT
	};

	enum EWEAPON_STATE
	{
		EWEAPON_SINGLE,
		EWEAPON_BARRAGE,
		EWEAPON_TREEWAY,
		EWEAPON_LASER,
	};
public:
	EPLAYER_STATE m_ePlayerState;
	EWEAPON_STATE m_eWeaponState;
public:
	//유닛 제한
	bool m_bUnit[4] = { false, };
	int m_iUnitCount = 0;
	//이동속도
	int m_iMoveSpeed = 700.f;

	//공격속도
	float m_fTotalShotDelay = 0.f;
	const float m_fShotDelay = 0.1f;

	//무기전환 변수
	int m_iNextWeapon = 0;

	//데미지 받았을 경우
	bool m_bDamage = false;
	float m_fDamageTime = 0.f;
	float m_fTime = 0.f;

	//체력
	float m_fHP = 100.f;
	float m_fMaxHP = 100.f;

	//플레이어가 얻은 점수
	int m_iScore = 0;
	
	//플레이어가 죽인 몬스터 수
	int m_iKillMonster;

	//stage1중간 보스 죽었는지
	bool m_bMonsterMiddleKill = false;
	//stage1최종 보스 죽었는지
	bool m_bMonsterLastKill = false;

	//공격력
	float m_fPower = 10.f;

	bool m_bAttSound = false;

	//승리 확인
	bool m_bWin = false;
public:
	Player();
	virtual ~Player();
public:
	virtual void Init();
	virtual void Render();
	virtual void Update(float deltatime);
	virtual void Destory();
	virtual bool CollisionTo(IObject * obj);
	virtual bool CollisionFrom(IObject * obj);
public:
	void Move(float deltatime);
	void PlayerState(float deltatime);
	void WeaponState(float deltatime);
	void Damage(float deltatime, float Delay);
	void DemageEffect();
	void DemageEffect(float damageNumber);
	void UnitCreate();
	void WeaponChange();
};

