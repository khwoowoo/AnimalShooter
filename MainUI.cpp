#include "stdafx.h"


MainUI::MainUI()
{
}


MainUI::~MainUI()
{
}

void MainUI::Init()
{
	m_ScoreSprite.LoadTextureFromFile("Resource/UI/score.png");
	m_ScoreSprite.m_Posset = Vector2(1.f, 1.f);
	m_ScoreSprite.m_Position = Vector3(1267.1f, 89.5f, 0.f);

	m_pNumberSprite = new NumberSprite;
	m_pNumberSprite->Init();
	m_pNumberSprite->SetOneNumber(50.f);
	//m_pNumberSprite->SetNumber(123456);
	m_pNumberSprite->SetColor(255, 255, 255, 255);
	m_pNumberSprite->SetPosition(1540.f, 65.f);

	m_SpriteTV.LoadTextureFromFile("Resource/tv.png");
	m_SpriteTV.m_Position = Vector3(WinSizeX - 190.f, WinSizeY - 125.f, 0.f);

}

void MainUI::Render()
{
	m_SpriteTV.OnRender();
	m_ScoreSprite.OnRender();
	m_pNumberSprite->Render();
}

void MainUI::Update(float deltatime)
{
}
