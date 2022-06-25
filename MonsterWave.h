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
	//�ð� ��� ����
	float m_fToalTime;
	//���� �ð� ���� �ݺ�
	float m_fWaveTime;

	//���� ���̺�� �Ѿ�� ���� ����
	int m_iOneWave = 20;
	//���� ���̺�� �Ѿ�� ���� ����
	int m_iThreeWave = 100;

	//���� ����Ʈ �ϱ�
	//bool m_bStage1MiddleEff = false;

	//������ �Ǿ����� Ȯ��
	bool m_bStage1Middle = false;
	//������ �Ǿ����� Ȯ��
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

