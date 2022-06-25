#include "stdafx.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Vector3 direction)
{
	Init();
	m_Direction = direction;
	m_Sprite.m_Rotate.z = Vec3Calc::Angle(Vector3(0.f, -1.f, 0.f), direction);
}


Bullet::~Bullet()
{
}

void Bullet::Init()
{
	m_Direction = Vector3(0.f, fSpeed, 0.f);
	m_Sprite.LoadTextureFromFile("Resource/att2.png");
	m_Sprite.SetImageColor(143, 5, 183, 255);
	m_Sprite.m_Scale = Vector2(0.7f, 0.7f);
	m_Sprite.m_ScalePivot = Vector2(m_Sprite.m_Texture.info.Width * 0.7f, m_Sprite.m_Texture.info.Height * 0.7f);

	if(isNewAtt)
		m_Sprite.SetImageColor(25, 25, 25, 255);
}

void Bullet::Render()
{
	m_Sprite.OnRender();
}

void Bullet::Update(float deltatime)
{
	m_Sprite.m_Position += m_Direction * deltatime;

	if (isNewAtt)
	{
		fNewAttTime += deltatime;
		cout << "fNewAttTime "<<fNewAttTime << endl;
		if (fNewAttTime >= 1.2f)
		{
			for (int i = 0; i < 8; ++i)
			{
				Bullet* bullet = new Bullet(Vec3Calc::Rotate(D3DXVECTOR3(0.0f, -500.0f, 0.0f), 100 + (45 * i)));
				bullet->Tag = "MonsterAtt";
				bullet->m_Sprite.m_Position = m_Sprite.m_Position;
				SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.AddObject(bullet);
			}
			isNewAtt = false;
		}


	}


	if (m_Sprite.m_Position.x >= WinSizeX ||
		m_Sprite.m_Position.x <= 0 ||
		m_Sprite.m_Position.y >= WinSizeY ||
		m_Sprite.m_Position.y <= 0)
	{
		if (!isDestory)
		{
			cout << "몬스터 공격 삭제" << endl;
			isDestory = true;
			SceneManager::GetInstance()->GetNowScene()->m_ObjectManager.RemoveObject(this);
		}
	}
}

void Bullet::Destory()
{
}

bool Bullet::CollisionTo(IObject * obj)
{
	return false;
}

bool Bullet::CollisionFrom(IObject * obj)
{
	return false;
}
