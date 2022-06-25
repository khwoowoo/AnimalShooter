#include "stdafx.h"


MoveBackground::MoveBackground()
{
}


MoveBackground::~MoveBackground()
{
}

void MoveBackground::SetUp(LPCSTR filename, float speed)
{
	Vector2Zero(m_Sprite.m_Posset);
	m_Sprite.LoadTextureFromFile(filename);
	m_fSpeed = speed;
	m_fHeight = m_Sprite.m_Texture.info.Height;

	m_vFirst = Vector3(0.f, -m_fHeight, 0.f);
	m_vSecond = Vector3(0.f, 0.f, 0.f);
}

void MoveBackground::Update(float deltatime)
{
	float fDeltaY = m_fSpeed * deltatime;
	m_vFirst.y += fDeltaY;
	m_vSecond.y += fDeltaY;

	if (m_vFirst.y >= m_fHeight)
	{
		m_vFirst.y = m_vSecond.y - m_fHeight;
	}

	if (m_vSecond.y >= m_fHeight)
	{
		m_vSecond.y = m_vFirst.y - m_fHeight;
	}
}

void MoveBackground::Render()
{
	m_Sprite.m_Position = m_vFirst;
	m_Sprite.OnRender();

	m_Sprite.m_Position = m_vSecond;
	m_Sprite.OnRender();
}
