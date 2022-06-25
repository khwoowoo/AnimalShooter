#include "stdafx.h"

PlayerLS::PlayerLS()
{
}


PlayerLS::~PlayerLS()
{
}

void PlayerLS::Init()
{
	Tag = "PlayerLS";
	m_Sprite.LoadTextureFromFile("Resource/Laser1.png");
}

void PlayerLS::Render()
{
	m_Sprite.OnRender();
}

void PlayerLS::Update(float deltatime)
{
	m_Sprite.m_Position.y -= fSpeed * deltatime;
	m_Sprite.m_Position.x = m_Player->m_Sprite.m_Position.x;

	if (m_Sprite.m_Position.y <= 0.f && !isDestory)
	{
		isDestory = true;
		SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
		cout << "player의 레이져 공격 삭제 완료" << endl;
	}
}

void PlayerLS::Destory()
{
}

bool PlayerLS::CollisionTo(IObject * obj)
{
	return false;
}

bool PlayerLS::CollisionFrom(IObject * obj)
{
	return false;
}
