#include "stdafx.h"

LoadScene::LoadScene()
{
}


LoadScene::~LoadScene()
{
}

void LoadScene::Open()
{
	//초기화
	m_iTextureCount = 0;
	m_iTextureLDCount = 0;
	m_bIsLoading = false;
	m_fLoadingTime = 0;
	m_bFadeOut = false;
	m_pFadeOut = nullptr;
	//------------------------------------

	m_Background.LoadTextureFromFile("Resource/Loading/LoadingBackgound.png");
	Vector2Zero(m_Background.m_Posset);

	LoadTexture("Resource/Loading/Loading (1).png");
	LoadTexture("Resource/Loading/Loading (2).png");
	LoadTexture("Resource/Loading/Loading (3).png");
	LoadTexture("Resource/Loading/Loading (4).png");
	LoadTexture("Resource/Loading/Loading (5).png");
	LoadTexture("Resource/Loading/Loading (6).png");
	LoadTexture("Resource/Loading/Loading (7).png");
	LoadTexture("Resource/Loading/Loading (8).png");
	LoadTexture("Resource/Loading/Loading (9).png");
	LoadTexture("Resource/Loading/Loading (10).png");
	LoadTexture("Resource/Loading/Loading (11).png");
	LoadTexture("Resource/Loading/Loading (12).png");
	LoadTexture("Resource/Loading/LoadingBackgound.png");
	LoadTexture("Resource/Menu/eixtButton.png");
	LoadTexture("Resource/Menu/startButton.png");
	LoadTexture("Resource/Menu/menuScene.png");
	LoadTexture("Resource/airpalne.png");
	LoadTexture("Resource/att.png");
	LoadTexture("Resource/monsterBeta.png");
	LoadTexture("Resource/Damage.png");
	LoadTexture("Resource/att1.png");
	LoadTexture("Resource/att2.png");
	LoadTexture("Resource/Item_heart.png");
	LoadTexture("Resource/Item_power.png");
	LoadTexture("Resource/Item_Unit.png");
	LoadTexture("Resource/particle.png");
	LoadTexture("Resource/Unit.png");
	LoadTexture("Resource/black.png");
	LoadTexture("Resource/Laser.png");
	LoadTexture("Resource/Laser1.png");
	LoadTexture("Resource/monster1.png");
	LoadTexture("Resource/monster2.png");
	LoadTexture("Resource/monsterAlpha.png");
	LoadTexture("Resource/monsterGamma.png");
	LoadTexture("Resource/Stage1/Stage1.png");
	LoadTexture("Resource/UI/HealthBar.png");
	LoadTexture("Resource/UI/Number/0.png");
	LoadTexture("Resource/UI/Number/1.png");
	LoadTexture("Resource/UI/Number/2.png");
	LoadTexture("Resource/UI/Number/3.png");
	LoadTexture("Resource/UI/Number/4.png");
	LoadTexture("Resource/UI/Number/5.png");
	LoadTexture("Resource/UI/Number/6.png");
	LoadTexture("Resource/UI/Number/7.png");
	LoadTexture("Resource/UI/Number/8.png");
	LoadTexture("Resource/UI/Number/9.png");
	LoadTexture("Resource/UI/Number1/0.png");
	LoadTexture("Resource/UI/Number1/1.png");
	LoadTexture("Resource/UI/Number1/2.png");
	LoadTexture("Resource/UI/Number1/3.png");
	LoadTexture("Resource/UI/Number1/4.png");
	LoadTexture("Resource/UI/Number1/5.png");
	LoadTexture("Resource/UI/Number1/6.png");
	LoadTexture("Resource/UI/Number1/7.png");
	LoadTexture("Resource/UI/Number1/8.png");
	LoadTexture("Resource/UI/Number1/9.png");
	LoadTexture("Resource/UI/score.png");
	LoadTexture("Resource/UI/waepon_one.png");
	LoadTexture("Resource/UI/waepon_two.png");
	LoadTexture("Resource/UI/waepon_three.png");
	LoadTexture("Resource/UI/waepon_four.png");
	LoadTexture("Resource/UI/ui_middle.png");
	LoadTexture("Resource/UI/ui_last.png");
	LoadTexture("Resource/UI/lose_UI.png");
	LoadTexture("Resource/UI/win_UI.png");
	LoadTexture("Resource/UI/replay_button1.png");
	LoadTexture("Resource/UI/replay_button2.png");
	LoadTexture("Resource/UI/close_button1.png");
	LoadTexture("Resource/UI/close_button2.png");
	LoadTexture("Resource/UI/x_button.png");
	LoadTexture("Resource/UI/x_button1.png");

	m_LoadingImage.m_Position = Vector3(550.f, 640.f, 0.f);
	m_Animation.SetUp("Resource/Loading/Loading", 12, 0.05f, true);
	m_LoadingImage.LoadTextureFromFile(m_Animation.UpdateLD(0.f));
}

void LoadScene::Update(float deltatime)
{
	m_fLoadingTime += deltatime;

	//로딩할 시간이 되고 이미지 개수랑 로딩된 이미지 개수가 다른경우
	if (m_fLoadingTime >= 0.05f && m_iTextureCount != m_iTextureLDCount)
	{
		m_LoadTexture.LoadTextureFromFile(m_FileName[m_iTextureLDCount]);
		m_iTextureLDCount++;

		m_Animation.iCurFrame++;
		m_LoadingImage.LoadTextureFromFile(m_Animation.UpdateLD(deltatime));

		m_fLoadingTime -= 0.05f;
	}
	else if (m_iTextureCount == m_iTextureLDCount)
		m_bIsLoading = true;


	if (m_bIsLoading == true && m_bFadeOut == false)
	{
		m_bFadeOut = true;
		m_pFadeOut = new Effect;
		m_pFadeOut->Init("Resource/black.png", Vector3(0.f, 0.f, 0.f));
		Vector2Zero(m_pFadeOut->m_Sprite.m_Posset);
		m_pFadeOut->bFadeOut = true;
		m_pFadeOut->fFadeOutTime = -0.7f;
		m_pFadeOut->m_Sprite.SetImageColor(255, 255, 255, 0);
		SceneManager::GetInstance()->GetNowScene()->m_EffectManager.AddObject(m_pFadeOut);
	}

	if (m_bFadeOut == true && m_pFadeOut->m_Sprite.m_Color.a == 1.f)
	{
		SceneManager::GetInstance()->ChangeScene("SceneMenu", true);
	}
}

void LoadScene::Render()
{
	m_Background.OnRender();
	m_LoadingImage.OnRender();
}

void LoadScene::LastRender()
{
}

void LoadScene::Close()
{
}

void LoadScene::LoadTexture(LPCSTR filename)
{
	m_FileName[m_iTextureCount] = filename;
	m_iTextureCount++;
}
