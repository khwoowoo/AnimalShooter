#include "stdafx.h"

Button::Button()
{
}


Button::~Button()
{
}

void Button::Init()
{
}

void Button::Render()
{
	m_Sprite.OnRender();
}

void Button::Update(float deltatime)
{
	Vector3 vTemp = m_Sprite.m_Position - KeyManager::GetInstance()->vMouse;
	if (D3DXVec3Length(&vTemp) < m_fTouchLen)
	{
		if (KeyManager::GetInstance()->GetKeyState(VK_LBUTTON) == EKEY_DOWN)
			m_bClick = true;
		else
			m_bClick = false;

		if (m_bTouchBig == true)
		{
			m_Sprite.m_Scale = Vector2(1.2f, 1.2f);
			m_Sprite.m_ScalePivot = Vector2(m_Sprite.m_Texture.info.Width * 1.2f, m_Sprite.m_Texture.info.Height * 1.2f);
		}
		m_bIn = true;
	}
	else
	{
		m_bIn = false;
		m_bClick = false;
		if (m_bTouchBig == true)
		{
			m_Sprite.m_Scale = Vector2(1.f, 1.f);
			m_Sprite.m_ScalePivot = Vector2(m_Sprite.m_Texture.info.Width, m_Sprite.m_Texture.info.Height);
		}
	}
}

void Button::Destory()
{
}

bool Button::CollisionTo(IObject * obj)
{
	return false;
}

bool Button::CollisionFrom(IObject * obj)
{
	return false;
}

void Button::SetUp(LPCSTR filename, Vector3 Pos, float len, bool big)
{
	m_Sprite.LoadTextureFromFile(filename);
	m_Sprite.m_Position = Pos;
	m_fTouchLen = len;
	m_bTouchBig = big;
}
