#pragma once
class MonsterWave
{
public:
	Player * m_pPlayer;
public:
	enum EWAVE_STATE
	{
		EWAVE_ONE,
		EWAVE_TWO,
		EWAVE_THREE,
		EWAVE_FOUR,
		EWAVE_ENDING,
	};
public:
	//시간 재는 변수
	float m_fToalTime;
	//일정 시간 동안 반복
	float m_fWaveTime;

	//다음 웨이브로 넘어가는 조건 변수
	int m_iOneWave = 20;
	//다음 웨이브로 넘어가는 조건 변수
	int m_iThreeWave = 100;

	//등장 이펙트 하기
	//bool m_bStage1MiddleEff = false;

	//생성이 되었는지 확인
	bool m_bStage1Middle = false;
	//생성이 되었는지 확인
	bool m_bStage1Last = false;

	int m_iNextWave = 0;
public:
	EWAVE_STATE m_eWaveState;
public:
	MonsterWave();
	virtual ~MonsterWave();
public:
	void Init(Player * player);
	void Update(float deltatime);
	void NextWave(float deltatime);
	void ItemCreate();
	void Wave_One(float deltatime);
	void Wave_Two(float deltatime);
	void Wave_Three(float deltatime);
	void Wave_Four(float deltatime);
};

