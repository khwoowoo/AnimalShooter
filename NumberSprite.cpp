#include "stdafx.h"


NumberSprite::NumberSprite()
{
}


NumberSprite::~NumberSprite()
{
}

void NumberSprite::Init()
{
	m_Sprite[0].LoadTextureFromFile("Resource/UI/Number1/0.png");
	m_Sprite[1].LoadTextureFromFile("Resource/UI/Number1/1.png");
	m_Sprite[2].LoadTextureFromFile("Resource/UI/Number1/2.png");
	m_Sprite[3].LoadTextureFromFile("Resource/UI/Number1/3.png");
	m_Sprite[4].LoadTextureFromFile("Resource/UI/Number1/4.png");
	m_Sprite[5].LoadTextureFromFile("Resource/UI/Number1/5.png");
	m_Sprite[6].LoadTextureFromFile("Resource/UI/Number1/6.png");
	m_Sprite[7].LoadTextureFromFile("Resource/UI/Number1/7.png");
	m_Sprite[8].LoadTextureFromFile("Resource/UI/Number1/8.png");
	m_Sprite[9].LoadTextureFromFile("Resource/UI/Number1/9.png");
}

void NumberSprite::SetOneNumber(float size)
{
	m_fOneSize = size;
}

void NumberSprite::SetPosition(float x, float y)
{
	m_Position = Vector3(x, y, 0.f);
}

void NumberSprite::SetColor(int r, int g, int b, int a)
{
	m_iR = r;
	m_iG = g;
	m_iB = b;
	m_iA = a;
}

void NumberSprite::SetNumber(string number)
{
	m_NumberText = number;
}

void NumberSprite::SetNumber(int number)
{
	char temp[256];
	itoa(number, temp, 10);
	m_NumberText = temp;
}

void NumberSprite::Render()
{
	//텍스트 개수 만큼 
	for (int i = 0; i < m_NumberText.size(); i++)
	{
		string temp = m_NumberText.substr(i, 1);
		int num = atoi(temp.c_str());
		m_Sprite[num].SetImageColor(m_iR, m_iG, m_iB, m_iA);

		int len = m_NumberText.size() - 1;

		m_Sprite[num].m_Position = D3DXVECTOR3(m_Position.x - ((len - i) * m_fOneSize), m_Position.y, 0);

		m_Sprite[num].OnRender();
	}
}
