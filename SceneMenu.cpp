#include "stdafx.h"

SceneMenu::SceneMenu()
{
}


SceneMenu::~SceneMenu()
{
}

void SceneMenu::Open()
{
	//초기화

	//------------------------------------

	m_Background.LoadTextureFromFile("Resource/Menu/menuScene.png");
	Vector2Zero(m_Background.m_Posset);

	// 사운드 객체 추가
	background1 = new SoundData;
	background1->fileType = "mpegvideo";
	//background1->fileType = "mpegvideo";
	background1->fileAddress = "Resource/background1.mp3";
	background1->isLoop = true;

	// 사운드 객체를 로드
	MCISound::GetInstance()->LoadWav(background1);


	SceneManager::GetInstance()->GetNowScene()->m_SoundManager.AddSound(background1);
	MCISound::GetInstance()->Play(background1);
	m_pButton[0] = new Button;
	m_pButton[0]->SetUp("Resource/Menu/startButton.png", Vector3(239.6f, 761.6f, 0.f), 100.f, true);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[0]);

	m_pButton[1] = new Button;
	m_pButton[1]->SetUp("Resource/Menu/eixtButton.png", Vector3(239.6f, 904.1f, 0.f), 100.f, true);
	SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(m_pButton[1]);

}

void SceneMenu::Update(float deltatime)
{
	if (m_pButton[0]->m_bClick == true)
	{
		SceneManager::GetInstance()->ChangeScene("Stage1", true);
	}
	else if (m_pButton[1]->m_bClick == true)
	{
		PostQuitMessage(0);
	}
}

void SceneMenu::Render()
{
	m_Background.OnRender();
}

void SceneMenu::LastRender()
{
}

void SceneMenu::Close()
{
}
