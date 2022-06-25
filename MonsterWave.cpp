#include "stdafx.h"


MonsterWave::MonsterWave()
{
}


MonsterWave::~MonsterWave()
{
}

void MonsterWave::Init(Player * player)
{
	m_pPlayer = player;
	m_fToalTime = 0.f;
	m_fWaveTime = 5.f;

	m_eWaveState = EWAVE_ONE;
}

void MonsterWave::Update(float deltatime)
{
	if (KeyManager::GetInstance()->GetKeyState(VK_F3) == EKEY_DOWN)
	{
		if ((EWAVE_STATE)m_iNextWave == int(sizeof(EWAVE_STATE)))
			m_iNextWave = -1;
		m_iNextWave++;
		m_eWaveState = (EWAVE_STATE)m_iNextWave;
		cout << "Wave: "<<m_iNextWave << endl;
	}

	NextWave(deltatime);
}

void MonsterWave::NextWave(float deltatime)
{
	switch (m_eWaveState)
	{
	case MonsterWave::EWAVE_ONE:

		if (m_pPlayer->m_iKillMonster >= m_iOneWave)
		{
			m_eWaveState = EWAVE_TWO;
			m_fWaveTime = 3.0f;
			break;
		}

		Wave_One(deltatime);
		break;
	case MonsterWave::EWAVE_TWO:
		if (m_pPlayer->m_bMonsterMiddleKill)
		{
			m_eWaveState = EWAVE_THREE;
			m_fWaveTime = 2.0f;
			m_iThreeWave = m_pPlayer->m_iKillMonster + 50;
			break;
		}
		Wave_Two(deltatime);
		break;
	case MonsterWave::EWAVE_THREE:

		if (m_pPlayer->m_iKillMonster >= m_iThreeWave)
		{
			m_eWaveState = EWAVE_FOUR;
			m_fWaveTime = 3.0f;
			break;
		}

		Wave_Three(deltatime);
		break;
	case MonsterWave::EWAVE_FOUR:
		if (m_pPlayer->m_bMonsterLastKill)
		{
			m_eWaveState = EWAVE_ENDING;
			break;
		}

		Wave_Four(deltatime);
		break;
	case MonsterWave::EWAVE_ENDING:
		m_pPlayer->m_bWin = true;
		break;
	default:
		break;
	}
}

void MonsterWave::ItemCreate()
{
	int iTemp = rand() % 3;

	Item * pItem = new Item;
	pItem->Init();
	pItem->SetUp(iTemp, Vector3(rand() % 1720 + 200.f, 0.f, 0.f), rand()%300 + 100.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pItem);

}

void MonsterWave::Wave_One(float deltatime)
{
	m_fToalTime += deltatime;

	if (m_fToalTime >= m_fWaveTime)
	{
		m_fToalTime -= m_fWaveTime;

		int iTemp = rand() % 3;

		if (iTemp == 0)
		{
			MonsterAlpha * m_pMonsterAlpha = new MonsterAlpha;
			m_pMonsterAlpha->SetUp("Resource/monsterAlpha.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 1, 100.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterAlpha);
		}
		else if (iTemp == 1)
		{
			MonsterBeta * mb = new MonsterBeta;
			mb->SetUp("Resource/monsterBeta.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 2, 100.f, 1);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(mb);
		}
		else
		{
			MonsterGamma * mg = new MonsterGamma;
			mg->SetUp("Resource/monsterGamma.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 3, 100.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(mg);

		}

		ItemCreate();
	}
}

void MonsterWave::Wave_Two(float deltatime)
{
	m_fToalTime += deltatime;

	if (m_fToalTime >= m_fWaveTime)
	{
		m_fToalTime -= m_fWaveTime;

		if (!m_bStage1Middle)
		{
			m_bStage1Middle = true;
			MonsterMiddle * pMM = new MonsterMiddle;
			pMM->SetUp("Resource/monster2.png", Vector3(1080.f, 276.5f, 0.f), 5, 4, 300.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pMM);
		}
		ItemCreate();
	}
}

void MonsterWave::Wave_Three(float deltatime)
{
	m_fToalTime += deltatime;

	if (m_fToalTime >= m_fWaveTime)
	{
		m_fToalTime -= m_fWaveTime;

		int iTemp = rand() % 3;

		if (iTemp == 0)
		{
			MonsterAlpha * m_pMonsterAlpha = new MonsterAlpha;
			m_pMonsterAlpha->SetUp("Resource/monsterAlpha.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 1, 150.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterAlpha);
		}
		else if (iTemp == 1)
		{
			MonsterBeta * mb = new MonsterBeta;
			mb->SetUp("Resource/monsterBeta.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 2, 150.f, 2);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(mb);
		}
		else
		{
			MonsterGamma * mg = new MonsterGamma;
			mg->SetUp("Resource/monsterGamma.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 3, 150.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(mg);

		}

		ItemCreate();
	}
}

void MonsterWave::Wave_Four(float deltatime)
{
	m_fToalTime += deltatime;

	if (m_fToalTime >= m_fWaveTime)
	{
		m_fToalTime -= m_fWaveTime;

		if (!m_bStage1Last)
		{
			m_bStage1Last = true;
			MonsterLast * pML = new MonsterLast;
			pML->SetUp("Resource/monster1.png", Vector3(423.f,310.f, 0.f), 0, 5, 300.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pML);
		}

		int iTemp = rand() % 3;

		if (iTemp == 0)
		{
			MonsterAlpha * m_pMonsterAlpha = new MonsterAlpha;
			m_pMonsterAlpha->SetUp("Resource/monsterAlpha.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 1, 100.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMonsterAlpha);
		}
		else if (iTemp == 1)
		{
			MonsterBeta * mb = new MonsterBeta;
			mb->SetUp("Resource/monsterBeta.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 2, 100.f, 1);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(mb);
		}
		else
		{
			MonsterGamma * mg = new MonsterGamma;
			mg->SetUp("Resource/monsterGamma.png", Vector3(rand() % 1720 + 200.f, 0.f, 0.f), 1, 3, 100.f);
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(mg);

		}
		ItemCreate();
	}
}
