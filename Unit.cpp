#include "stdafx.h"


Unit::Unit()
{
}


Unit::~Unit()
{
}

void Unit::Init()
{
	Tag = "Unit";
	m_Sprite.LoadTextureFromFile("Resource/Unit.png");
	m_Sprite.SetImageColor(rand() % 255, rand() % 255, rand() % 255, 255);
}

void Unit::Render()
{
	m_Sprite.OnRender();
}

void Unit::Update(float deltatime)
{
	m_Sprite.m_Position = m_pPlayer->m_Sprite.m_Position + AddPositiom;

	m_fToaltime += deltatime;

	if (m_fToaltime >= m_fAttTime)
	{
		m_fToaltime -= m_fAttTime;
		PlayerAtt * pAtt = new PlayerAtt;
		pAtt->Init();
		pAtt->m_Sprite.LoadTextureFromFile("Resource/att.png");
		pAtt->fPower = 5.f;
		pAtt->m_Sprite.m_Position = m_Sprite.m_Position + Vector3(0.f, -100.f, 0.f);
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(pAtt);
	}
}
