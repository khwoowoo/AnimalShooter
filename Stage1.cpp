#include "stdafx.h"


Stage1::Stage1()
{
}


Stage1::~Stage1()
{
}

void Stage1::Open()
{
	m_bWinUI = false;
	m_bLoseUI = false;
	//-------------------------------------------
	m_pRenderTarget = RenderTarget::Create(1570.f, 848.f);

	MoveBackground * m_pMBG = new MoveBackground;
	m_pMBG->SetUp("Resource/Stage1/Stage1.png", 500.f);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMBG);

	m_pMainUI = new MainUI;
	m_pMainUI->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pMainUI);


	m_pPlayer = new Player;
	m_pPlayer->Init();
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pPlayer);

	m_pMainUI->m_pNumberSprite->SetNumber(m_pPlayer->m_iScore);

	m_pMonsterWave = new MonsterWave;
	m_pMonsterWave->Init(m_pPlayer);

	// 사운드 객체 추가
	background1 = new SoundData;
	background1->fileType = "WaveAudio";
	//background1->fileType = "mpegvideo";
	background1->fileAddress = "Resource/town1.wav";
	background1->isLoop = true;

	// 사운드 객체를 로드
	MCISound::GetInstance()->LoadWav(background1);


	SceneManager::GetInstance()->GetNowScene()->m_SoundManager.AddSound(background1);

	MCISound::GetInstance()->Play(background1);

	m_ResultUI.LoadTextureFromFile("Resource/UI/lose_UI.png");
	m_ResultUI.m_Position = Vector3(970.f, 531.5f, 0.f);
	m_ResultUI.bEnable = false;

	m_pButton[0] = new Button;
	//Vector3(570.f, 706.f, 0.f)
	m_pButton[0]->SetUp("Resource/UI/replay_button1.png", Vector3(570.f, 1200.f, 0.f), 100.f, false);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[0]);

	m_pButton[1] = new Button;
	//Vector3(1453.1f, 706.f, 0.f)
	m_pButton[1]->SetUp("Resource/UI/close_button1.png", Vector3(1453.1f, 1200.f, 0.f), 100.f, false);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[1]);

	m_pButton[2] = new Button;
	//Vector3(1691.5f, 167.6f, 0.f)
	m_pButton[2]->SetUp("Resource/UI/x_button.png", Vector3(1691.5f, 1200.f, 0.f), 100.f, false);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[2]);
}

void Stage1::Update(float deltatime)
{
	if (!m_pPlayer->isDestory)
		m_pMainUI->m_pNumberSprite->SetNumber(m_pPlayer->m_iScore);

	m_pMonsterWave->Update(deltatime);

	LoseUI();
	WinUI();
}

void Stage1::Render()
{
}

void Stage1::RenderTargetRender()
{
	//랜더타겟 따로 랜더
	m_pRenderTarget->RenderTargetBeginGenerate();
	SceneManager::GetInstance()->GetNowScene()->SceneRender();
	m_pRenderTarget->RenderTargetEndGenerate();
	m_pRenderTarget->Render();
}

void Stage1::UIRender()
{
	m_pMainUI->Render();
	m_ResultUI.OnRender();
	m_pButton[0]->m_Sprite.OnRender();
	m_pButton[1]->m_Sprite.OnRender();
	m_pButton[2]->m_Sprite.OnRender();
}

void Stage1::LastRender()
{
}

void Stage1::Close()
{
	//m_pRenderTarget->Release();
	//Safe_Delete(m_pRenderTarget);
}

void Stage1::LoseUI()
{
	if (!m_bLoseUI)
	{
		if (m_pPlayer->m_fHP <= 0.f)
		{
			Time::GetInstance()->bStop = true;
			m_ResultUI.bEnable = true;

			m_pButton[0]->m_Sprite.m_Position.y = 706.f;
			m_pButton[1]->m_Sprite.m_Position.y = 706.f;
			m_bLoseUI = true;
		}
	}
	else if (m_bLoseUI)
	{
		if (m_pButton[0]->m_bIn)
			m_pButton[0]->m_Sprite.LoadTextureFromFile("Resource/UI/replay_button2.png");
		else
			m_pButton[0]->m_Sprite.LoadTextureFromFile("Resource/UI/replay_button1.png");

		if (m_pButton[1]->m_bIn)
			m_pButton[1]->m_Sprite.LoadTextureFromFile("Resource/UI/close_button2.png");
		else
			m_pButton[1]->m_Sprite.LoadTextureFromFile("Resource/UI/close_button1.png");

		if (m_pButton[0]->m_bClick)
		{
			SceneManager::GetInstance()->ChangeScene("Stage1", true);
			Time::GetInstance()->bStop = false;
		}
		if (m_pButton[1]->m_bClick)
		{
			SceneManager::GetInstance()->ChangeScene("SceneMenu", true);
			Time::GetInstance()->bStop = false;
		}
	}
}

void Stage1::WinUI()
{
	if (!m_bWinUI)
	{
		if (m_pPlayer->m_bWin)
		{
			Time::GetInstance()->bStop = true;
			m_ResultUI.LoadTextureFromFile("Resource/UI/win_UI.png");
			m_ResultUI.bEnable = true;

			m_pButton[2]->m_Sprite.m_Position.y = 167.6f;
			m_bWinUI = true;
		}
	}
	else if (m_bWinUI)
	{
		if (m_pButton[2]->m_bIn)
			m_pButton[2]->m_Sprite.LoadTextureFromFile("Resource/UI/x_button1.png");
		else
			m_pButton[2]->m_Sprite.LoadTextureFromFile("Resource/UI/x_button.png");

		if (m_pButton[2]->m_bClick)
		{
			SceneManager::GetInstance()->ChangeScene("SceneMenu", true);
			Time::GetInstance()->bStop = false;
		}
	}
}
